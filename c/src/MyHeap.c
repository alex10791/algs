#include "MyHeap.h"
#include <stdio.h>

void heapify(heap* h);
int parentIndex(int index);
int leftChildIndex(int index);
int rightChildIndex(int index);
int int_max_comp(void* a, void* b);
int int_min_comp(void* a, void* b);



int parentIndex(int index) {
	return (index-1)/2;
}
int leftChildIndex(int index) {
	return (index+1)*2-1;
}
int rightChildIndex(int index) {
	return (index+1)*2;
}

int int_max_comp(void* a, void* b) {
	if (*(int*)a > *(int*)b)
		return 1;
	if (*(int*)b > *(int*)a)
		return 2;
	return 0;
}

int int_min_comp(void* a, void* b) {
	if (*(int*)a < *(int*)b) 
		return 1;
	if (*(int*)b < *(int*)a)
		return 2;
	return 0;
}



heap* createHeap(int length, comparison_type ct, int (*comp_function)(void*, void*)) {
	heap* h = (heap*)malloc(sizeof(heap));
	h->length = 0;
	h->max_length = length;
	if (ct == MAX)
		h->comp_function = &int_max_comp;
	else if (ct == MIN) 
		h->comp_function = &int_min_comp;
	else 
		h->comp_function = comp_function;
	h->array = (void *)malloc(sizeof(node*)*length);
	return h;
}

void destroyHeap(heap* h) {
	flush(h);
	free(h->array);
	free(h);
}

int insert(heap* h, void *data) {
	if (h->length == h->max_length) return -1;
	node* n = (node *)malloc(sizeof(node*));
	if (n == NULL) return -2;
	n->data = data;
	h->array[h->length] = n;
	h->length++;
	heapify(h);
	return 0;
}

void* extract(heap *h) {
	if (h->length == 0) return NULL;
	void* ext_node_data = h->array[0]->data;
	free(h->array[0]);
	h->array[0] = h->array[h->length-1];
	h->length--;
	heapify(h);
	return ext_node_data;
}

void flush(heap* h) {
	int i;
	for (i = 0; i < h->length; ++i) {
		free(h->array[i]);
	}
	h->length = 0;
}

void heapify(heap* h) {
	int i;
	int parent_idx, lchild_idx, rchild_idx;
	int lchild_exists, rchild_exists;
	node *parent, *lchild, *rchild;
	node *temp_node;
	int change = 1;

	while (change) {
		change = 0;
		for (i = h->length-1; i >= 1; i=i-2) {

			parent_idx = parentIndex(i);
			lchild_idx = leftChildIndex(parent_idx);
			rchild_idx = rightChildIndex(parent_idx);

			parent = h->array[parent_idx]->data;
			if (lchild_idx < h->length) {
				lchild_exists = 1;
				lchild = h->array[lchild_idx]->data;
			} else {
				lchild_exists = 0;
			}
			if (rchild_idx < h->length) {
				rchild_exists = 1;
				rchild = h->array[rchild_idx]->data;
			} else {
				rchild_exists = 0;
			}


			if ((lchild_exists) 
					&& h->comp_function(lchild, parent) == 1 
					&& (!rchild_exists || h->comp_function(lchild, rchild) == 1)) {
				temp_node = h->array[lchild_idx];
				h->array[lchild_idx] = h->array[parent_idx];
				h->array[parent_idx] = temp_node;
				change = 1;
			} else if ((rchild_exists) 
					&& h->comp_function(rchild, parent) == 1 
					&& (!lchild_exists || h->comp_function(lchild, rchild) == 2)) {
				temp_node = h->array[rchild_idx];
				h->array[rchild_idx] = h->array[parent_idx];
				h->array[parent_idx] = temp_node;
				change = 1;
			} else if ((lchild_exists) 
					&& h->comp_function(lchild, parent) == 1 
					&& rchild_exists
					&& h->comp_function(lchild, rchild) == 0) {
				temp_node = h->array[lchild_idx];
				h->array[lchild_idx] = h->array[parent_idx];
				h->array[parent_idx] = temp_node;
				change = 1;
			}
		} 

	}
}

