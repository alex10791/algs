#include <stdio.h>
#include <stdlib.h>
#include "MyLinkedList.h"
#include "MyHashTable.h"

#include <time.h>

#define N 10000
#define M 40

long long int gCounter;
long long int gKeyAccum;
long long int gValAccum;

int alphabetical_order(node *a, node *b);

void inc_gCounter(void* key, void* value) {
	gCounter++;
	gKeyAccum += (long long int)key;
	gValAccum += (long long int)value;
}

unsigned int hash(long long int x, int size) {
	return x & 0xF;
}

int main(int argc, char*argv[]) {
	gCounter = 0;
	int i;


	void* x2 = (void*)123;
	void* y2 = 0;


	hash_table *ht2 = create_hash_table(	0x10, 	
										BUILD_IN_IC_PHF, NULL, 
										CUSTOM_HF,  	 hash, 
										BUILD_IN_IC_KC,  NULL, 
										BUILD_IN_IC_VC,  NULL);


	srand(time(NULL));

	int arr[M];
	for (i = 0; i < M; ++i) arr[i] = 0;

	for (i = 0; i < 20; i++) {
		int r0 = rand() % M;
		arr[r0]++;
		//int r1 = rand();
		x2 = (void*)r0;
		//y2 = (void*)r1;
		y2 = hash_table_search(ht2, (void*)x2);
		y2 = (void*)((long long int)y2 + 1);
		hash_table_insert(ht2, (void*)x2, (void*)y2);
	}
	printf("\n");

	for (i = 0; i < M; ++i) 
		printf("%p\t%p\n", (void*)i,(void*)arr[i]);

	print_ht(ht2, INT_CAST_KP, "%p:", INT_CAST_VP, "%p->", "#\n");

	return 0;


	hash_table *ht = create_hash_table(	0x100000, 	
										BUILD_IN_IC_PHF, NULL, 
										BUILD_IN_HF,  	 NULL, 
										BUILD_IN_IC_KC,  NULL, 
										BUILD_IN_IC_VC,  NULL);


	for (i = 0; i < N; i++) {
		y2 = hash_table_search(ht, (void*)x2);
		y2 = (void*)((long long int)y2 + 1);
		hash_table_insert(ht, (void*)x2, (void*)y2);
	}

	y2 = hash_table_search(ht, (void*)x2);
	printf("ht[%lld] = %lld\n", (long long int)x2, (long long int)y2);

	return 0;

	for (i = 0; i < N; i++) {
		long long int k = i;
		long long int v = i;
		hash_table_insert(ht, (void*)k, (void*)v);

		long long int v2;
		long long int k_mod = k;// % 16;
		v2 = (long long int)hash_table_search(ht,  (void*)k_mod);

		//printf("HT\tk:%d\tv:%lld\n", k_mod, (long long int)v2);

	}

	for_each_in_hash_table(ht, inc_gCounter);

	printf("gCounter\t%lld\n",  gCounter);
	printf("gKeyAccum\t%lld\n", gKeyAccum);
	printf("gValAccum\t%lld\n", gValAccum);

	delete_hash_table(ht);

	return 0;

/*
	hash_table *ht = create_hash_table(	1000, 	
										BUILD_IN_ID_PHF, NULL, 
										BUILD_IN_HF,  NULL, 
										BUILD_IN_ID_KC,  NULL, 
										BUILD_IN_ID_VC,  NULL);
*/

	int* k_arr[10000];
	int* v_arr[10000];

	for (i = 0; i < 10000; i++) {

		//printf("i: %d\n", i);
		
		k_arr[i] = (int *)malloc(1 * sizeof(int));
		v_arr[i] = (int *)malloc(1 * sizeof(int));

		int *k = k_arr[i];
		int *v = v_arr[i];

		*k = i;
		*v = i;

		int *v2;


		hash_table_insert(ht, k, v);
		
		int k_mod = (*k) % 16;
		v2 = (int *)hash_table_search(ht,  &k_mod);
/*
		if (v2 == NULL) 
			printf("HT\tk:%d\tv:NULL\n", k_mod);
		else
			printf("HT\tk:%d\tv:%d\n", k_mod, *(int*)v2);
*/
	}

	delete_hash_table(ht);

	for (i = 0; i < 10000; ++i) {
		free(k_arr[i]);
		free(v_arr[i]);
	}

	return 0;

	for (i = 1010; i < 1020; ++i) {
		int *k = (int *)malloc(1 * sizeof(int));

		*k = i;

		hash_table_delete(ht, k);
	}


	return 0;


	// LINKED LIST

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





