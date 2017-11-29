#ifndef GENCO_HEADER
#define GENCO_HEADER

#include "hash.h"
#include "astree.h"


#define TAC_SYMBOL 1
#define TAC_ADD 2
#define TAC_SUB 3
#define TAC_MUL 4
#define TAC_DIV 5
#define TAC_ASS 6
#define TAC_JZ 7
#define TAC_VECWRITE 8
#define TAC_VECREAD 9
#define TAC_INPUT 10
#define TAC_OUPUT 11//uma pra cada parametro do printf
#define TAC_RETURN 12
#define TAC_JMP 13
#define TAC_LABEL 14
#define TAC_BEGINFUN 15
#define TAC_ENDFUN 16
#define TAC_CALL 17
#define TAC_ARG 18////não sei se existe realmente

//argumetno 0 da função f, argumento 1 da funçao f,. ... gera uuns temp safado


/*
não quer:
  TAC_SYMBOL - ??????
  declarações -

*/


typedef struct struct_tac{

  int type;
  HASH_NODE* res;
  HASH_NODE* op1;
  HASH_NODE* op2;
  struct struct_tac* prev;
  struct struct_tac* next;



}TAC;

TAC* tacCreate(int type, HASH_NODE* res,HASH_NODE* op1,HASH_NODE* op2);
TAC* tacGenerator(AST* node);
TAC* tacJoin(TAC* l1, TAC* l2);
void tacPrintBack(TAC* last);

#endif