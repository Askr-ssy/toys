	.file	"leetcode-100.cpp"
	.text
	.section	.rodata
	.type	_ZStL19piecewise_construct, @object
	.size	_ZStL19piecewise_construct, 1
_ZStL19piecewise_construct:
	.zero	1
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.type	_ZStL13allocator_arg, @object
	.size	_ZStL13allocator_arg, 1
_ZStL13allocator_arg:
	.zero	1
	.text
	.globl	_Z10isSameTreeP8TreeNodeS0_
	.type	_Z10isSameTreeP8TreeNodeS0_, @function
_Z10isSameTreeP8TreeNodeS0_:
.LFB2574:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	cmpq	$0, -8(%rbp)
	jne	.L2
	cmpq	$0, -16(%rbp)
	jne	.L2
	movl	$1, %eax
	jmp	.L3
.L2:
	cmpq	$0, -8(%rbp)
	jne	.L4
	cmpq	$0, -16(%rbp)
	je	.L4
	movl	$0, %eax
	jmp	.L3
.L4:
	cmpq	$0, -8(%rbp)
	je	.L5
	cmpq	$0, -16(%rbp)
	jne	.L5
	movl	$0, %eax
	jmp	.L3
.L5:
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	testq	%rax, %rax
	jne	.L6
	movq	-16(%rbp), %rax
	movq	8(%rax), %rax
	testq	%rax, %rax
	je	.L6
	movl	$0, %eax
	jmp	.L3
.L6:
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	testq	%rax, %rax
	je	.L7
	movq	-16(%rbp), %rax
	movq	8(%rax), %rax
	testq	%rax, %rax
	jne	.L7
	movl	$0, %eax
	jmp	.L3
.L7:
	movq	-8(%rbp), %rax
	movq	16(%rax), %rax
	testq	%rax, %rax
	jne	.L8
	movq	-16(%rbp), %rax
	movq	16(%rax), %rax
	testq	%rax, %rax
	je	.L8
	movl	$0, %eax
	jmp	.L3
.L8:
	movq	-8(%rbp), %rax
	movq	16(%rax), %rax
	testq	%rax, %rax
	je	.L9
	movq	-16(%rbp), %rax
	movq	16(%rax), %rax
	testq	%rax, %rax
	jne	.L9
	movl	$0, %eax
	jmp	.L3
.L9:
	movq	-8(%rbp), %rax
	movl	(%rax), %edx
	movq	-16(%rbp), %rax
	movl	(%rax), %eax
	cmpl	%eax, %edx
	je	.L10
	movl	$0, %eax
	jmp	.L3
.L10:
	movq	-16(%rbp), %rax
	movq	8(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_Z10isSameTreeP8TreeNodeS0_
	xorl	$1, %eax
	testb	%al, %al
	jne	.L11
	movq	-16(%rbp), %rax
	movq	16(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_Z10isSameTreeP8TreeNodeS0_
	xorl	$1, %eax
	testb	%al, %al
	je	.L12
.L11:
	movl	$1, %eax
	jmp	.L13
.L12:
	movl	$0, %eax
.L13:
	testb	%al, %al
	je	.L14
	movl	$0, %eax
	jmp	.L3
.L14:
	movl	$1, %eax
.L3:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2574:
	.size	_Z10isSameTreeP8TreeNodeS0_, .-_Z10isSameTreeP8TreeNodeS0_
	.globl	main
	.type	main, @function
main:
.LFB2575:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2575:
	.size	main, .-main
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB3056:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	cmpl	$1, -4(%rbp)
	jne	.L19
	cmpl	$65535, -8(%rbp)
	jne	.L19
	leaq	_ZStL8__ioinit(%rip), %rdi
	call	_ZNSt8ios_base4InitC1Ev@PLT
	leaq	__dso_handle(%rip), %rdx
	leaq	_ZStL8__ioinit(%rip), %rsi
	movq	_ZNSt8ios_base4InitD1Ev@GOTPCREL(%rip), %rax
	movq	%rax, %rdi
	call	__cxa_atexit@PLT
.L19:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3056:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I__Z10isSameTreeP8TreeNodeS0_, @function
_GLOBAL__sub_I__Z10isSameTreeP8TreeNodeS0_:
.LFB3057:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$65535, %esi
	movl	$1, %edi
	call	_Z41__static_initialization_and_destruction_0ii
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3057:
	.size	_GLOBAL__sub_I__Z10isSameTreeP8TreeNodeS0_, .-_GLOBAL__sub_I__Z10isSameTreeP8TreeNodeS0_
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I__Z10isSameTreeP8TreeNodeS0_
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 9.2.1-17ubuntu1~18.04.1) 9.2.1 20191102"
	.section	.note.GNU-stack,"",@progbits
