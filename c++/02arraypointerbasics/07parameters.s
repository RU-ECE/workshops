	.file	"07parameters.cpp"
	.text
	.p2align 4
	.globl	_Z1fi
	.type	_Z1fi, @function
_Z1fi:
.LFB1812:
	.cfi_startproc
	endbr64
	leal	1(%rdi), %eax
	ret
	.cfi_endproc
.LFE1812:
	.size	_Z1fi, .-_Z1fi
	.p2align 4
	.globl	_Z1ff
	.type	_Z1ff, @function
_Z1ff:
.LFB1813:
	.cfi_startproc
	endbr64
	mulss	%xmm0, %xmm0
	ret
	.cfi_endproc
.LFE1813:
	.size	_Z1ff, .-_Z1ff
	.p2align 4
	.globl	_Z1fdd
	.type	_Z1fdd, @function
_Z1fdd:
.LFB1814:
	.cfi_startproc
	endbr64
	addsd	%xmm1, %xmm0
	ret
	.cfi_endproc
.LFE1814:
	.size	_Z1fdd, .-_Z1fdd
	.p2align 4
	.globl	_Z6longeriddd
	.type	_Z6longeriddd, @function
_Z6longeriddd:
.LFB1815:
	.cfi_startproc
	endbr64
	addsd	%xmm1, %xmm0
	pxor	%xmm1, %xmm1
	cvtsi2sdl	%edi, %xmm1
	addsd	%xmm2, %xmm0
	mulsd	%xmm1, %xmm0
	ret
	.cfi_endproc
.LFE1815:
	.size	_Z6longeriddd, .-_Z6longeriddd
	.p2align 4
	.globl	_Z11arraythingyPKidPdi
	.type	_Z11arraythingyPKidPdi, @function
_Z11arraythingyPKidPdi:
.LFB1816:
	.cfi_startproc
	endbr64
	ret
	.cfi_endproc
.LFE1816:
	.size	_Z11arraythingyPKidPdi, .-_Z11arraythingyPKidPdi
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB1817:
	.cfi_startproc
	endbr64
	xorl	%eax, %eax
	ret
	.cfi_endproc
.LFE1817:
	.size	main, .-main
	.p2align 4
	.type	_GLOBAL__sub_I__Z1fi, @function
_GLOBAL__sub_I__Z1fi:
.LFB2299:
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
.LFE2299:
	.size	_GLOBAL__sub_I__Z1fi, .-_GLOBAL__sub_I__Z1fi
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I__Z1fi
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
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
