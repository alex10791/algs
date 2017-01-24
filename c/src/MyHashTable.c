
#include "MyHashTable.h"

hash_table* create_hash_table(	unsigned int size, 
								prehash_function_type phft, 
								long long int (*custom_prehash_function)(void*), 
								hash_function_type hft, 
								unsigned int (*custom_hash_function)(long long int, int), 
								key_comparator_type kc, 
								int (*custom_key_comparator)(void*, void*), 
								value_comparator_type vc, 
								int (*custom_value_comparator)(void*, void*)) {

	// allocate space for hastable structure
	hash_table *ht = (hash_table*)malloc(sizeof(hash_table));
	if (ht == NULL) return NULL;

	// check if custom prehash function given
	if (phft == CUSTOM_PHF) {
		if (custom_prehash_function == NULL) return NULL;
		ht->prehash_function = custom_prehash_function;
	} else if (phft == BUILD_IN_ID_PHF){
		ht->prehash_function = build_in_int_deref_prehash_function;
	} else {
		ht->prehash_function = build_in_int_cast_prehash_function;
	}

	// check if custom hash function given
	if (hft == CUSTOM_HF) {
		if (custom_hash_function == NULL) return NULL;
		ht->hash_function = custom_hash_function;
	} else {
		ht->hash_function = build_in_hash_function;
	}

	// check if custom key comparator given
	if (kc == CUSTOM_KC) {
		if (custom_prehash_function == NULL) return NULL;
		ht->key_comparator = custom_key_comparator;
	} else if (kc == BUILD_IN_ID_KC) {
		ht->key_comparator = build_in_int_deref_key_comparator;
	} else {
		ht->key_comparator = build_in_int_cast_key_comparator;
	}

	// check if custom value comparator given
	if (vc == CUSTOM_VC) {
		if (custom_prehash_function == NULL) return NULL;
		ht->value_comparator = custom_value_comparator;
	} else if (vc == BUILD_IN_ID_VC) {
		ht->value_comparator = build_in_int_deref_value_comparator;
	} else {
		ht->value_comparator = build_in_int_cast_value_comparator;
	}

	// allocate space for hashtable array
	ht->items = (item**)malloc(size * sizeof(item*));
	if (ht->items == NULL) return NULL;

	// fill hashtable array with NULLs
	int i = 0;
	for (i = 0; i < size; ++i) {
		ht->items[i] = NULL;
	}

	// store hashtable size in hashtable datastructure
	ht->size = size;
	
	return ht;
}

void delete_hash_table(hash_table *ht) {
	int i;
	// step through entire hashtable array
	for (i = 0; i < ht->size; ++i) {
		item *curr = ht->items[i];
		item *next;
		// free all elements until the element found is NULL
		while (curr != NULL) {
			next = curr->next;
			free(curr);
			curr = next;
		}
	}

	// free hashtable array and hashtable structure
	free(ht->items);
	free(ht);
}

void for_each_in_hash_table(hash_table *ht, void (*callback)(void* key, void* value)) {
	int i;
	// step through entire hashtable array
	for (i = 0; i < ht->size; ++i) {
		item *curr = ht->items[i];
		item *next;
		// call callback function on each element until the element found is NULL
		while (curr != NULL) {
			next = curr->next;
			callback(curr->key, curr->value);
			curr = next;
		}
	}
}

void print_ht(	hash_table* ht, 
				print_key_type pkt, const char* key_format, 
				print_value_type pvt, const char* value_format,
				const char* chain_sperator) {
	int i;
	// step through entire hashtable array
	for (i = 0; i < ht->size; ++i) {
		item *curr = ht->items[i];
		item *next;
		// call callback function on each element until the element found is NULL
		while (curr != NULL) {
			next = curr->next;
			// print elements as specified
			if (pkt == INT_DEREFERENCE_KP) {
				printf(key_format, *((int*)curr->key));
			} else {	// INT_CAST_KP
				printf(key_format, curr->key);
			}
			if (pvt == INT_DEREFERENCE_VP) {
				printf(value_format, *((int*)curr->value));
			} else {	// INT_CAST_VP
				printf(value_format, curr->value);
			}
			curr = next;
		}
		printf("%s", chain_sperator);
	}
}

void* hash_table_search(hash_table *ht, void *key) {
	// run prehash and hash functions to get array index
	int prehash = ht->prehash_function(key);
	unsigned int idx = ht->hash_function(prehash, ht->size);

	// if array at given hash index is empty return NULL (item does not exist)
	if (ht->items[idx] == NULL) {
		return NULL;
	}

	// loop through linked list in array to find the required emelent
	item *found = ht->items[idx];
	while (found != NULL && !ht->key_comparator(key, found->key)) {
		found = found->next;
	} 

	// if found is NULL the key is not present
	if (found == NULL) {
		return NULL;
	}

	return found->value;
}

int hash_table_insert(hash_table *ht, void *key, void *value) {
	// run prehash and hash functions to get array index
	int prehash = ht->prehash_function(key);
	unsigned int idx = ht->hash_function(prehash, ht->size);

	// loop through linked list in array to find the emelent if it exists
	item *found = ht->items[idx];
	while (found != NULL && !ht->key_comparator(key, found->key)) {
		found = found->next;
	} 
	if (found != NULL) {
		found->value = value;
		return 1;
	}

	// allocate memory for new hashtable entry
	item *new_item = (item*)malloc(sizeof(item));
	if (new_item == NULL) return -1;	// maybe also right into stderr

	// update new hashtable entry values
	new_item->key = key;
	new_item->value = value;
	new_item->next = NULL;

	// if array at given hash index is empty assign hashtable entry
	if (ht->items[idx] == NULL) {
		ht->items[idx] = new_item;
		return 1;
	}

	// loop through linked list in array to find the next available empty spot
	item *last = ht->items[idx];
	while (last->next != NULL && !ht->key_comparator(key, last->next->key)) {
		last = last->next;
	} 

	// assign value the end of the linked list
	last->next = new_item;
	return 1;
}

int hash_table_delete(hash_table *ht, void *key) {
	// run prehash and hash functions to get array index
	int prehash = ht->prehash_function(key);
	unsigned int idx = ht->hash_function(prehash, ht->size);

	// if array at given hash index is empty return 0 (item does not exist)
	if (ht->items[idx] == NULL) {
		return 0;
	}

	// loop through linked list in array to find the next available empty spot
	item *prev = NULL;
	item *found = ht->items[idx];
	while (found != NULL && !ht->key_comparator(key, found->key)) {
		prev = found;
		found = found->next;
	}

	// if entry not found on hash indexed linked list return 0 (item does not exist)
	if (found == NULL) {
		return 0;
	}

	// skip entry to be deleted and free memory
	// --if element is first in linked list set head to next element
	if (prev == NULL) {
		ht->items[idx] = found->next;
	}
	// --if previous element exists in linked list direct it to next element
	if (prev != NULL) {
		prev->next = found->next;
	}
	// -- free found element
	free(found);
	return 1;
}


unsigned int build_in_hash_function(long long int prehash, int size) {
	// perform % size as hash function
	return prehash % size;
}

// Int Dereferencing
// -----------------
long long int build_in_int_deref_prehash_function(void* key) {
	// cast void* to int* and return dereferenced value as prehash
	return *(int*)key;
}

int build_in_int_deref_key_comparator(void* key1, void* key2) {
	// compare integer values from dereferenced integer pointers
	if (key1 == NULL || key2 == NULL) return 0;
	return *(int *)key1 == *(int *)key2;
}

int build_in_int_deref_value_comparator(void* value1, void* value2) {
	// compare integer values from dereferenced integer pointers
	return *(int *)value1 == *(int *)value2;
}

// Int Casting
// ----------- 
long long int build_in_int_cast_prehash_function(void* key) {
	// cast void* to int* and return dereferenced value as prehash
	return (long long int)key;
}

int build_in_int_cast_key_comparator(void* key1, void* key2) {
	// compare integer values from dereferenced integer pointers
	//if (key1 == NULL || key2 == NULL) return 0;
	return (long long int)key1 == (long long int)key2;
}

int build_in_int_cast_value_comparator(void* value1, void* value2) {
	// compare integer values from dereferenced integer pointers
	return (long long int)value1 == (long long int)value2;
}

