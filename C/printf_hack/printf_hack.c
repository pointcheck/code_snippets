#include <stdio.h>

int main(void) {
	char *a = "Hello";
	int n = 0;
	char x = 0;
	char y = 0;
	printf("n = %d\n", n);
	printf("%s%n\n", a, &n); // initial set n = sizeof("Hello")
	printf("n = %d\n", n);
	printf("%100d%n\n", 123, &n); // add 100 to n
	printf("n = %d\n", n);
	printf("%.33d%n\n", 123, &n); // set n = 33
	printf("n = %d\n", n);
	printf("%s%s%s%4$hhn\n", a, a, a, &x); // store lower byte of accumulator to arg4
	printf("x = %d\n", x); 
	printf("%1$255d%hhn\n", 123, &y); // dec accumulator by 1 
	printf("y = %d\n", y);
	return 0;
}
