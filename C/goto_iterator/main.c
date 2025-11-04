#include <stdio.h>

// State machine without IFs

void* next(void *pc) {
	if(pc == NULL) {
		printf("start\n");
		return &&n1;
	} else
		goto *pc;

	n1: {
		printf("n1\n");
		return &&n2;
	}

	n2: {
		printf("n2\n");
		return &&n3;
	}

	n3: {
		printf("n3\n");
		return &&n1;
	}
}


int main(void) {
	void *pc = NULL;

	for(int i = 0; i < 10; i++)
		pc = next(pc);

	return 0;
}
