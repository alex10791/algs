#include <stdio.h>
#include <stdlib.h>
#include "MyHeap.h"

#define N 		30		// size of datastructure
#define M 		35		// number of of objects
#define STR_LEN 30		// generated string length


int alphabetical_order(void *a, void *b);

int main(int argc, char*argv[]) {
	
	int i;
	char* x[M];
	

	// create a new heap
	heap* h = createHeap(N, CUSTOM, alphabetical_order);
	printf("Initial Length:\t%d\n", h->length);
	printf("Maximum Length:\t%d\n", h->max_length);

	// create radom strings
	srand(100);
	for (i = 0; i < M; ++i) {
		x[i] = (char *)malloc(sizeof(char) * STR_LEN);
		for (int k = 0; k < STR_LEN-1; ++k) {
			x[i][k] = 65 + (rand() % 26);
		}
		x[i][STR_LEN-1] = '\0';
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
	for (i = 0; i < M; ++i) {
		free(x[i]);
	}

	// free data structure memory
	destroyHeap(h);

	return 0;
}





int alphabetical_order(void *a, void *b) {
	int i = 0;
	while  ( ( (char*)a)[i] != '\n') {
		if ( ( (char*)b)[i] == '\n') return 2;
		if ( ( (char*)a)[i] < ((char*)b)[i]) return 1;
		if ( ( (char*)a)[i] > ((char*)b)[i]) return 2;
		++i;
	}
	return 1;
}


