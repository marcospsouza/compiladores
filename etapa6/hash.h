//Feito por Marcos Praisler de Souza (242239) e João Batista Henz (242251)
#define HASH_SIZE 977


/*nao tamo usando esses aqui
#define SYMBOL_LIT_INT 1
#define SYMBOL_LIT_CHAR 2
#define SYMBOL_ID 3
#define SYMBOL_LIT_STRING 4
*/

#define SYMBOL_TEMPORARY_VAR 4
#define SYMBOL_VAR 5
#define SYMBOL_VEC 6
#define SYMBOL_FUN 7
#define SYMBOL_LABEL 8

#define DATATYPE_BYTE 20
#define DATATYPE_SHORT 21
#define DATATYPE_LONG 22
#define DATATYPE_FLOAT 23
#define DATATYPE_DOUBLE 24

//substitui todos os id's por esses caras aqui

struct node
{
	char *value; //*text
	int tk_type; //type
	int data_type;
	int node_line;
	struct node *next;
};

typedef struct node HASH_NODE;
HASH_NODE *table[HASH_SIZE];


void hash_create();
void hash_print();
HASH_NODE *hash_insert (char *text, int type);
HASH_NODE *hash_search (char *text);
int hash_function(char *text);
HASH_NODE* makeTemp(void);
