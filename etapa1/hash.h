#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>



struct s_parlist{
	char* param;
	struct s_parlist *next;
};

struct entry_s {
	char *key;
	char *value;
	struct entry_s *next;
};

typedef struct entry_s entry_t;

struct hashtable_s {
	int size;
	struct entry_s **table;	
};

typedef struct hashtable_s hashtable_t;



hashtable_t *ht_create( int size ) ;/* Create a new hashtable. */

entry_t *ht_newpair( char *key, char *value );/* Create a key-value pair. */

void entry_destroy(entry_t *next);

void ht_destroy(hashtable_t *hashtable);

hashtable_t *ht_set( hashtable_t *hashtable, char *key, char *value );/* Insert a key-value pair into a hash table. */

entry_t *ht_get( hashtable_t *hashtable, char *key );/* Retrieve a key-value pair from a hash table. */

int ht_hash( hashtable_t *hashtable, char *key ) ;/* Hash a string for a particular hash table. */

hashtable_t *ht_rehash(hashtable_t *old, int size);



