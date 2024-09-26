# HmmmSilicon
## Overview
The Harvey Mudd Miniature Machine ([HMMM](https://www.cs.hmc.edu/~cs5grad/cs5/hmmm/documentation/documentation.html)) is a toy ISA which is used for CS5 (i.e. CS 101...  get it?) at Harvey Mudd College. HMMM exists officially only in the form of a Python emulator which looks absolutely nothing like resembling a real microprocessor, and a cheat sheet for using said emulator. This project was created for CS123--effectively a management class--in hopes to raise the technical bar for the types of projects people are willing to attempt in the future despite that this is obviously not the point of the class. CS123 requires that students use Python to create a tutorial, so we created a hardware-accurate HMMM emulator in a subset of Python simple enough to the point that sufficiently curious CS5'ers (which I trust they all are!) who desire to know more about what's going on under the HMMM hood can take a look for themselves. You may be saying to yourself, "Hardware-accurate? But there is no RTL implementation for HMMM!" Well, there *wasn't* one (to my knowledge), so we made one. Okay, I'll be honest with you... this whole project is just an excuse to implement HMMM in Verilog. I really really wanted to implement HMMM in Verilog.

### How to run

1. Specify the program in program.txt in HMMM machine code.

2. Build:
```
verilator -cc --exe --trace --build --build-jobs 0 sim_main.cpp hmmm.sv
```

3. Run:
```
./obj_dir/VHmmm
```
## Statement of Motivation (i.e. What we told our CS123 Prof to let us do this.)
The HMMM unit of CS5 is preceded by a cursory introduction to logic design. While the logic design unit is clearly meant to motivate HMMM, HMMM is framed as moving beyond logic/hardware, i.e. "Farewell Wires." 

An enterprising CS5'er will invariably dig into the emulator code in an attempt to correlate the content of both units. Presently, this is somewhat doomed. The Profs behind HMMM are sensible, and wrote the emulator in concise and ideomatic Python using advanced features like introspection, not to be understood by CS5ers 6 weeks into their Python careers. The code is interspered with debugging code which is hard for new CS students to pick apart from the functional code. Most critically, because Python is very abstracted from hardware, the emulator (understandably) looks very little like a hardware description. 

If a CS5'er wants to to truly learn how a microprocessor implements a simple instruction set architecture, they will take E85, where they will implement a partial Risc-V processor over the course of a semester, necessarily learning SystemVerilog along the way. Our aim is to take a step in the direction of E85 to encourage students to actually take that class, and for those who do not, to at least bridge the gap between the two aforementioned CS5 units, which would provide a more concrete conceptual foundation going into Computer Systems (CS105).

Still, to CS5ers, Python, though undeniably horribly unsuited to the task, is the best "hardware description language" available. So that is how we procede to implement HMMM: in a Jupyter notebook.

I realized that if we attempted a CS5-interpretable emulator directly, we would just produce an all-around worse version of the existing emulator, which still looks nothing like hardware. If we were trying to teach students to write emulators, this would be fine, but as mentioned, our goal is to give intuituion to the hardware which might implement an already familiar ISA, not just to reiterate the ISA via an emulator written in a high-level programming language.

To be faithful to the hardware, we need an actual HMMM hardware description to emulate. Again, this did not previously exist, so I made it.

## Limitations
I wrote the hardware implementation while in attendance of two very noisy NCAA basketball games, so some errors may have slipped in. If you find one, submit a PR or let me know!
