.data

string0_label:
	.string "Marcos\n"

.comm __temp0, 4, 4
.comm __temp1, 4, 4
.comm __temp2, 4, 4
.comm __temp3, 4, 4

string1_label:
	.string "i != 12"


string2_label:
	.string "João\n"


string3_label:
	.string "While i < 5\n"


string4_label:
	.string "i == 12\n"


##VARDEC
	.globl	i
	.align 4
	.type	i, @object
	.size	i, 4
i:
	.long	10
##VARDEC
	.globl	a
	.align 4
	.type	a, @object
	.size	a, 4
a:
	.long	2
##BEGFUN
.text
.globl	main
.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp

##FUNCALL
	movl $0, %eax
	call f

##ASSIGN
	movl %eax, i(%rip)
##EQUAL
	movl i(%rip), %edx
	movl $12, %eax
	cmpl %eax, %edx
	jne .__label0

## PRINT
	movl $string4_label, %edi
	call printf

##ASSIGN
	movl i(%rip), %eax
	movl %eax, a(%rip)

	jmp .__label1

.__label0:

## PRINT
	movl $string1_label, %edi
	call printf

##ASSIGN
	movl a(%rip), %eax
	movl %eax, i(%rip)

.__label1:

## PRINT
	movl $string2_label, %edi
	call printf

## PRINT
	movl $string0_label, %edi
	call printf

##ASSIGN
	movl $0, i(%rip)

.__label3:

##LESS
	movl i(%rip), %edx
	movl $5, %eax
	cmpl %eax, %edx
	jge .__label2

## PRINT
	movl $string3_label, %edi
	call printf

##ADD
	movl i(%rip), %edx
	movl $1, %eax
	addl %edx, %eax
	movl %eax, __temp2(%rip)

##ASSIGN
	movl __temp2(%rip), %eax
	movl %eax, i(%rip)

	jmp .__label3

.__label2:

	popq	%rbp
	ret

##BEGFUN
.text
.globl	f
.type	f, @function
f:
	pushq	%rbp
	movq	%rsp, %rbp

##ADD
	movl $10, %edx
	movl a(%rip), %eax
	addl %edx, %eax
	movl %eax, __temp3(%rip)
movl __temp3(%rip), %eax

	popq	%rbp
	ret
