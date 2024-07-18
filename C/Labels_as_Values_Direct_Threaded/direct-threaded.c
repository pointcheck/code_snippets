/*
 * Code snippet for GCC labels as values (direct-threaded code with operands)
 * Can be useful to implement VMs or interpretters. 
 *
 * More details on: https://en.wikipedia.org/wiki/Threaded_code
 *
 * Author: "Ruslan Zalata" <rz@fabmicro.ru>
 *
 */

#include <stdio.h>
#include <stdint.h>

// Example data used as operands 
int8_t data0 = 0x31;
int32_t data1 = 0x01234567;
int32_t data2 = 0x76543210;
int64_t data3 = 0xABCD000076543210;
char *data4 = (char*)"Hello, world";

int main() {

	// Operands of different types
	int8_t	arg8;
	int32_t	arg32;
	int64_t	arg64;
	char*	arg_c;

	// Example program to execute
	static void* program[] = { &&op1, &data1, // 32 bit arg 
			   &&op3, &data4, // C string arg 
			   &&op2, &data3, // 64 bit arg 
			   &&op0, &data0, // 8 bit arg
			   &&op1, &data2, // 32 bit arg
			   (void*)123, 0, // invalid operation
	};

	for(int i = 0; i < sizeof(program) / sizeof(*program); i++) {

		printf("Step %d, label: %p: ", i/2, program[i]);

		if(program[i] >= &&op0 && program[i] <= &&op3)
			goto *program[i];

		printf("Unsupported operation\n");
		i++; // skip one operand
		continue;

		op0:	// Works with 8 bit data
			arg8 = *(uint8_t*)(program[++i]);
			printf("Operation Zero: data = 0x%02x\n", arg8);
			continue;

		op1:	// Works with 32 bit data
			arg32 = *(int32_t*)program[++i];
			printf("Operation One: data = 0x%08x\n", arg32);
			continue;

		op2:	// Works with 64 bit data
			arg64 = *(int64_t*)program[++i];
			printf("Operation Two: data = 0x%016lx\n", arg64);
			continue;

		op3:	// Works with C strings
			arg_c = (char*)*(long*)program[++i];
			printf("Operation Three: data = %s\n", arg_c);
			continue;
	}

	return 0;
}
