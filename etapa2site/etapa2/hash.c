//Feito por Marcos Praisler de Souza (242239) e João Batista Henz (242251)
#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hash_create(){

	int i;
	for (i=0; i< HASH_SIZE; i++){
	    table[i] = 0;
	}
}


void hash_print(){

	HASH_NODE *n;

	int i;
	for(i = 0; i < HASH_SIZE; i++){
	   for(n = table[i]; n != NULL; n = n->next){
	       printf ("%s\n",n->value);
	   }
	}
	printf("\n");
}

int hash_function(char *text){

	unsigned long int hash_address = 0;
	int i;

	for(i = 0; i < strlen(text); i++) {
		hash_address = hash_address * 256;
		hash_address += text[i];
		hash_address %= HASH_SIZE;
		i++;
	}

	return hash_address;
}


HASH_NODE *hash_insert (char *text, int type){

	HASH_NODE *newnode;
	int address = hash_function(text);

	if ((newnode = hash_search(text)) != 0)
		return newnode;
	
	newnode = (HASH_NODE *) malloc (sizeof(HASH_NODE));
	newnode->value = (char *) malloc (sizeof(char)*strlen(text));
	strcpy(newnode->value, text);
        
	newnode->tk_type = type;
	newnode->next = table[address];
	table[address] = newnode;
	return newnode;
}

HASH_NODE *hash_search (char *text){

	HASH_NODE *node;
	int address;
	address = hash_function(text);

	for (node=table[address]; node; node=node->next){
		if ((strcmp (node->value, text)) == 0)
	 		return node;
	}
	return 0;
}
