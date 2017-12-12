#include "genco.h"
#include <stdio.h>
#include <stdlib.h>

TAC* makeIfThen(TAC* code0,TAC* code1);

TAC* tacCreate(int type, HASH_NODE* res,HASH_NODE* op1,HASH_NODE* op2){
    TAC* newtac;
    newtac = (TAC*)calloc(1,sizeof(TAC));
    newtac->type = type;
    newtac->res = res;
    newtac->op1 = op1;
    newtac->op2 = op2;
    newtac->prev = 0;
    newtac->next = 0;

    return newtac;
}

TAC* tacJoin(TAC* l1, TAC* l2){
  TAC* tac= l2;
  if (!l1) return l2;
  if (!l2) return l1;
  while(tac->prev)
    tac = tac->prev;

  tac->prev=l1;
  return l2;


}

void tacPrintSingle(TAC* tac){
  if(!tac)return;
  if(tac->type == TAC_SYMBOL)return;

  fprintf(stderr, "TAC(");
  switch(tac->type){
    case TAC_SYMBOL: fprintf(stderr,"TAC_SYMBOL");break;
    case TAC_ADD: fprintf(stderr,"TAC_ADD");break;
    case TAC_SUB: fprintf(stderr,"TAC_SUB");break;
    case TAC_MUL: fprintf(stderr,"TAC_MUL");break;
    case TAC_DIV: fprintf(stderr,"TAC_DIV");break;
    case TAC_GT: fprintf(stderr,"TAC_GT");break;
    case TAC_LS: fprintf(stderr,"TAC_LS");break;
    case TAC_NOT: fprintf(stderr,"TAC_NOT");break;
    case TAC_LE: fprintf(stderr,"TAC_LE");break;
    case TAC_GE: fprintf(stderr,"TAC_GE");break;
    case TAC_EQ: fprintf(stderr,"TAC_EQ");break;
    case TAC_NE: fprintf(stderr,"TAC_NE");break;
    case TAC_AND: fprintf(stderr,"TAC_AND");break;
    case TAC_OR: fprintf(stderr,"TAC_OR");break;
    case TAC_JZ: fprintf(stderr,"TAC_JZ");break;
    case TAC_LABEL: fprintf(stderr,"TAC_LABEL");break;
    case TAC_ASSIGN: fprintf(stderr,"TAC_ASSIGN");break;
    case TAC_VASSIGN: fprintf(stderr, "TAC_VASSIGN");break;
    case TAC_VACCESS: fprintf(stderr, "TAC_VACESS");break;
    case TAC_PRINT: fprintf(stderr, "TAC_PRINT");break;
    case TAC_PRINTARG: fprintf(stderr, "TAC_PRINTARG");break;
    case TAC_READ: fprintf(stderr, "TAC_READ");break;
    case TAC_RETURN: fprintf(stderr, "TAC_RETURN");break;
    case TAC_JMP: fprintf(stderr, "TAC_JMP");break;
    case TAC_BEGINFUN: fprintf(stderr, "TAC_BEGINFUN");break;
    case TAC_ENDFUN: fprintf(stderr, "TAC_ENDFUN");break;
    case TAC_FUNCALL: fprintf(stderr, "TAC_FUNCALL");break;
    case TAC_ARG: fprintf(stderr, "TAC_ARG");break;
    default: fprintf(stderr,"UNKNOWN");break;


  }


  if (tac->res) fprintf(stderr,"%s",tac->res->value); else fprintf(stderr,",null");
  if (tac->op1) fprintf(stderr,"%s",tac->op1->value); else fprintf(stderr,",null");
  if (tac->op2) fprintf(stderr,"%s",tac->op2->value); else fprintf(stderr,",null");
  fprintf(stderr,"\n");


}



void tacPrintBack(TAC* last){
  TAC* tac;
  for (tac = last; tac != NULL; tac=tac->prev){
    tacPrintSingle(tac);
  }
}



TAC* tacGenerator(AST* node){
  TAC* code[MAX_SONS];
  int i;

  if(!node) return 0;
  //first generate children
  for (i=0; i<MAX_SONS; ++i){
    code[i] = tacGenerator(node->son[i]);
  }



  TAC* funcall_TAC;
  TAC* arg;
  switch(node->type){
    case AST_SYMBOL: return tacCreate(TAC_SYMBOL, node->symbol,0,0);break;
    case AST_ADD: return tacJoin(tacJoin(code[0], code[1]), tacCreate(TAC_ADD, makeTemp(),code[0]?code[0]->res:0,code[1]?code[1]->res:0));break;
    case AST_SUB: return tacJoin(tacJoin(code[0], code[1]), tacCreate(TAC_SUB, makeTemp(),code[0]?code[0]->res:0,code[1]?code[1]->res:0));break;
    case AST_MUL: return tacJoin(tacJoin(code[0], code[1]), tacCreate(TAC_MUL, makeTemp(),code[0]?code[0]->res:0,code[1]?code[1]->res:0));break;
    case AST_DIV: return tacJoin(tacJoin(code[0], code[1]), tacCreate(AST_DIV, makeTemp(),code[0]?code[0]->res:0,code[1]?code[1]->res:0));break;
    case AST_GT: return tacJoin(tacJoin(code[0], code[1]), tacCreate(TAC_GT, makeTemp(), code[0]?code[0]->res:0, code[1]?code[1]->res:0)); break;
    case AST_LS: return tacJoin(tacJoin(code[0], code[1]), tacCreate(TAC_LS, makeTemp(), code[0]?code[0]->res:0, code[1]?code[1]->res:0)); break;
    case AST_NOT: return tacJoin(tacJoin(code[0], code[1]), tacCreate(TAC_NOT, makeTemp(), code[0]?code[0]->res:0, code[1]?code[1]->res:0)); break;
    case AST_LE: return tacJoin(tacJoin(code[0], code[1]), tacCreate(TAC_LE, makeTemp(), code[0]?code[0]->res:0, code[1]?code[1]->res:0)); break;
    case AST_GE: return tacJoin(tacJoin(code[0], code[1]), tacCreate(TAC_GE, makeTemp(), code[0]?code[0]->res:0, code[1]?code[1]->res:0)); break;
    case AST_EQ: return tacJoin(tacJoin(code[0], code[1]), tacCreate(TAC_EQ, makeTemp(), code[0]?code[0]->res:0, code[1]?code[1]->res:0)); break;
    case AST_NE: return tacJoin(tacJoin(code[0], code[1]), tacCreate(TAC_NE, makeTemp(), code[0]?code[0]->res:0, code[1]?code[1]->res:0)); break;
    case AST_AND: return tacJoin(tacJoin(code[0], code[1]), tacCreate(TAC_AND, makeTemp(), code[0]?code[0]->res:0, code[1]?code[1]->res:0)); break;
    case AST_OR: return tacJoin(tacJoin(code[0], code[1]), tacCreate(TAC_OR, makeTemp(), code[0]?code[0]->res:0, code[1]?code[1]->res:0)); break;

    case AST_ASSIGN: return tacJoin(code[0],tacCreate(TAC_ASSIGN,node->symbol,code[0]?code[0]->res:0,0));break;
    case AST_VASSIGN: return tacJoin(tacJoin(code[0], code[1]), tacCreate(TAC_VASSIGN, node->symbol, code[1]?code[1]->res:0, code[0]?code[0]->res:0)); break;
    case AST_VACCESS: return tacJoin(code[0], tacCreate(TAC_VACCESS, makeTemp(), node->symbol, code[0]?code[0]->res:0)); break;
    case AST_KWIF: return makeIfThen(code[0],code[1]);break;

    //case AST_KWPRINT: return tacJoin(code[0],tacCreate(TAC_PRINT(code[0]?code[0]->res,))); break;
    //case AST_KWPRINT: return tacCreate(TAC_PRINT, node->symbol, 0, 0); break;
    case AST_PRINTARGS: return tacJoin(tacCreate(TAC_PRINTARG, code[0]?code[0]->res:0, 0, 0), code[1]);break;
    case AST_KWREAD: return tacCreate(TAC_READ, node->symbol, 0, 0); break;

    case AST_KWWHILE: return makeWhile(code[0], code[1]); break;

    case AST_KWRETURN: return tacJoin(code[0], tacCreate(TAC_RETURN, code[0]?code[0]->res:0, 0, 0)); break;

    case AST_FUNDEC: return makeFun(node->symbol, code[3]);break;

    case AST_FUNCALL:
      funcall_TAC = tacJoin(code[0], tacCreate(TAC_FUNCALL, node->symbol, 0, 0));
      arg = funcall_TAC;

      if(arg != NULL){
        while(arg->prev != NULL){
          arg = arg->prev;
          if(arg->type == TAC_ARG)
            arg->res = node->symbol;
        }
      }
      return funcall_TAC;
      break;

    case AST_ARGS: return tacJoin(tacJoin(code[0], tacCreate(TAC_ARG, 0, code[0]?code[0]->res:0, 0)), code[1]); break;
  }
  return tacJoin(tacJoin(tacJoin(code[0],code[1]),code[2]),code[3]);


}

TAC* makeWhile(TAC* code0, TAC* code1){

  TAC* finalTacJump = 0;
  TAC* finalTacLabel = 0;
  HASH_NODE* label_final = makeLabel();
  finalTacLabel = tacCreate(TAC_LABEL,label_final,0,0);
  finalTacJump = tacCreate(TAC_JZ,label_final,code0?code0->res:0,0);

  TAC* initialTacJump = 0;
  TAC* initialTacLabel = 0;
  HASH_NODE* label_initial = makeLabel();
  initialTacLabel = tacCreate(TAC_LABEL,label_initial,0,0);
  initialTacJump = tacCreate(TAC_JMP,label_initial,code0?code0->res:0,0);



  return tacJoin(tacJoin(tacJoin(tacJoin(tacJoin(initialTacLabel,code0),finalTacJump),code1),initialTacJump),finalTacLabel);
}

TAC* makeIfThen(TAC* code0,TAC* code1){
  TAC* newJumpTac = 0;
  TAC* newLabelTac = 0;

  HASH_NODE* newLabel = makeLabel();

  newJumpTac = tacCreate(TAC_JZ,newLabel,code0?code0->res:0,0);
  newLabelTac = tacCreate(TAC_LABEL,newLabel,0,0);

  return tacJoin(tacJoin(tacJoin(code0,newJumpTac),code1), newLabelTac);
}


TAC* makeFun(HASH_NODE* f, TAC* c){
  TAC* beginFunTac = 0;
  TAC* endFunTac = 0;

  beginFunTac = tacCreate(TAC_BEGINFUN, f, 0, 0);
  endFunTac = tacCreate(TAC_ENDFUN, f, 0, 0);

  return tacJoin(tacJoin(beginFunTac, c), endFunTac);
}
//no modo dele vaiter que fazer duas passagens, mas nao vamos perceber isso pq o assembler que vai cuidar dessa idiotice
///BACKPATCHING lista com pontos de jump para código que ainda nao foi gerado
//nunca fazer ponteiro de tac pra tac
//tac é um trecho de código em assembly????!?!@?#!??$#!$?






TAC* tacReverse(TAC*last){
  if(!last)
    return 0;
  while(last->prev){
    last->prev->next = last;
    last = last->prev;
  }

}





void tacPrintForward(TAC* last){
  TAC* tac;
  for(tac = ) //nunca voltou pra cá, RIP
    tacPrint
}
