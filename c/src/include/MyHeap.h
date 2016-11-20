#ifndef _C_MYHEAP_
#define _C_MYHEAP_
#include <stdlib.h>

/*
 * comparison type
 * MAX: maxheap
 * MIN: minheap
 * CUSTOM: custom comparison function for heap ordering
 */
typedef enum comparison_type {MAX, MIN, CUSTOM} comparison_type;

/*
 * Data object structure
 * void* data: pointer to object
 */
typedef struct node {
	void* data;
} node;

/*
 * heap data-structure
 * int max_length: max number of objects that can be handled
 * int length: current number of objects in data-structure
 * node **array: object container
 * comparison_type comparator: comparator selection flag
 * int (*comp_function)(node*, node*): custom comparator functions
 */
typedef struct heap {
	int max_length;
	int length;
	node **array;
	comparison_type comparator;
	int (*comp_function)(node*, node*);
} heap;

/*
 * Create new heap
 * int length: data-structure object limit
 * comarison_type ct: comparison method options MAX for max heap, MIN for min heap CUSTOM for custom function
 * int (*comp_function)(node*, node*): comparison function when ct is CUSTOM, otherwise NULL
 * Time Complexity: O(1)
 */
heap* createHeap(int length, comparison_type ct, int (*comp_function)(node*, node*));

/*
 * Free data-structure memory
 * heap* h: pointer to data-structure to be freed
 * Time Complexity: O(n)
 */
void destroyHeap(heap* h);

/*
 * Insert new object into data-structure 
 * heap* h: pointer to data-structure to insert into
 * void* data: pointer to new object to be inserted
 * Time Complexity: O(nlg(n))
 */
int insert(heap* h, void* data);

/*
 * Empty data-structure data 
 * heap* h: pointer to data-structure to be emptied 
 * Time Complexity: O(n)
 */
void flush(heap* h);

/*
 * Extract data-structure root object
 * heap* h: pointer to data-structure from which to extract root object
 * Time Complexity: O(1)
 */
void* extract(heap* h);


#endif
