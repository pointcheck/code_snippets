# Collection of code snippets for everyday use

## ./C/ErrorHandling - Handle multiple errors with errno

## ./C/Labels_as_Values_Direct_Threaded - GCC Labels as Values

Allows implementing efficient interpretters or VMs. Each command (operation) should be
encoded with an integer value which is then used as goto label in main loop instead of
giant switch or if-then-else.

Reference: https://gcc.gnu.org/onlinedocs/gcc/Labels-as-Values.html

### Update

Code snipped was extended to support one operand per operation, its type depends on the op.

## ./C/StackViolation - Access to values on stack referenced by dead pointer

FreeBSD: works both methods through dead pointer and through function call.

Linux: access through function call only works, access through dead pointer segfaults.

## ./C/main_as_array - It's possible to define **main** symbol as an array and put machine code in it

## /C/BufferOverflow - Examples of buffer overflow bugs and how to catch them 

## ./Verilog/FreqDIV - Frequency divider and simulation test bench

## ./Shell/SIXEL - Show "HI" in terminal using SIXEL graphics mode

Details are here: https://en.wikipedia.org/wiki/Sixel


