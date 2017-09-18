/* 
	Feito por Marcos Praisler de Souza (242239) e João Batista Henz (242251)
*/

#define HASH_SIZE 977

typedef struct node
{
	char *value;
	int tk_type;
	struct node *next;
} HASH_NODE;

HASH_NODE *table[HASH_SIZE];


void hash_create();
void hash_print();
HASH_NODE *hash_insert (char *text, int type);
HASH_NODE *hash_search (char *text);
int hash_function(char *text);


