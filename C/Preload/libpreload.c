#include <stdio.h>
#include <unistd.h>
#include <dlfcn.h>

void *(*old_malloc)(size_t size) = NULL;

void* malloc(long unsigned int size) {
	char str[512];

	if(old_malloc == NULL) {
		old_malloc = dlsym(RTLD_NEXT, "malloc");
		int str_size = snprintf(str, 512, "MALLOC: obtained old_malloc = %p\r\n", old_malloc);
		write(1, str, str_size);
		if(old_malloc == NULL)
			return 0;
	}


	int str_size = snprintf(str, 512, "MALLOC: %lu\r\n", size);
	write(1, str, str_size);
	return old_malloc(size);
}
