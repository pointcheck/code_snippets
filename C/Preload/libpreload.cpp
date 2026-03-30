#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <dlfcn.h>

extern "C" {

void *(*old_malloc)(size_t size) = NULL;

void* malloc(size_t size) {
	char str[512];

	if(old_malloc == NULL) {
		old_malloc = (void *(*)(size_t))dlsym(RTLD_NEXT, "malloc");
		int str_size = snprintf(str, 512, "MALLOC: obtained old_malloc = %p\r\n", old_malloc);
		write(1, str, str_size);
		if(old_malloc == NULL)
			return 0;
	}

	int str_size = snprintf(str, 512, "MALLOC: %lu\r\n", size);
	write(1, str, str_size);
	return old_malloc(size);
}

}


class Test {
	public:
		Test() {
			std::cout << "Class Test has been constructed" << std::endl;
		}
}; 

Test t;

