#include <stdio.h>
#include <unistd.h>

void* malloc(long unsigned int size) {
	char str[512];
	int str_size = snprintf(str, 512, "MALLOC: %lu\r\n", size);
	write(1, str, str_size);
	return 0;
}
