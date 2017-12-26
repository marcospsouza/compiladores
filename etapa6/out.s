
string0_label:
	.string "Marcos\n"


string1_label:
	.string "João\n"


##VARDEC
	.globl	a
	.align 4
	.type	a, @object
	.size	a, 4
a:
	.long	10
##BEGFUN
.text
.globl	main
.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp

## PRINT
	movl $string1_label, %edi
	call printf

## PRINT
	movl $string97_label, %edi
	call printf

## PRINT
	movl $string0_label, %edi
	call printf


	
	
	
