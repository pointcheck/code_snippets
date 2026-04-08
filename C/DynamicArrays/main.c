#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char* item;
	int capacity;
	int size;
} dynar;


int dynar_push(dynar **da, char *item) {
	if(!da)
		return -1;

	if(*da == NULL) {
		*da = malloc(sizeof(**da) * 10);
		(*da)->capacity = 10;
		(*da)->size = 0;
	}

	if((*da)->size == (*da)->capacity) {
		int new_capacity = (*da)->capacity * 3 / 2;
		*da = realloc(*da, sizeof(**da) * new_capacity);
		(*da)->capacity = new_capacity; 
	}

	(*da)[(*da)->size].item = item;
	(*da)->size++;

	return 0;
}


int dynar_pop(dynar **da, char **last_item) {
	if(!da)
		return -1;

	if((*da)->size <= 0)
		return -2;
	
	*last_item = (*da)[(*da)->size-1].item;
	(*da)->size--;

	if((*da)->size <= (*da)->capacity * 2 / 3) {
		int new_capacity = (*da)->capacity * 2 / 3;
		*da = realloc(*da, sizeof(**da) * new_capacity);
		(*da)->capacity = new_capacity; 
	}

	return 0;
}


int main(void) {
	dynar *da = NULL;

	dynar_push(&da, "test1"); 
	dynar_push(&da, "test2"); 
	dynar_push(&da, "test3"); 
	dynar_push(&da, "test4"); 
	dynar_push(&da, "test4"); 
	dynar_push(&da, "test4"); 
	dynar_push(&da, "test4"); 
	dynar_push(&da, "test4"); 
	dynar_push(&da, "test4"); 
	dynar_push(&da, "test4"); 
	dynar_push(&da, "test7"); 
	dynar_push(&da, "test8"); 
	dynar_push(&da, "test9"); 

	printf("da[3] = %s\n", da[3].item);
	printf("da[0] = %s\n", da[0].item);
	printf("da[1] = %s\n", da[1].item);

	printf("da.size = %d, da.capacity = %d\n", da->size, da->capacity);

	char *item;

	dynar_pop(&da, &item); 
	printf("da[X-1] = %s\n", item);

	dynar_pop(&da, &item); 
	printf("da[X-2] = %s\n", item);

	dynar_pop(&da, &item); 
	printf("da[X-3] = %s\n", item);

	printf("da.size = %d, da.capacity = %d\n", da->size, da->capacity);

	dynar_pop(&da, &item); 
	printf("da[X-3] = %s\n", item);

	dynar_pop(&da, &item); 
	printf("da[X-4] = %s\n", item);

	dynar_pop(&da, &item); 
	printf("da[X-5] = %s\n", item);

	dynar_pop(&da, &item); 
	printf("da[X-6] = %s\n", item);

	dynar_pop(&da, &item); 
	printf("da[X-7] = %s\n", item);

	dynar_pop(&da, &item); 
	printf("da[X-8] = %s\n", item);

	dynar_pop(&da, &item); 
	printf("da[X-9] = %s\n", item);

	dynar_pop(&da, &item); 
	printf("da[X-10] = %s\n", item);

	dynar_pop(&da, &item); 
	printf("da[X-11] = %s\n", item);

	dynar_pop(&da, &item); 
	printf("da[X-12] = %s\n", item);

	dynar_pop(&da, &item); 
	printf("da[X-13] = %s\n", item);

	dynar_pop(&da, &item); 
	printf("da[X-14] = %s\n", item);

	printf("da.size = %d, da.capacity = %d\n", da->size, da->capacity);

	free(da);

	return 0;
}

