	.file	"Demo.c"
	.text
	.globl	No1
	.data
	.align 4
	.type	No1, @object
	.size	No1, 4
No1:
	.long	10
	.comm	No2,4,4
	.section	.rodata
.LC0:
	.string	"Process is running..."
.LC1:
	.string	"Pid of parent process is %d \n"
	.align 8
.LC2:
	.string	"Pid of current process is %d \n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
	movl	$20, -12(%rbp)
	movl	$16, %edi
	call	malloc@PLT
	movq	%rax, -8(%rbp)
	leaq	.LC0(%rip), %rdi
	call	puts@PLT
	call	getppid@PLT
	movl	%eax, %esi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	call	getpid@PLT
	movl	%eax, %esi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	free@PLT
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
