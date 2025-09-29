/*
	Derived from: https://sanixdk.xyz/blogs/the-weird-concept-of-branchless-programming

*/


#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int abs_branchless(int x) {
	int mask = x >> 31;
	return (x + mask) ^ mask;
}

int abs_naive(int x) {
	return (x < 0) ? -x : x;
}

int clamp_naive(int x, int min, int max) {
	if (x < min) return min;
	if (x > max) return max;
	return x;
}

int clamp_branchless(int x, int min, int max) {
	int r1 = x - ((x - min) & ((x - min) >> 31));
	return r1 - ((r1 - max) & ((r1 - max) >> 31));
}

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition_naive(int* arr, int low, int high) {
	int pivot = arr[high];
	int i = low;
	for (int j = low; j < high; j++) {
		if (arr[j] < pivot) {
			swap(&arr[i], &arr[j]);
			i++;
		}
	}
	swap(&arr[i], &arr[high]);
	return i;
}

int partition_branchless(int* arr, int low, int high) {
	int pivot = arr[high];
	int i = low;
	for (int j = low; j < high; j++) {
		swap(&arr[i], &arr[j]);
		//i += arr[i] < pivot;
		i += ((arr[i] - pivot) >> 31) & 1;
	}
	swap(&arr[i], &arr[high]);
	return i;
}


#define	CYCLES	100000000U

volatile static int x1;
volatile static int x;

int main(int argc, char *argv[]) {

	struct timeval t1, t2;
	
	gettimeofday(&t1, NULL);

	for(int i = 0; i < CYCLES; i++) {
		x = rand() - (RAND_MAX / 2);
		x1 = abs(x);
	}

	gettimeofday(&t2, NULL);

	printf("abs(%d) = %d, time: %ld uS, cycles: %d\n", x, x1,
		(t2.tv_sec - t1.tv_sec) * 1000000U + t2.tv_usec - t1.tv_usec, CYCLES);



	gettimeofday(&t1, NULL);

	for(int i = 0; i < CYCLES; i++) {
		x = rand() - (RAND_MAX / 2);
		x1 = abs_branchless(x);
	}

	gettimeofday(&t2, NULL);

	printf("abs_branchless(%d) = %d, time: %ld uS, cycles: %d\n", x, x1,
		(t2.tv_sec - t1.tv_sec) * 1000000U + t2.tv_usec - t1.tv_usec, CYCLES);

	

	gettimeofday(&t1, NULL);

	for(int i = 0; i < CYCLES; i++) {
		x = rand() - (RAND_MAX / 2);
		x1 = abs_naive(x);
	}

	gettimeofday(&t2, NULL);

	printf("abs_naive(%d) = %d, time: %ld uS, cycles: %d\n", x, x1,
		(t2.tv_sec - t1.tv_sec) * 1000000U + t2.tv_usec - t1.tv_usec, CYCLES);

}
