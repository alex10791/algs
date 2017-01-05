#include <stdio.h>
#include <stdlib.h>
#include "MyLinkedList.h"

#define N 30

int alphabetical_order(node *a, node *b);

int main(int argc, char*argv[]) {
	
	//int i;
	//char* x[35];

	int* x = (int*)malloc(sizeof(int));
	*x = 1;
	int* y = (int*)malloc(sizeof(int));
	*y = 2;
	int* z = (int*)malloc(sizeof(int));
	*z = 3;
	int* a = (int*)malloc(sizeof(int));
	*a = 4;
	int* b = (int*)malloc(sizeof(int));
	*b = 5;
	int* c = (int*)malloc(sizeof(int));
	*c = 6;
	
	linked_list* ll = createLinkedList();

	addToTail(ll, x);
	addToTail(ll, y);
	addToTail(ll, z);
	addToTail(ll, a);
	addToTail(ll, b);
	addToTail(ll, c);

	addToHead(ll, x);
	addToHead(ll, y);
	addToHead(ll, z);
	addToHead(ll, a);
	addToHead(ll, b);
	addToHead(ll, c);

	print(ll);
	printf("\n");

	removeFromHead(ll);
	removeFromTail(ll);

	print(ll);
	printf("\n");

	printf("isempty: %d\n", lined_list_isempty(ll));
	printf(" length: %d\n", linked_list_length(ll));

	printf("   head: %d\n", *(int*)getFromHead(ll));
	printf("   tail: %d\n", *(int*)getFromTail(ll));
	printf("index 2: %d\n", *(int*)getFromIndex(ll, 2));

	flush(ll);

	print(ll);
	printf("\n");

	return 0;
}





