/*
 * Code snippet for Stack Violation (access to variable on stack)
 *
 * FreeBSD: works both methods through dead pointer and through function call.
 *
 * Linux: access through function call only works, access through dead pointer segfaults.
 *
 * Author: "Ruslan Zalata" <rz@fabmicro.ru>
 *
 */

#include <stdio.h>

int C, D;

void* foo(int x, int y) {
	int res = x + y;
	printf("foo: &res = %p, res = %d\n", &res, res);
	return (void*)&res;
}

int bar(int x, int y) {
	int res;
	printf("bar: &res = %p, res = %d\n", &res, res);
	return res;
}

int main() {
	int A = 1;

	printf("&A = %p, A = %d\n", &A, A);

	void* B = foo(0, 42);

	// Violation 1
	C = bar(0,0);

	// Violation 2 
	D = *(int*)B; 

	printf("violation 1: C = %d\n", C);
	printf("violation 2: D = %d\n", D);

	return 0;
}
