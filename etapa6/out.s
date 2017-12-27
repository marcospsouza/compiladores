.data
.comm __temp0, 4, 4

##VARDEC
	.globl	i
	.align 4
	.type	i, @object
	.size	i, 4
i:
	.long	0
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
 .__label0

.__label0:

	popq	%rbp
	ret
