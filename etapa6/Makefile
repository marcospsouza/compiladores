#Feito por Marcos Praisler de Souza (242239) e João Batista Henz (242251)


etapa6: y.tab.o lex.yy.o hash.o main.o astree.o semantic.o genco.o asmgen.o
	gcc -o etapa6 y.tab.o lex.yy.o astree.o hash.o main.o semantic.o genco.o asmgen.o

asmgen.o: asmgen.c
	gcc -c asmgen.c
	
genco.o: genco.c
	gcc -c genco.c
	
astree.o: astree.c
	gcc -c astree.c

semantic.o: semantic.c
	gcc -c semantic.c

main.o: main.c
	gcc -c main.c

hash.o: hash.c
	gcc -c hash.c

y.tab.o: y.tab.c lex.yy.h
	gcc -c y.tab.c

y.tab.c: parser.y
	yacc -d -v parser.y

lex.yy.o: lex.yy.c
	gcc -c lex.yy.c

lex.yy.h: scanner.l
	lex scanner.l

lex.yy.c: scanner.l
	lex scanner.l

clean:
	rm *.o lex.yy.c y.tab.c y.tab.h etapa6 y.output