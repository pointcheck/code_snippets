#include <stdio.h>

int hog(int a) {
	int sum = a;
	for(int i = 0; i < a; i++)
		sum +=i;

	return sum;
}

int main(void) {
	printf("Hello, world!\n");
	printf("hog = %d\n", hog(12345000));
	printf("hog = %d\n", hog(54321000));
	return 0;
}
