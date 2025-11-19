# Collection of code snippets for everyday use

 - [./C/ErrorHandling](./C/ErrorHandling) - Handle multiple errors with errno

 - [./C/Labels_as_Values_Direct_Threaded](./C/Labels_as_Values_Direct_Threaded) - GCC Labels as Values

Allows implementing efficient interpretters or VMs. Each command (operation) should be
encoded with an integer value which is then used as goto label in main loop instead of
giant switch or if-then-else.

Reference: https://gcc.gnu.org/onlinedocs/gcc/Labels-as-Values.html

### Update

Code snipped was extended to support one operand per operation, its type depends on the op.

 - [./C/StackViolation](./C/StackViolation) - Access to values on stack referenced by dead pointer

FreeBSD: works both methods through dead pointer and through function call.

Linux: access through function call only works, access through dead pointer make it segfaults.


 - [./C/main_as_array](./C/main_as_array) - It's possible to define **main** symbol as an array and put machine code in it

 - [./C/BufferOverflow](./C/BufferOverflow) - Examples of buffer overflow bugs and how to catch them 

 - [./C/BranchlessProgramming](./C/BranchlessProgramming) - Branchless implementation of abs(), clamp() and partition()

Derived from: https://sanixdk.xyz/blogs/the-weird-concept-of-branchless-programming


 - [./C/Quine](./C/Quine) - Quine in C, a simple self-reproducable C program

 - [./C/goto_iterator](./C/goto_iterator) - Interate using goto

Derived from: https://xavierleroy.org/control-structures/book/main006.html


 - [./C/Plasma](./C/Plasma) - Simple shader in C++ on CPU. 

Derived from: https://gist.github.com/rexim/ef86bf70918034a5a57881456c0a0ccf


 - [./Verilog/FreqDIV](./Verilog/FreqDIV) - Frequency divider and simulation test bench

 - [./Shell/SIXEL](./Shell/SIXEL) - Show "HI" in terminal using SIXEL graphics mode

Details are here: https://en.wikipedia.org/wiki/Sixel


