# HmmmSilicon
A reference implementation of the Harvey Mudd Miniature Machine (HMMM) which officially exists only as an emulator written in Python. HMMM was written as a simplified instruction set architecture for the CS5 curriculum. To my knowledge, though emulators have been written in other programming languages, this is the first attempt at a hardware implementation/description.

### Motivation
This implementation was written to parallel my group's final project for CS123 at Harvey Mudd, which is to write a partially-complete HMMM emulator in tutorial format. 

Strictly speaking, this HMMMSilicon project is not involved with the class. I wrote this code entirely by myself, none of it is getting turned in, and further, my group was unaware of its existence until it was nearly complete. However, the intent was to provide a reference implementation in hardware

The HMMM unit of CS5 is preceded by a cursory introduction to logic design. While the logic design unit is clearly meant to motivate HMMM, HMMM is framed as moving beyond logic/hardware, i.e. "Farewell Wires." 

An enterprising CS5'er will invariably dig into the emulator code in an attempt to correlate the content of both units. Presently, this is somewhat doomed. The profs behind HMMM are sensible, and wrote the emulator in concise and ideomatic Python using advanced features like introspection, not to be understood by CS5ers 6 weeks into their Python careers. The code is interspered with debugging code which is hard for new CS students to pick apart from the functional code. Most critically, because Python is very abstracted from hardware, the emulator (understandably) looks very little like a hardware description. 

If a CS5'er wants to to truly learn how a microprocessor implements a simple instruction set architecture, they will take E85, where they will implement a partial Risc-V processor over the course of a semester, necessarily learning SystemVerilog along the way. Our aim is to take a step in the direction of E85 to encourage students to actually take that class, and for those who do not, to at least bridge the gap between the two aforementioned CS5 units, which would provide a more concrete conceptual foundation going into Computer Systems (CS105).

Still, to CS5ers, Python, though undeniably horribly unsuited to the task, is the best "hardware description language" available. So that is how we procede to implement HMMM: in a Jupyter notebook.

I realized that if we attempted a CS5-interpretable emulator directly, we would just produce an all-around worse version of the existing emulator, which still looks nothing like hardware. If we were trying to teach students to write emulators, this would be fine, but as mentioned, our goal is to give intuituion to the hardware which might implement an already familiar ISA, not just to reiterate the ISA via an emulator written in a high-level programming language.

To be faithful to the hardware, we need an actual HMMM hardware description to emulate. Again, this did not previously exist, so I made it.


### Limitations

I had a choice to follow either the behavior of the emulator as the "HMMM documentation" which practically speaking is not a specification but a user manual for the emulator.

If I were principled, I would seriously weigh pros and cons of each idiosyncrasy of the emulator, but I thought it would be fun to design the hardware "from spec" so I used the documentation instead, looking at the pre-existing Python for no more than 10 seconds.

This entails many execution paths which are not only "undefined" but "undefined undefineds," to adopt a phrase from the worst person to ever emerge from my high school, Donald Rumsfeld. What happens when the PC runs of the end of the unified memory? By the documentation, it isn't clear. The python emulator sets the PC to a magic negative value which gets caught later as invalid, terminating the program. I didn't look at the python for more than 10 seconds before writing the whole hardware description, but if I had, I still wouldn't have done it this way, for obvious reasons. There are many similar python-isms which do not map well to the hardware. I haven't bothered to check, but I'm sure there are other edge cases in the emulator code that are caused more by the intricacies of Python itself than the designers' intent.

There are other weird things not in spec but which diverge between the emulator and my implementation. My implementation (at time of writing) has a +2 PC increment, to use the address of each instruction. The emulator has +1, for each whole instruction. HMMM proper halts when the PC exceeds the number of instructions written into memory. My implementation does not.

Also, I wrote most of this in attandance of a few NCAA basketball games, so I am sure my distraction has admitted a handful of bugs. If you see them, let me know!

The implementation is meant to be a guardrail for a python implementation readable by intro CS students, so the code is not very optimized in either synthesized hardware area or lines of code. For instance, my decoding logic is to directly decode the instruction name. Large scale hardware reuse was attempted only insofar as was evidently possible in the bitpatterns of the HMMM instructions.

Additionally, I haven't done anything like this before, so my implementation isn't great.


### How to run

1. Specify the program in program.txt in binary format.

2. Build:
```
verilator -cc --exe --trace --build --build-jobs 0 sim_main.cpp hmmm.sv
```

3. Run:
```
./obj_dir/VHmmm
```


TODO:
Variable naming is horrible.
Things are still a bit too removed from the hardware. Nominally this is because 
