#include "MyLinkedList.h"
#include <stdio.h>

linked_list* createLinkedList() {
	linked_list* ll = (linked_list*)malloc(sizeof(linked_list));
	if (ll == NULL) return NULL;
	ll->head = NULL;
	ll->tail = NULL;
	ll->length = 0;
	return ll;
}

int addToHead(linked_list* ll, void* data) {
	node* n = (node*)malloc(sizeof(node));
	if (n == NULL) return -1;
	n->data = data;
	n->next = NULL;
	n->prev = NULL;
	if (ll->head == NULL) {
		ll->head = n;
		ll->tail = n;
	} else {
		ll->head->prev = n;
		n->next = ll->head;
		ll->head = n;
	}
	ll->length++;
	return 0;
}

int addToTail(linked_list* ll, void* data) {
	node* n = (node*)malloc(sizeof(node));
	if (n == NULL) return -1;
	n->data = data;
	n->next = NULL;
	n->prev = NULL;
	if (ll->head == NULL) {
		ll->head = n;
		ll->tail = n;
	} else {
		ll->tail->next = n;
		n->prev = ll->tail;
		ll->tail = n;
	}
	ll->length++;
	return 0;
}

int removeFromHead(linked_list* ll){
	if (ll->head == NULL) return -1;
	node* n = ll->head;
	ll->head = ll->head->next;
	ll->head->prev = NULL;		// this is an null dereference on the last item
	free(n);
	ll->length--;
	return 0;
}

int removeFromTail(linked_list* ll){
	if (ll->tail == NULL) return -1;
	node* n = ll->tail;
	ll->tail = ll->tail->prev;
	ll->tail->next = NULL;		// this is an null dereference on the last item
	free(n);
	ll->length--;
	return 0;
}

int lined_list_isempty(linked_list* ll) {
	return ll->length==0;
}

int linked_list_length(linked_list* ll) {
	return ll->length;
}

void* getFromHead(linked_list* ll) {
	if (ll->head == NULL) return NULL;
	return (void*)ll->head->data;
}

void* getFromTail(linked_list* ll) {
	if (ll->tail == NULL) return NULL;
	return (void*)ll->tail->data;
}

void* getFromIndex(linked_list* ll, unsigned int idx) {
	int i;
	node* n = ll->head;
	if (idx >= ll->length) return NULL;
	for (i = 0; i < idx; ++i) {
		n = n->next;
	}
	return (void*)n->data;
}

void flush(linked_list* ll) {
	while(removeFromHead(ll)==0);
}


void print(linked_list* ll) {
	node* n = ll->head;
	while(n != NULL) {
		printf("%d ", *(int*)n->data);
		n = n->next;
	}
}

