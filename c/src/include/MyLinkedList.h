#ifndef _C_MYLINKEDLIST_
#define _C_MYLINKEDLIST_
#include <stdlib.h>

typedef enum equality_check {EQUAL, CUSTOM} equality_check;

typedef struct node {
	void* data;
	struct node* next;
	struct node* prev;
} node;

typedef struct linked_list {
	node* head;
	node* tail;
	unsigned int length;
} linked_list;

linked_list* createLinkedList();
void print(linked_list* ll);

int addToHead(linked_list* ll, void* data);
int addToTail(linked_list* ll, void* data);

int removeFromHead(linked_list* ll);
int removeFromTail(linked_list* ll);

int lined_list_isempty(linked_list* ll);
int linked_list_length(linked_list* ll);

void* getFromHead(linked_list* ll);
void* getFromTail(linked_list* ll);
void* getFromIndex(linked_list* ll, unsigned int idx);

void flush(linked_list* ll);

#endif
