#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int errno;

int main(int argc, char *argv[]) {
	long a, b, c;

	if(argc < 4)
		return 255,
		printf("Usage: %s <long> <long> <long>\n", argv[0]); 

	a = strtol(argv[1], NULL, 0);
	b = strtol(argv[2], NULL, 0);
	c = strtol(argv[3], NULL, 0);

	if(errno)
		return errno,
		printf("Error: %s\n", strerror(errno)); 

	printf("Result: %ld\n", a + b + c);

	return 0;
}
