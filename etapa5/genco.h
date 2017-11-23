#ifndef GENCO_HEADER
#define GENCO_HEADER

#include "hash.h"
#include "astree.h"


#define TAC_SYMBOL 1
#define TAC_ADD 2
#define TAC_MUL 3
#define TAC_ASS 5
#define TAC_JZ 6
#define TAC_VECWRITE 6
#define TAC_VECREAD 6
#define TAC_INPUT 6
#define TAC_OUPUT 6 //uma pra cada parametro do printf
#define TAC_RETURN 6
#define TAC_JMP 6
#define TAC_LABEL 6
#define TAC_BEGINFUN 6
#define TAC_ENDFUN 6
#define TAC_CALL 6
#define TAC_ARG 6////não sei se existe realmente

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

TAC* tacCreate(int type, HASH_NODE* res,HASH_NODE* op1,HASH_NODE* op2,);
TAC* tacGenerator(AST* node);
TAC* tacJoin(TAC* l1, TAC* l2);
void tacPrintBack(TAC* last);

#endinf
