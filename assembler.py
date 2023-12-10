import sys, string, re
have_docopt = True


#
# opcodes encodes the preferred opcode translations.  Each entry is a
# triple: match, mask, translation.  If the binary word matches
# "match" under the mask, the translated opcode is given by that
# entry.  Blanks are ignored in the match and mask fields.  The table
# is order-dependent; the first match is used.  Note that at present
# the masks are either 0x0 or 0xF in each hex digit, although the code
# doesn't enforce that restriction.
#
# This table is shared directly between the assembler and simulator.
# The assembler doesn't use all the fields.
#
opcodes = (
        ("0000 0000 0000 0000", "1111 1111 1111 1111", "halt"),
        ("0000 0000 0000 0001", "1111 0000 1111 1111", "read"),
        ("0000 0000 0000 0010", "1111 0000 1111 1111", "write"),
        ("0000 0000 0000 0011", "1111 0000 1111 1111", "jumpr"),
        ("0001 0000 0000 0000", "1111 0000 0000 0000", "setn"),
        ("0010 0000 0000 0000", "1111 0000 0000 0000", "loadn"),
        ("0011 0000 0000 0000", "1111 0000 0000 0000", "storen"),
        ("0100 0000 0000 0000", "1111 0000 0000 1111", "loadr"),
        ("0100 0000 0000 0001", "1111 0000 0000 1111", "storer"),
        ("0100 0000 0000 0010", "1111 0000 0000 1111", "popr"),
        ("0100 0000 0000 0011", "1111 0000 0000 1111", "pushr"),
        ("0101 0000 0000 0000", "1111 0000 0000 0000", "addn"),
        ("0110 0000 0000 0000", "1111 1111 1111 1111", "nop"),
        ("0110 0000 0000 0000", "1111 0000 0000 1111", "copy"),
        ("0110 0000 0000 0000", "1111 0000 0000 0000", "add"),
        ("0111 0000 0000 0000", "1111 0000 1111 0000", "neg"),
        ("0111 0000 0000 0000", "1111 0000 0000 0000", "sub"),
        ("1000 0000 0000 0000", "1111 0000 0000 0000", "mul"),
        ("1001 0000 0000 0000", "1111 0000 0000 0000", "div"),
        ("1010 0000 0000 0000", "1111 0000 0000 0000", "mod"),
        ("1011 0000 0000 0000", "1111 1111 0000 0000", "jumpn"),
        ("1011 0000 0000 0000", "1111 0000 0000 0000", "calln"),
        ("1100 0000 0000 0000", "1111 0000 0000 0000", "jeqzn"),
        ("1101 0000 0000 0000", "1111 0000 0000 0000", "jnezn"),
        ("1110 0000 0000 0000", "1111 0000 0000 0000", "jgtzn"),
        ("1111 0000 0000 0000", "1111 0000 0000 0000", "jltzn"),
        ("0000 0000 0000 0000", "0000 0000 0000 0000", "data"),
        )
#
# The assembler would prefer a dictionary for the opcodes; that's not
# possible in the simulator because ordering matters.  Convert the
# table above into a dictionary that translates opcodes into encodings.
#
opcodeDict = {}
for i in range(len(opcodes)):
    opcodeDict[opcodes[i][2]] = opcodes[i][0]

#
# Encodings of the registers into binary.
#
register_encodings = {"r0":"0000", "r1":"0001", "r2":"0010", "r3":"0011",
    "r4":"0100", "r5":"0101", "r6":"0110", "r7":"0111",
    "r8":"1000", "r9":"1001", "r10":"1010", "r11":"1011",
    "r12":"1100", "r13":"1101", "r14":"1110", "r15":"1111", 
    "R0":"0000", "R1":"0001", "R2":"0010", "R3":"0011",
    "R4":"0100", "R5":"0101", "R6":"0110", "R7":"0111",
    "R8":"1000", "R9":"1001", "R10":"1010", "R11":"1011",
    "R12":"1100", "R13":"1101", "R14":"1110", "R15":"1111"}

#
# arguments encodes the required arguments for each operation.  "r"
# means a register; "s" means a signed 8-bit number in decimal; "u"
# means an unsigned 8-bit number in decimal, and "n" means a signed or
# unsigned 16-bit number in hex (0x notation) or decimal.  Actually,
# all numbers are accepted in all bases.
#
# In addition, "z" means insert four bits of zeros without swallowing
# an argument.
#
arguments = {
        "halt":   "",
        "read":   "r",
        "write":  "r",
        "jumpr":  "r",
        "setn":   "rs",
        "loadn":  "ru",
        "storen": "ru",
        "loadr":  "rr",
        "storer": "rr",
        "popr":   "rr",
        "pushr":  "rr",
        "addn":   "rs",
        "add":    "rrr",
        "copy":   "rr",
        "nop":    "",
        "sub":    "rrr",
        "neg":    "rzr",
        "mul":    "rrr",
        "div":    "rrr",
        "mod":    "rrr",
        "jumpn":  "zu",
        "calln":  "ru",
        "jeqzn":  "ru",
        "jgtzn":  "ru",
        "jltzn":  "ru",
        "jnezn":  "ru",
        "data":   "n",
        }


# Maximum output line width
outputLineMax = 78

#
# insertBits performs a logical "OR" on A and B
#
def insertBits(a, b):
    """Perform logical OR on a and b, preserving blanks in a.  Both a and
       b must consist exclusively of blanks, 0s, and 1s."""
    if a == ''  or  b == '':
        return a
    elif a[0] == ' ':
        return ' ' + insertBits(a[1:], b)
    elif b[0] == ' ':
        return insertBits(a, b[1:])
    elif a[0] == '1'  or  b[0] == '1':
        return '1' + insertBits(a[1:], b[1:])
    else:
        return '0' + insertBits(a[1:], b[1:])

def numToTwosComplement(value, width):
    """Convert value to a twos-complement binary number of the given width."""
    if value < 0:
        return numToTwosComplement(2**width + value, width)
    fmt = '{:0' + str(width) + 'b}'
    return fmt.format(value)

def translate(flds):
    try:
        operation = flds[0]
        opval = opcodeDict[operation]
    except KeyError:
        print("\nOPERATION ERROR:")
        print("'{} IS NOT A VALID OPERATION.".format(flds[0]))
        return "***OPERATION ERROR HERE***"
    encoding = opval
    extraBits = '0000'
    argsRequired = arguments[flds[0]]
    parts  = re.split(r'[,\s]+', flds[1].strip())    # split args into parts
    argc = len(parts)
    if argc == 1  and  parts[0] == '':
        argc = 0
        parts = []
    numArgsRequired = 0
    for i in argsRequired:
        if i != 'z':
            numArgsRequired += 1
    if argc != numArgsRequired:
        print("\nARGUMENT ERROR:")
        print("WRONG NUMBER OF ARGUMENTS.")
        print("DETECTED {} ARGUMENTS, EXPECTED {} ARGUMENTS"
          .format(argc, numArgsRequired))
        print(flds[0], flds[1])
        return "***ARGUMENT ERROR HERE***"
    for p in parts:
        if p == '':
            print("\nARGUMENT ERROR:")
            print("EMPTY ARGUMENT.")
            return "***ARGUMENT ERROR HERE***"

        arg = re.match(r'([Rr][0-9]+|-?[0-9]+|-|0[xX][0-9a-fA-F]+)$', p)
        if arg is None:
            print("\nARGUMENT ERROR:")
            print("'{}' IS NEITHER A REGISTER NOR A NUMBER.".format(p))
            return "***ARGUMENT ERROR HERE***"
        code = argsRequired[0]
        argsRequired = argsRequired[1:]
        while code == 'z':
            extraBits += '0000'
            code = argsRequired[0]
            argsRequired = argsRequired[1:]
        if code == 'r':
            try:
                bits = register_encodings[p]
            except KeyError:
                print("\nREGISTER ERROR:")
                print("'{}' IS NOT A VALID REGISTER.".format(p))
                return "***REGISTER ERROR HERE***"
            extraBits += bits
        else:
            try:
                value = int(p)
            except ValueError:
                print("\nARGUMENT ERROR:")
                print("'{}' IS NOT A VALID NUMBER.".format(p))
                return "***ARGUMENT ERROR HERE***"
            if code == 's':
                ok = -128 <= value <= 127
                width = 8
            elif code == 'u':
                ok = 0 <= value <= 255
                width = 8
            elif code == 'n':
                ok = -32768 <= value <= 65535
                width = 16
                extraBits = ''          # No padding in this case
            else:
                print("\nINTERNAL ERROR:")
                print("HMMMASSEMBLER ENCOUNTERED AN UNEXPECTED SITUATION.")
                return "***INTERNAL ERROR HERE***"
            if not ok:
                print("\nARGUMENT ERROR:")
                print("'{}' IS OUT OF RANGE FOR THE ARGUMENT.".format(p))
                return "***ARGUMENT ERROR HERE***"
            extraBits += numToTwosComplement(value, width)

    return insertBits(encoding, extraBits)

def assemble(program):
    output = []
    lineNum = -1
    for line in program:
        lineNum += 1
        # nasty regular expression to parse line number, instruction,
        # and arguments
        if len(re.findall(r'^([0-9]+)[\s]+([a-z]+)[\s]*(([-r0-9xXa-fA-F]+[,\s]*)*)([\s]+(#.*)*)*$', line)) != 1:
            print("\nSYNTAX ERROR ON LINE {}:".format(lineNum))
            print(line)
            output.append([lineNum, "***SYNTAX ERROR HERE***", line])
            continue

        flds = re.sub(r'^([0-9]+)[\s]+([a-z]+)[\s]*(([-r0-9xXa-fA-F]+[,\s]*)*)([\s]+(#.*)*)*$', r'\1~\2~\3', line).split('~')

        try:
            userLine = int(flds[0])
        except ValueError:
            print("\nMISSING LINE NUMBER AT LINE {}:".format(lineNum))
            print("FOUND:", flds[0])
            output.append([lineNum, "***MISSING LINE NUMBER HERE***", line])
            continue

        instruction = translate(flds[1:])
        triplet = [lineNum, instruction, line]

        if instruction[0] != '*' and lineNum != userLine:
            print("\nBAD LINE NUMBER AT LINE {}:".format(lineNum))
            print("LINE NUMBER: {} EXPECTED {}".format(flds[0], lineNum))
            output.append([lineNum, "***BAD LINE NUMBER HERE***", line])
            continue

        output.append(triplet)
    return output


def readFile(filename):
    try:
        f = open(filename,"r")          # file with machine code
    except IOError:
        print("Cannot open file: ", filename)
        sys.exit(1)
    program = []
    while True:
        line = f.readline()
        if line == "":                  # End of file
            break
        line = line.strip()             # Strip white space from front and end
        if line != ""   and  line[0] != '#': # If it's not a comment...
            program.append(line)        # ... then it's part of the program
    f.close()
    return program

def convertStringToProgram(s):
    """Convert the string "s" to the internal representation of a program.
       This function is not used by Hmmm itself, but is available to programs
       that wish to import Hmmm and use it internally."""
    program = []
    linesOfString = s.split("\n")
    for line in linesOfString:
        if line == "":
            continue
        line = line.strip()             # Strip white space from front and end
        if line != ""   and  line[0] != '#': # If it's not a comment...
            program.append(line)        # ... then it's part of the program
    return program

def isMachineCode(program):
    """Returns True if the program appears to be machine code, False if it
       appears to be Hmmm source code."""
    return re.match(r'([01]{4} ){3}[01]{4}$', program[0]) is not None

def writeMachineCode(machineCode, filename):
    """Write the internal representation of machine code to a file."""
    f = open(filename, "w")
    for triplet in machineCode:
        f.write(triplet + "\n")
    f.close()

def programToMachineCode(program):
    """Convert the result of an assembled program into internal machien code."""
    return [triplet[1][:4] + triplet[1][5:9] + triplet[1][10:14] + triplet[1][15:19] for triplet in program]

def hmmmAssembler(program):
    """Assemble the given program and return it as a string.  If an assembly
       error occurs, returns None.  Error messages are printed directly to
       stdout (this is because the program listing also goes to stdout)."""
    machineCode = assemble(program)

    # check whether there are any errors
    failure = False
    for triplet in machineCode:
        if triplet[1][0] == '*':
            failure = 1
            break
    if failure:
        print("\n***** ASSEMBLY TERMINATED UNSUCCESSFULLY *****")
        print("              ASSEMBLY RESULTS:\n")
    else:
        print("\n" + "-"*22)
        print("| ASSEMBLY SUCCESSFUL |")
        print("-"*22 + "\n")
    try:
        nWidth = max([len(str(x[0])) for x in machineCode])
    except ValueError:
        print("                <EMPTY PROGRAM>\n")
        return None
    # Create a format for the output.
    fmt = "{:<" + str(nWidth) + "}: {:<31} {}"
    for triplet in machineCode:
        # Print each line with tabs expanded, and with the width limited
        # to outputLineMax.
        line = fmt.format(triplet[0], triplet[1], triplet[2].expandtabs())
        print(line[:outputLineMax])
    print("")
    if failure:
        print("***** ASSEMBLY FAILED, SEE ABOVE FOR ERRORS *****")
        return None
    else:
        return machineCode

def assembleProgram():
    # Read the file based on user input
    # The try statement ensures only an acceptable
    # filename is submitted

    readable = False
    while not readable:
      file = input("Input your program filename:")
      readable = True
      try:
        program = readFile(file)
      except:
        readable = False


    
    # assemble the program
    program = hmmmAssembler(program)

    # clean up the assembled program to be machine-readable
    program = programToMachineCode(program)

    # Write assembled program to file
    file = open("assembled.txt", "w")
    for triplet in program:
      file.write(triplet + "\n")
    file.close()