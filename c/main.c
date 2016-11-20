#include <stdio.h>
#include <stdlib.h>
#include "MyHeap.h"

#define N 30

int alphabetical_order(node *a, node *b);

int main(int argc, char*argv[]) {
	
	int i;
	char* x[35];
	
	for (i = 0; i < argc; ++i) {
		printf("%s\n", argv[i]);
	}

	// create a new heap
	heap* h = createHeap(N, CUSTOM, alphabetical_order);
	printf("Initial Length:\t%d\n", h->length);
	printf("Maximum Length:\t%d\n", h->max_length);

	// create radom strings
	srand(100);
	for (i = 0; i < 35; ++i) {
		x[i] = (char *)malloc(sizeof(char) * 8);
		for (int k = 0; k < 7; ++k) {
			x[i][k] = 65 + (rand() % 10);
		}
		x[i][7] = '\0';
		if (insert(h, x[i]) < 0) {
			printf("filled up\n");
		}
	}

	// print random strings
	for (i = 0; i < N; ++i) {
		printf("%s\n", (char*)h->array[i]->data);
	}
	printf("-------\n");

	// extract random strings in alphabetical order 
	for (i = 0; i < N; ++i) {
		printf("%s\n", (char*)extract(h));
	}
	printf("\n");


	// free string memory
	for (i = 0; i < 35; ++i) {
		free(x[i]);
	}

	// free data structure memory
	destroyHeap(h);

	return 0;
}





int alphabetical_order(node *a, node *b) {
	int i = 0;
	while  ( ( (char*)a->data)[i] != '\n') {
		if ( ( (char*)b->data)[i] == '\n') return 2;
		if ( ( (char*)a->data)[i] < ((char*)b->data)[i]) return 1;
		if ( ( (char*)a->data)[i] > ((char*)b->data)[i]) return 2;
		++i;
	}
	return 1;
}


