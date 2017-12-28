.data

string0_label:
	.string "v[6] == 10\n"


string1_label:
	.string "b[3] == 10\n"


string2_label:
	.string "i != 200\n"


string3_label:
	.string "i == 200\n"

.comm __temp0, 4, 4
.comm __temp12, 4, 4
.comm __temp11, 4, 4
.comm __temp10, 4, 4
.comm __temp1, 4, 4
.comm __temp2, 4, 4
.comm __temp3, 4, 4
.comm __temp4, 4, 4
.comm __temp5, 4, 4
.comm __temp6, 4, 4
.comm __temp7, 4, 4
.comm __temp8, 4, 4
.comm __temp9, 4, 4

string4_label:
	.string "While i < 5\n"


string5_label:
	.string "v[5] == 2\n"


string6_label:
	.string "v[0] == 12\n"

##VECDEC
.comm	v,40,32

##VARDEC
	.globl	i
	.align 4
	.type	i, @object
	.size	i, 4
i:
	.long	10##VECDEC
.comm	b,40,32

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

##VEC ASSIGN
	movl i(%rip), %eax
	movl %eax, b+12(%rip)

##VEC ASSIGN
	movl $2, v+20(%rip)

##VEC READ
	movl	b+12(%rip), %eax
	movl	%eax, __temp0(%rip)

##VEC ASSIGN
	movl b+12(%rip), %eax
	movl %eax, v+24(%rip)

##FUNCALL
	movl $0, %eax
	call f

##VEC ASSIGN
	movl %eax, v+0(%rip)

##VEC READ
	movl	b+12(%rip), %eax
	movl	%eax, __temp1(%rip)

##EQUAL
	movl __temp1(%rip), %edx
	movl $10, %eax
	cmpl %eax, %edx
	jne .__label0

## PRINT
	movl $string1_label, %edi
	call printf

	jmp .__label1

.__label0:

.__label1:

##VEC READ
	movl	v+20(%rip), %eax
	movl	%eax, __temp3(%rip)

##EQUAL
	movl __temp3(%rip), %edx
	movl $2, %eax
	cmpl %eax, %edx
	jne .__label2

## PRINT
	movl $string5_label, %edi
	call printf

	jmp .__label3

.__label2:

.__label3:

##VEC READ
	movl	v+24(%rip), %eax
	movl	%eax, __temp5(%rip)

##EQUAL
	movl __temp5(%rip), %edx
	movl $10, %eax
	cmpl %eax, %edx
	jne .__label4

## PRINT
	movl $string0_label, %edi
	call printf

	jmp .__label5

.__label4:

.__label5:

##VEC READ
	movl	v+0(%rip), %eax
	movl	%eax, __temp7(%rip)

##EQUAL
	movl __temp7(%rip), %edx
	movl $12, %eax
	cmpl %eax, %edx
	jne .__label6

## PRINT
	movl $string6_label, %edi
	call printf

	jmp .__label7

.__label6:

.__label7:

##FUNCALL
	movl $0, %eax
	call f

##ASSIGN
	movl %eax, i(%rip)

##EQUAL
	movl i(%rip), %edx
	movl $200, %eax
	cmpl %eax, %edx
	jne .__label8

## PRINT
	movl $string3_label, %edi
	call printf

##ASSIGN
	movl i(%rip), %eax
	movl %eax, a(%rip)

	jmp .__label9

.__label8:

## PRINT
	movl $string2_label, %edi
	call printf

##ASSIGN
	movl a(%rip), %eax
	movl %eax, i(%rip)

.__label9:

##ASSIGN
	movl $0, i(%rip)

.__label11:

##LESS
	movl i(%rip), %edx
	movl $5, %eax
	cmpl %eax, %edx
	jge .__label10

## PRINT
	movl $string4_label, %edi
	call printf

##ADD
	movl i(%rip), %edx
	movl $1, %eax
	addl %edx, %eax
	movl %eax, __temp11(%rip)

##ASSIGN
	movl __temp11(%rip), %eax
	movl %eax, i(%rip)

	jmp .__label11

.__label10:

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
	movl %eax, __temp12(%rip)
movl __temp12(%rip), %eax

	popq	%rbp
	ret
