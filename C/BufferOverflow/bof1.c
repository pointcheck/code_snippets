#include <stdio.h>
#include <string.h>

void welcome(const char *name) {
	char buf[32];
	strcpy(buf, name);
	printf("Hello, %s\n", buf);
}

int main(int argc, char **argv) {
	const char *name = (argc > 1) ? argv[1] : "World!";
	welcome(name);
	return 0;
}


