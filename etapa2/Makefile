

etapa2: y.tab.o lex.yy.o hash.o main.o 
	gcc lex.yy.o hash.o main.o -o etapa1




lex.yy.o: lex.yy.c
	gcc lex.yy.c -c


y.tab.o: y.tab.c
	gcc -c y.tab.c


hash.o: hash.c
	gcc hash.c -c

main.o: main.c
	gcc main.c -c

y.tab.c: parser.y
	yacc -d parser.y


lex.yy.c: scanner.l
	lex scanner.l

clean:
	rm etapa2 lex.yy.c *.o