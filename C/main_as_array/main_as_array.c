//#include <stdlib.h>
//int main(void) { asm("mov $1, %eax"); asm("int $0x80");}
//__attribute__((section(".text"))) char main[] = { 0xb8, 0x01, 0x00, 0x00, 0x00, 0xcd, 0x80 };

__attribute__((section(".text"))) char main[] = { 0xc3 }; // retq
	  
