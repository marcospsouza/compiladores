//Feito por Marcos Praisler de Souza (242239) e João Batista Henz (242251)
#define HASH_SIZE 977



#define SYMBOL_LIT_INT 1
#define SYMBOL_ID 2
#define SYMBOL_LIT_STRING 3


#define SYMBOL_VAR 4
#define SYMBOL_VEC 5
#define SYMBOL_FUN 6

#define DATATYPE_INT 1
#define DATATYPE_CHAR 2
//substitui todos os id's por esses caras aqui

struct node
{
	char *value; //*text
	int tk_type; //type                                                                                               
	struct node *next;
};

typedef struct node HASH_NODE;
HASH_NODE *table[HASH_SIZE];


void hash_create();
void hash_print();
HASH_NODE *hash_insert (char *text, int type);
HASH_NODE *hash_search (char *text);
int hash_function(char *text);

