.data

string0_label:
	.string "Marcos\n"

.comm __temp0, 4, 4
.comm __temp1, 4, 4

string1_label:
	.string "João\n"


string2_label:
	.string "While i < 5\n"


##VARDEC
	.globl	i
	.align 4
	.type	i, @object
	.size	i, 4
i:
	.long	0
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
	movl $string0_label, %edi
	call printf

.__label1:

##LESS
	movl i(%rip), %edx
	movl $5, %eax
	cmpl %eax, %edx
	jge .__label0

## PRINT
	movl $string2_label, %edi
	call printf

##ADD
	movl i(%rip), %edx
	movl $1, %eax
	addl %edx, %eax
	movl %eax, __temp1(%rip)

##ASSIGN
	movl __temp1(%rip), %eax
	movl %eax, i(%rip)

	jmp .__label1

.__label0:

	popq	%rbp
	ret
