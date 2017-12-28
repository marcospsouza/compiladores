	.file	"a.c"
	.comm	v,80,32
	.comm	b,40,32
	.globl	i
	.data
	.align 4
	.type	i, @object
	.size	i, 4
i:
	.long	10
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	pushq	%rbp
	movq	%rsp, %rbp

	movl	i(%rip), %eax
	movl	%eax, b+12(%rip)
	movl	$2, v+20(%rip)
	
	movl	b+12(%rip), %eax
	movl	%eax, v+24(%rip)

	movl	$0, %eax
	popq	%rbp
	ret
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
