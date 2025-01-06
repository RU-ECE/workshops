	.file	"08inlining.cpp"
	.text
	.p2align 4
	.globl	_Z1fi
	.type	_Z1fi, @function
_Z1fi:
.LFB1812:
	.cfi_startproc
	endbr64
	leal	0(,%rdi,8), %eax
	ret
	.cfi_endproc
.LFE1812:
	.size	_Z1fi, .-_Z1fi
	.p2align 4
	.globl	_Z1hddi
	.type	_Z1hddi, @function
_Z1hddi:
.LFB1813:
	.cfi_startproc
	endbr64
	testl	%edi, %edi
	jle	.L4
	movsd	.LC0(%rip), %xmm2
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L5:
	addsd	%xmm1, %xmm0
	addl	$1, %eax
	addsd	%xmm0, %xmm1
	addsd	%xmm2, %xmm1
	cmpl	%eax, %edi
	jne	.L5
.L4:
	addsd	%xmm1, %xmm0
	mulsd	.LC1(%rip), %xmm0
	ret
	.cfi_endproc
.LFE1813:
	.size	_Z1hddi, .-_Z1hddi
	.p2align 4
	.globl	_Z3adddd
	.type	_Z3adddd, @function
_Z3adddd:
.LFB1814:
	.cfi_startproc
	endbr64
	addsd	%xmm1, %xmm0
	ret
	.cfi_endproc
.LFE1814:
	.size	_Z3adddd, .-_Z3adddd
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB1815:
	.cfi_startproc
	endbr64
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movl	$3, %edi
	call	_Z1gi@PLT
	movl	$16, %esi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSolsEi@PLT
	xorl	%eax, %eax
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE1815:
	.size	main, .-main
	.p2align 4
	.type	_GLOBAL__sub_I__Z1fi, @function
_GLOBAL__sub_I__Z1fi:
.LFB2297:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	leaq	_ZStL8__ioinit(%rip), %rbp
	movq	%rbp, %rdi
	call	_ZNSt8ios_base4InitC1Ev@PLT
	movq	_ZNSt8ios_base4InitD1Ev@GOTPCREL(%rip), %rdi
	movq	%rbp, %rsi
	popq	%rbp
	.cfi_def_cfa_offset 8
	leaq	__dso_handle(%rip), %rdx
	jmp	__cxa_atexit@PLT
	.cfi_endproc
.LFE2297:
	.size	_GLOBAL__sub_I__Z1fi, .-_GLOBAL__sub_I__Z1fi
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I__Z1fi
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC0:
	.long	-1717986918
	.long	1069128089
	.align 8
.LC1:
	.long	-1717986918
	.long	1071225241
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
