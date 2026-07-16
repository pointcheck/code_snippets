#include <stdio.h>

int main(void) {
	char *a = "World";
	int n = 0;
	printf("n = %d\n", n);
	printf("Hello %s%n\n", a, &n);
	printf("n = %d\n", n);
	return 0;
}
