#ifndef _C_MYHASHTABLE_
#define _C_MYHASHTABLE_
#include <stdlib.h>

// #include <stdint.h>
// #if UINTPTR_MAX == 0xffffffff
// /* 32-bit */
// #define INT_TYPE long int
// #elif UINTPTR_MAX == 0xffffffffffffffff
// /* 64-bit */
// #define INT_TYPE long long int
// #else
// /* wtf */
// #endif

typedef enum prehash_function_type {
	/*Build in int dereferenced prehash function*/	BUILD_IN_ID_PHF,
	/*Build in int casted prehash function*/		BUILD_IN_IC_PHF,
 	/*Custom prehash function*/						CUSTOM_PHF
} prehash_function_type;

typedef enum hash_function_type {
	/*Build in hash function*/	BUILD_IN_HF, 
	/*Custom hash function*/	CUSTOM_HF
} hash_function_type;

typedef enum key_comparator_type {
	/*Build in int dereferenced key comparator*/	BUILD_IN_ID_KC, 
	/*Build in int casted key comparator*/			BUILD_IN_IC_KC,
	/*Custom key comparator*/						CUSTOM_KC
} key_comparator_type;

typedef enum value_comparator_type {
	/*Build in int dereferenced value comparator*/	BUILD_IN_ID_VC, 
	/*Build in int casted value comparator*/		BUILD_IN_IC_VC,
	/*Custom value comparator*/						CUSTOM_VC
} value_comparator_type;

typedef struct item {
	void* key;
	void* value;
	struct item* next;
} item;

typedef struct hash_table {
	item **items;
	unsigned int size;
	long long int (*prehash_function)(void*);
	unsigned int (*hash_function)(long long int, int);
	int (*key_comparator)(void*, void*);
	int (*value_comparator)(void*, void*);
} hash_table;

/*
 * Create a new hashtable datastructure with a given array size
 * Set custom prehash function or use build in prehash function
 * Set custom hash function or use build in hash function
 * Set custom key comparator function or use build in key comparator function
 * Set custom value comparator function or use build in value comparator function
 * Returns hashtable pointer
 */
hash_table* create_hash_table(	unsigned int size, 
								prehash_function_type phft, 
								long long int (*custom_prehash_function)(void*), 
								hash_function_type hft, 
								unsigned int (*custom_hash_function)(long long int, int), 
								key_comparator_type kc, 
								int (*custom_key_comparator)(void*, void*), 
								value_comparator_type vc, 
								int (*custom_value_comparator)(void*, void*));

/*
 * Free entire hashtable datastructure
 * NOTE: ONLY MEMORY ALLOCATED BY THE DATASTRUCTURE
 * Set hashtable pointer
 */
void delete_hash_table(hash_table *ht);

/*
 * Search hashtable by key using key comparator function
 * Set hastable pointer
 * Set key pointer
 * Returns value pointer if found, NULL if not found
 */
void* hash_table_search(hash_table *ht, void *key);

/*
 * Insert into hashtable by key using key comparator function
 * Set hastable pointer
 * Set key pointer
 * Set key value pointer
 * Returns non-zero if successful, zero if failed
 */
int hash_table_insert(hash_table *ht, void *key, void *value);

/*
 * Delete from hashtable by key using key comparator function
 * Set hastable pointer
 * Set key pointer
 * Returns non-zero if successful, zero if failed
 */
int hash_table_delete(hash_table *ht, void *key);

/*
 * Build in hash function
 * Performs prehash % size as hash function
 * Set prehash value
 * Set hashtable array size
 * Returns an unsinged int hash value
 */
unsigned int build_in_hash_function(long long int prehash, int size);

/*
 * Build in prehash function
 * Casts void* to int* and returns dereferenced value as prehash
 * Set key pointer
 * Returns a long long int prehash value
 */
long long int build_in_int_deref_prehash_function(void* key);

/*
 * Build in key comparator function
 * Compares integer values from dereferenced integer pointers
 * Set key1 pointer
 * Set key2 pointer
 * Returns non-zero if equal, zero if un-equal
 */
int build_in_int_deref_key_comparator(void* key1, void* key2);

/*
 * Build in value comparator function
 * Compares integer values from dereferenced integer pointers
 * Set value1 pointer
 * Set value2 pointer
 * Returns non-zero if equal, zero if un-equal
 */
int build_in_int_deref_value_comparator(void* value1, void* value2);

/*
 * Build in prehash function
 * Casts void* to int and returns value as prehash
 * Set key pointer
 * Returns a long long int prehash value
 */
long long int build_in_int_cast_prehash_function(void* key);

/*
 * Build in key comparator function
 * Casts void* to int and compares integer values
 * Set key1 pointer
 * Set key2 pointer
 * Returns non-zero if equal, zero if un-equal
 */
int build_in_int_cast_key_comparator(void* key1, void* key2);

/*
 * Build in value comparator function
 * Casts void* to int and compares integer values
 * Set value1 pointer
 * Set value2 pointer
 * Returns non-zero if equal, zero if un-equal
 */
int build_in_int_cast_value_comparator(void* value1, void* value2);

/*
 * Run a callback for each element in function
 * Set hastable pointer
 * Set callback function
 * -- callback function gets key as void*
 * -- callback function gets value as void*
 */
void for_each_in_hash_table(hash_table *ht, void (*callback)(void* key, void* value));

#endif
