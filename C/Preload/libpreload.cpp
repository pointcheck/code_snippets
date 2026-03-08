#include <stdio.h>
#include <unistd.h>
#include <iostream>

extern "C" {

void* malloc(long unsigned int size) {
	char str[512];
	int str_size = snprintf(str, 512, "MALLOC: %lu\r\n", size);
	write(1, str, str_size);
	return 0;
}

}


class Test {
	public:
		Test() {
			std::cout << "Class Test has been constructed" << std::endl;
		}
}; 

Test t;

