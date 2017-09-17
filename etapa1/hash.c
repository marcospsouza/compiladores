
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include "hash.h"


int entries = 0;

hashtable_t *ht_create( int size ) {

	hashtable_t *hashtable = NULL;
	int i;

	if( size < 1 ) return NULL;

	if( ( hashtable = malloc( sizeof( hashtable_t ) ) ) == NULL ) {
		return NULL;
	}

	if( ( hashtable->table = malloc( sizeof( entry_t * ) * size ) ) == NULL ) {
		return NULL;
	}
	for( i = 0; i < size; i++ ) {
		hashtable->table[i] = NULL;
	}

	hashtable->size = size;

	return hashtable;	
}

int ht_hash( hashtable_t *hashtable, char *key ) {
	unsigned long int hashval = 0;
	int i;

	for(i = 0; i < strlen(key); i++) {
		hashval = hashval * 256;
		hashval += key[ i ];
		hashval %= hashtable->size;
		i++;
	}

	return hashval;
}


void entry_destroy(entry_t *next){
	if(next != NULL){
		free(next->key);
		free(next->value);
		entry_destroy(next->next);
		free(next);
	}
}

void ht_destroy(hashtable_t *hashtable){
	int i;
	for(i = 0; i < hashtable->size; i++){
		entry_destroy(hashtable->table[i]);
	}
	free(hashtable->table);
	free(hashtable);
}

entry_t *ht_get( hashtable_t *hashtable, char *key ) {
	int bin = 0;
	entry_t *pair;

	bin = ht_hash( hashtable, key );

	pair = hashtable->table[ bin ];
	while( pair != NULL && pair->key != NULL && strcmp( key, pair->key ) > 0 ) {
		pair = pair->next;
	}

	if( pair == NULL || pair->key == NULL || strcmp( key, pair->key ) != 0 ) {
		return NULL;

	} else {
		return pair;
	}
	
}


hashtable_t *ht_rehash(hashtable_t *old, int size){

	hashtable_t *new = ht_create(size);

	int i;
	for(i = 0; i < old->size; i++){
		entry_t *next = old->table[i];
		while(next != NULL){
			if(next->key != NULL && next->value != NULL){
				new = ht_set(new, next->key, next->value);
				entry_t *new_entry = ht_get(new, next->key);
			}
		}
	}

	ht_destroy(old);
	return new;
}


entry_t *ht_newpair( char *key, char *value ) {
	entry_t *newpair;

	if( ( newpair = malloc( sizeof( entry_t ) ) ) == NULL ) {
		return NULL;
	}

	if( ( newpair->key = strdup( key ) ) == NULL ) {
		return NULL;
	}

	if( ( newpair->value = strdup( value ) ) == NULL ) {
		return NULL;
	}

	newpair->next = NULL;

	return newpair;
}

hashtable_t *ht_set( hashtable_t *hashtable, char *key, char *value ) {
	int bin = 0;
	entry_t *newpair = NULL;
	entry_t *next = NULL;
	entry_t *last = NULL;

	bin = ht_hash( hashtable, key );

	next = hashtable->table[ bin ];

	while( next != NULL && next->key != NULL && strcmp( key, next->key ) > 0 ) {
		last = next;
		next = next->next;
	}

	if( next != NULL && next->key != NULL && strcmp( key, next->key ) == 0 ) {

		free( next->value );
		next->value = strdup( value );

	} else {
		newpair = ht_newpair( key, value );
		if( next == hashtable->table[ bin ] ) {
			entries++;
			newpair->next = next;
			hashtable->table[ bin ] = newpair;

			if (entries >= hashtable->size/2){
				hashtable = ht_rehash(hashtable, hashtable->size*4);
			}
	
		} else if ( next == NULL ) {
			last->next = newpair;
	
		} else  {
			newpair->next = next;
			last->next = newpair;
		}
	}

	return hashtable;
}
