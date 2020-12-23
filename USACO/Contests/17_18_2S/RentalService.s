	.file	"RentalService.cpp"
	.text
	.p2align 4,,15
	.globl	_Z3cmpRKSt4pairIxxES2_
	.def	_Z3cmpRKSt4pairIxxES2_;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z3cmpRKSt4pairIxxES2_
_Z3cmpRKSt4pairIxxES2_:
.LFB8499:
	.seh_endprologue
	movq	8(%rcx), %r9
	movq	8(%rdx), %r8
	cmpq	%r8, %r9
	setg	%al
	je	.L5
	ret
	.p2align 4,,10
.L5:
	movq	(%rdx), %rax
	cmpq	%rax, (%rcx)
	setl	%al
	ret
	.seh_endproc
	.p2align 4,,15
	.def	__tcf_0;	.scl	3;	.type	32;	.endef
	.seh_proc	__tcf_0
__tcf_0:
.LFB9353:
	.seh_endprologue
	leaq	_ZStL8__ioinit(%rip), %rcx
	jmp	_ZNSt8ios_base4InitD1Ev
	.seh_endproc
	.section	.text$_ZSt16__insertion_sortIPxN9__gnu_cxx5__ops15_Iter_comp_iterISt7greaterIxEEEEvT_S7_T0_,"x"
	.linkonce discard
	.p2align 4,,15
	.globl	_ZSt16__insertion_sortIPxN9__gnu_cxx5__ops15_Iter_comp_iterISt7greaterIxEEEEvT_S7_T0_
	.def	_ZSt16__insertion_sortIPxN9__gnu_cxx5__ops15_Iter_comp_iterISt7greaterIxEEEEvT_S7_T0_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt16__insertion_sortIPxN9__gnu_cxx5__ops15_Iter_comp_iterISt7greaterIxEEEEvT_S7_T0_
_ZSt16__insertion_sortIPxN9__gnu_cxx5__ops15_Iter_comp_iterISt7greaterIxEEEEvT_S7_T0_:
.LFB9162:
	pushq	%r12
	.seh_pushreg	%r12
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	cmpq	%rdx, %rcx
	movq	%rcx, %rdi
	je	.L7
	leaq	8(%rcx), %rbx
	cmpq	%rbx, %rdx
	je	.L7
	subq	$16, %rdx
	movl	$8, %r12d
	subq	%rcx, %rdx
	shrq	$3, %rdx
	leaq	16(%rcx,%rdx,8), %rbp
	jmp	.L14
	.p2align 4,,10
.L18:
	cmpq	%rbx, %rdi
	je	.L10
	leaq	(%rdi,%r12), %rcx
	movq	%rbx, %r8
	movq	%rdi, %rdx
	subq	%rdi, %r8
	call	memmove
.L10:
	addq	$8, %rbx
	movq	%rsi, (%rdi)
	cmpq	%rbx, %rbp
	je	.L7
.L14:
	movq	(%rbx), %rsi
	cmpq	(%rdi), %rsi
	jg	.L18
	movq	-8(%rbx), %rdx
	leaq	-8(%rbx), %rax
	cmpq	%rdx, %rsi
	jg	.L13
	jmp	.L19
	.p2align 4,,10
.L16:
	movq	%rcx, %rax
.L13:
	movq	%rdx, 8(%rax)
	movq	-8(%rax), %rdx
	leaq	-8(%rax), %rcx
	cmpq	%rdx, %rsi
	jg	.L16
	movq	%rsi, (%rax)
.L20:
	addq	$8, %rbx
	cmpq	%rbx, %rbp
	jne	.L14
.L7:
	addq	$32, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	ret
	.p2align 4,,10
.L19:
	movq	%rbx, %rax
	movq	%rsi, (%rax)
	jmp	.L20
	.seh_endproc
	.section	.text$_ZSt16__insertion_sortIPxN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_,"x"
	.linkonce discard
	.p2align 4,,15
	.globl	_ZSt16__insertion_sortIPxN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_
	.def	_ZSt16__insertion_sortIPxN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt16__insertion_sortIPxN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_
_ZSt16__insertion_sortIPxN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_:
.LFB9180:
	pushq	%r12
	.seh_pushreg	%r12
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	cmpq	%rdx, %rcx
	movq	%rcx, %rdi
	je	.L21
	leaq	8(%rcx), %rbx
	cmpq	%rbx, %rdx
	je	.L21
	subq	$16, %rdx
	movl	$8, %r12d
	subq	%rcx, %rdx
	shrq	$3, %rdx
	leaq	16(%rcx,%rdx,8), %rbp
	jmp	.L28
	.p2align 4,,10
.L32:
	cmpq	%rbx, %rdi
	je	.L24
	leaq	(%rdi,%r12), %rcx
	movq	%rbx, %r8
	movq	%rdi, %rdx
	subq	%rdi, %r8
	call	memmove
.L24:
	addq	$8, %rbx
	movq	%rsi, (%rdi)
	cmpq	%rbx, %rbp
	je	.L21
.L28:
	movq	(%rbx), %rsi
	cmpq	(%rdi), %rsi
	jl	.L32
	movq	-8(%rbx), %rdx
	leaq	-8(%rbx), %rax
	cmpq	%rdx, %rsi
	jl	.L27
	jmp	.L33
	.p2align 4,,10
.L30:
	movq	%rcx, %rax
.L27:
	movq	%rdx, 8(%rax)
	movq	-8(%rax), %rdx
	leaq	-8(%rax), %rcx
	cmpq	%rdx, %rsi
	jl	.L30
	movq	%rsi, (%rax)
.L34:
	addq	$8, %rbx
	cmpq	%rbx, %rbp
	jne	.L28
.L21:
	addq	$32, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	ret
	.p2align 4,,10
.L33:
	movq	%rbx, %rax
	movq	%rsi, (%rax)
	jmp	.L34
	.seh_endproc
	.section .rdata,"dr"
	.align 8
.LC0:
	.ascii "basic_string::_M_construct null not valid\0"
	.section	.text$_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPcEEvT_S7_St20forward_iterator_tag,"x"
	.linkonce discard
	.align 2
	.p2align 4,,15
	.globl	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPcEEvT_S7_St20forward_iterator_tag
	.def	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPcEEvT_S7_St20forward_iterator_tag;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPcEEvT_S7_St20forward_iterator_tag
_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPcEEvT_S7_St20forward_iterator_tag:
.LFB9183:
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	testq	%rdx, %rdx
	movq	%rcx, %rsi
	movq	%rdx, %rdi
	jne	.L36
	testq	%r8, %r8
	jne	.L51
.L36:
	movq	%r8, %rbx
	subq	%rdi, %rbx
	cmpq	$15, %rbx
	movq	%rbx, 40(%rsp)
	ja	.L52
	cmpq	$1, %rbx
	movq	(%rsi), %rax
	jne	.L39
	movzbl	(%rdi), %edx
	movb	%dl, (%rax)
	movq	40(%rsp), %rbx
	movq	(%rsi), %rax
	movq	%rbx, 8(%rsi)
	movb	$0, (%rax,%rbx)
	addq	$48, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	ret
	.p2align 4,,10
.L39:
	testq	%rbx, %rbx
	jne	.L38
	movq	%rbx, 8(%rsi)
	movb	$0, (%rax,%rbx)
	addq	$48, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	ret
	.p2align 4,,10
.L52:
	leaq	40(%rsp), %rdx
	xorl	%r8d, %r8d
	movq	%rsi, %rcx
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERyy
	movq	40(%rsp), %rdx
	movq	%rax, (%rsi)
	movq	%rdx, 16(%rsi)
.L38:
	movq	%rbx, %r8
	movq	%rdi, %rdx
	movq	%rax, %rcx
	call	memcpy
	movq	40(%rsp), %rbx
	movq	(%rsi), %rax
	movq	%rbx, 8(%rsi)
	movb	$0, (%rax,%rbx)
	addq	$48, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	ret
.L51:
	leaq	.LC0(%rip), %rcx
	call	_ZSt19__throw_logic_errorPKc
	nop
	.seh_endproc
	.section .rdata,"dr"
.LC1:
	.ascii "basic_string::append\0"
.LC2:
	.ascii ".in\0"
.LC3:
	.ascii "r\0"
.LC4:
	.ascii ".out\0"
.LC5:
	.ascii "w\0"
	.text
	.p2align 4,,15
	.globl	_Z9handle_iobNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
	.def	_Z9handle_iobNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z9handle_iobNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
_Z9handle_iobNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE:
.LFB8498:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$72, %rsp
	.seh_stackalloc	72
	.seh_endprologue
	testb	%cl, %cl
	movq	%rdx, %rsi
	jne	.L81
	cmpq	$0, 8(%rsi)
	jne	.L82
.L53:
	addq	$72, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	ret
	.p2align 4,,10
.L81:
	xorl	%ecx, %ecx
.LEHB0:
	call	_ZNSt8ios_base15sync_with_stdioEb
	movq	.refptr._ZSt3cin(%rip), %rax
	cmpq	$0, 8(%rsi)
	movq	$0, 232(%rax)
	je	.L53
.L82:
	movq	__imp___acrt_iob_func(%rip), %rdi
	leaq	32(%rsp), %rbx
	xorl	%ecx, %ecx
	call	*%rdi
	movq	(%rsi), %rdx
	xorl	%r9d, %r9d
	movq	%rbx, %rcx
	movq	8(%rsi), %r8
	movq	%rax, %rbp
	leaq	16(%rbx), %rax
	movq	%rax, 32(%rsp)
	addq	%rdx, %r8
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPcEEvT_S7_St20forward_iterator_tag
.LEHE0:
	movabsq	$9223372036854775807, %rax
	subq	40(%rsp), %rax
	cmpq	$2, %rax
	jbe	.L83
	leaq	.LC2(%rip), %rdx
	movl	$3, %r8d
	movq	%rbx, %rcx
.LEHB1:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_appendEPKcy
.LEHE1:
	movq	32(%rsp), %rcx
	leaq	.LC3(%rip), %rdx
	movq	%rbp, %r8
.LEHB2:
	call	freopen
.LEHE2:
	movq	32(%rsp), %rcx
	leaq	16(%rbx), %rax
	cmpq	%rax, %rcx
	je	.L60
	call	_ZdlPv
.L60:
	movl	$1, %ecx
.LEHB3:
	call	*%rdi
	movq	(%rsi), %rdx
	xorl	%r9d, %r9d
	movq	%rbx, %rcx
	movq	8(%rsi), %r8
	movq	%rax, %rdi
	leaq	16(%rbx), %rax
	movq	%rax, 32(%rsp)
	addq	%rdx, %r8
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPcEEvT_S7_St20forward_iterator_tag
.LEHE3:
	movabsq	$9223372036854775807, %rax
	subq	40(%rsp), %rax
	cmpq	$3, %rax
	jbe	.L84
	leaq	.LC4(%rip), %rdx
	movl	$4, %r8d
	movq	%rbx, %rcx
.LEHB4:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_appendEPKcy
.LEHE4:
	movq	32(%rsp), %rcx
	leaq	.LC5(%rip), %rdx
	movq	%rdi, %r8
.LEHB5:
	call	freopen
.LEHE5:
	movq	32(%rsp), %rcx
	addq	$16, %rbx
	cmpq	%rbx, %rcx
	je	.L53
	call	_ZdlPv
	nop
	addq	$72, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	ret
.L83:
	leaq	.LC1(%rip), %rcx
.LEHB6:
	call	_ZSt20__throw_length_errorPKc
.LEHE6:
.L84:
	leaq	.LC1(%rip), %rcx
.LEHB7:
	call	_ZSt20__throw_length_errorPKc
.LEHE7:
.L71:
.L78:
	movq	32(%rsp), %rcx
	addq	$16, %rbx
	movq	%rax, %rsi
	cmpq	%rbx, %rcx
	je	.L69
	call	_ZdlPv
.L69:
	movq	%rsi, %rcx
.LEHB8:
	call	_Unwind_Resume
.LEHE8:
.L72:
	jmp	.L78
.L70:
	jmp	.L78
.L73:
	jmp	.L78
	.def	__gxx_personality_seh0;	.scl	2;	.type	32;	.endef
	.seh_handler	__gxx_personality_seh0, @unwind, @except
	.seh_handlerdata
.LLSDA8498:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE8498-.LLSDACSB8498
.LLSDACSB8498:
	.uleb128 .LEHB0-.LFB8498
	.uleb128 .LEHE0-.LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB1-.LFB8498
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L72-.LFB8498
	.uleb128 0
	.uleb128 .LEHB2-.LFB8498
	.uleb128 .LEHE2-.LEHB2
	.uleb128 .L70-.LFB8498
	.uleb128 0
	.uleb128 .LEHB3-.LFB8498
	.uleb128 .LEHE3-.LEHB3
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB4-.LFB8498
	.uleb128 .LEHE4-.LEHB4
	.uleb128 .L73-.LFB8498
	.uleb128 0
	.uleb128 .LEHB5-.LFB8498
	.uleb128 .LEHE5-.LEHB5
	.uleb128 .L71-.LFB8498
	.uleb128 0
	.uleb128 .LEHB6-.LFB8498
	.uleb128 .LEHE6-.LEHB6
	.uleb128 .L72-.LFB8498
	.uleb128 0
	.uleb128 .LEHB7-.LFB8498
	.uleb128 .LEHE7-.LEHB7
	.uleb128 .L73-.LFB8498
	.uleb128 0
	.uleb128 .LEHB8-.LFB8498
	.uleb128 .LEHE8-.LEHB8
	.uleb128 0
	.uleb128 0
.LLSDACSE8498:
	.text
	.seh_endproc
	.section	.text$_ZSt25__unguarded_linear_insertIN9__gnu_cxx17__normal_iteratorIPSt4pairIxxESt6vectorIS3_SaIS3_EEEENS0_5__ops14_Val_comp_iterIPFbRKS3_SC_EEEEvT_T0_,"x"
	.linkonce discard
	.p2align 4,,15
	.globl	_ZSt25__unguarded_linear_insertIN9__gnu_cxx17__normal_iteratorIPSt4pairIxxESt6vectorIS3_SaIS3_EEEENS0_5__ops14_Val_comp_iterIPFbRKS3_SC_EEEEvT_T0_
	.def	_ZSt25__unguarded_linear_insertIN9__gnu_cxx17__normal_iteratorIPSt4pairIxxESt6vectorIS3_SaIS3_EEEENS0_5__ops14_Val_comp_iterIPFbRKS3_SC_EEEEvT_T0_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt25__unguarded_linear_insertIN9__gnu_cxx17__normal_iteratorIPSt4pairIxxESt6vectorIS3_SaIS3_EEEENS0_5__ops14_Val_comp_iterIPFbRKS3_SC_EEEEvT_T0_
_ZSt25__unguarded_linear_insertIN9__gnu_cxx17__normal_iteratorIPSt4pairIxxESt6vectorIS3_SaIS3_EEEENS0_5__ops14_Val_comp_iterIPFbRKS3_SC_EEEEvT_T0_:
.LFB9256:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$56, %rsp
	.seh_stackalloc	56
	.seh_endprologue
	movdqu	(%rcx), %xmm0
	leaq	-16(%rcx), %rbx
	movq	%rdx, %rbp
	movaps	%xmm0, 32(%rsp)
	leaq	32(%rsp), %rdi
	jmp	.L87
	.p2align 4,,10
.L88:
	movq	(%rbx), %rax
	subq	$16, %rbx
	movq	%rax, 32(%rbx)
	movq	24(%rbx), %rax
	movq	%rax, 40(%rbx)
.L87:
	leaq	16(%rbx), %rsi
	movq	%rbx, %rdx
	movq	%rdi, %rcx
	call	*%rbp
	testb	%al, %al
	jne	.L88
	movq	32(%rsp), %rax
	movq	%rax, (%rsi)
	movq	40(%rsp), %rax
	movq	%rax, 8(%rsi)
	addq	$56, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZSt16__insertion_sortIN9__gnu_cxx17__normal_iteratorIPSt4pairIxxESt6vectorIS3_SaIS3_EEEENS0_5__ops15_Iter_comp_iterIPFbRKS3_SC_EEEEvT_SG_T0_,"x"
	.linkonce discard
	.p2align 4,,15
	.globl	_ZSt16__insertion_sortIN9__gnu_cxx17__normal_iteratorIPSt4pairIxxESt6vectorIS3_SaIS3_EEEENS0_5__ops15_Iter_comp_iterIPFbRKS3_SC_EEEEvT_SG_T0_
	.def	_ZSt16__insertion_sortIN9__gnu_cxx17__normal_iteratorIPSt4pairIxxESt6vectorIS3_SaIS3_EEEENS0_5__ops15_Iter_comp_iterIPFbRKS3_SC_EEEEvT_SG_T0_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt16__insertion_sortIN9__gnu_cxx17__normal_iteratorIPSt4pairIxxESt6vectorIS3_SaIS3_EEEENS0_5__ops15_Iter_comp_iterIPFbRKS3_SC_EEEEvT_SG_T0_
_ZSt16__insertion_sortIN9__gnu_cxx17__normal_iteratorIPSt4pairIxxESt6vectorIS3_SaIS3_EEEENS0_5__ops15_Iter_comp_iterIPFbRKS3_SC_EEEEvT_SG_T0_:
.LFB9171:
	pushq	%r12
	.seh_pushreg	%r12
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	cmpq	%rdx, %rcx
	movq	%rcx, %rdi
	movq	%rdx, %r12
	movq	%r8, %rbp
	je	.L89
	leaq	16(%rcx), %rsi
	cmpq	%rdx, %rsi
	jne	.L96
	jmp	.L89
	.p2align 4,,10
.L92:
	movq	%rsi, %rcx
	movq	%rbp, %rdx
	addq	$16, %rsi
	call	_ZSt25__unguarded_linear_insertIN9__gnu_cxx17__normal_iteratorIPSt4pairIxxESt6vectorIS3_SaIS3_EEEENS0_5__ops14_Val_comp_iterIPFbRKS3_SC_EEEEvT_T0_
	cmpq	%rsi, %r12
	je	.L89
.L96:
	movq	%rdi, %rdx
	movq	%rsi, %rcx
	movq	%rsi, %rbx
	call	*%rbp
	testb	%al, %al
	je	.L92
	movq	%rsi, %rdx
	movq	(%rsi), %rcx
	subq	%rdi, %rdx
	movq	8(%rsi), %r8
	movq	%rdx, %rax
	sarq	$4, %rax
	testq	%rdx, %rdx
	jle	.L95
	.p2align 4,,10
.L93:
	subq	$16, %rbx
	movq	(%rbx), %rdx
	subq	$1, %rax
	movq	%rdx, 16(%rbx)
	movq	8(%rbx), %rdx
	movq	%rdx, 24(%rbx)
	jne	.L93
.L95:
	addq	$16, %rsi
	movq	%rcx, (%rdi)
	cmpq	%rsi, %r12
	movq	%r8, 8(%rdi)
	jne	.L96
.L89:
	addq	$32, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	ret
	.seh_endproc
	.section	.text$_ZSt13__adjust_heapIPxxxN9__gnu_cxx5__ops15_Iter_comp_iterISt7greaterIxEEEEvT_T0_S8_T1_T2_,"x"
	.linkonce discard
	.p2align 4,,15
	.globl	_ZSt13__adjust_heapIPxxxN9__gnu_cxx5__ops15_Iter_comp_iterISt7greaterIxEEEEvT_T0_S8_T1_T2_
	.def	_ZSt13__adjust_heapIPxxxN9__gnu_cxx5__ops15_Iter_comp_iterISt7greaterIxEEEEvT_T0_S8_T1_T2_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt13__adjust_heapIPxxxN9__gnu_cxx5__ops15_Iter_comp_iterISt7greaterIxEEEEvT_T0_S8_T1_T2_
_ZSt13__adjust_heapIPxxxN9__gnu_cxx5__ops15_Iter_comp_iterISt7greaterIxEEEEvT_T0_S8_T1_T2_:
.LFB9317:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	.seh_endprologue
	leaq	-1(%r8), %rax
	movq	%r8, %rbp
	movq	%rax, %rdi
	andl	$1, %ebp
	shrq	$63, %rdi
	addq	%rax, %rdi
	sarq	%rdi
	cmpq	%rdi, %rdx
	jge	.L103
	movq	%rdx, %rsi
	.p2align 4,,10
.L105:
	leaq	1(%rsi), %rax
	leaq	(%rax,%rax), %r10
	salq	$4, %rax
	leaq	(%rcx,%rax), %r11
	movq	(%r11), %rbx
	cmpq	-8(%rcx,%rax), %rbx
	jle	.L104
	subq	$1, %r10
	leaq	(%rcx,%r10,8), %r11
	movq	(%r11), %rbx
.L104:
	cmpq	%rdi, %r10
	movq	%rbx, (%rcx,%rsi,8)
	movq	%r10, %rsi
	jl	.L105
	testq	%rbp, %rbp
	je	.L110
.L106:
	leaq	-1(%r10), %rax
	movq	%rax, %r8
	shrq	$63, %r8
	addq	%rax, %r8
	sarq	%r8
	cmpq	%rdx, %r10
	jle	.L107
	movq	(%rcx,%r8,8), %rbx
	cmpq	%rbx, %r9
	jl	.L108
	jmp	.L107
	.p2align 4,,10
.L109:
	movq	(%rcx,%rax,8), %rbx
	movq	%r8, %r10
	movq	%rax, %r8
	cmpq	%rbx, %r9
	jge	.L107
.L108:
	movq	%rbx, (%rcx,%r10,8)
	leaq	-1(%r8), %r10
	leaq	(%rcx,%r8,8), %r11
	movq	%r10, %rax
	shrq	$63, %rax
	addq	%r10, %rax
	sarq	%rax
	cmpq	%r8, %rdx
	jl	.L109
.L107:
	movq	%r9, (%r11)
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	ret
	.p2align 4,,10
.L103:
	leaq	(%rcx,%rdx,8), %r11
	testq	%rbp, %rbp
	jne	.L107
	movq	%rdx, %r10
	.p2align 4,,10
.L110:
	leaq	-2(%r8), %rax
	movq	%rax, %r8
	shrq	$63, %r8
	addq	%rax, %r8
	sarq	%r8
	cmpq	%r10, %r8
	jne	.L106
	leaq	2(%r10,%r10), %r10
	movq	-8(%rcx,%r10,8), %rax
	subq	$1, %r10
	movq	%rax, (%r11)
	leaq	(%rcx,%r10,8), %r11
	jmp	.L106
	.seh_endproc
	.section	.text$_ZSt16__introsort_loopIPxxN9__gnu_cxx5__ops15_Iter_comp_iterISt7greaterIxEEEEvT_S7_T0_T1_,"x"
	.linkonce discard
	.p2align 4,,15
	.globl	_ZSt16__introsort_loopIPxxN9__gnu_cxx5__ops15_Iter_comp_iterISt7greaterIxEEEEvT_S7_T0_T1_
	.def	_ZSt16__introsort_loopIPxxN9__gnu_cxx5__ops15_Iter_comp_iterISt7greaterIxEEEEvT_S7_T0_T1_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt16__introsort_loopIPxxN9__gnu_cxx5__ops15_Iter_comp_iterISt7greaterIxEEEEvT_S7_T0_T1_
_ZSt16__introsort_loopIPxxN9__gnu_cxx5__ops15_Iter_comp_iterISt7greaterIxEEEEvT_S7_T0_T1_:
.LFB9091:
	pushq	%r14
	.seh_pushreg	%r14
	pushq	%r13
	.seh_pushreg	%r13
	pushq	%r12
	.seh_pushreg	%r12
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%r8, %r14
	movq	%rdx, %r8
	movq	%rcx, %rbx
	subq	%rcx, %r8
	movl	%r9d, %ebp
	cmpq	$128, %r8
	jle	.L115
	leaq	8(%rcx), %r13
	testq	%r14, %r14
	leaq	16(%rcx), %r12
	je	.L144
.L119:
	sarq	$4, %r8
	movq	8(%rbx), %rcx
	subq	$1, %r14
	leaq	(%rbx,%r8,8), %r10
	movq	(%rbx), %r9
	movq	(%r10), %rax
	movq	-8(%rdx), %r8
	cmpq	%rax, %rcx
	jle	.L124
	cmpq	%r8, %rax
	jg	.L129
	cmpq	%r8, %rcx
	jg	.L142
.L143:
	movq	%rcx, (%rbx)
	movq	%r9, 8(%rbx)
	movq	-8(%rdx), %r8
.L126:
	movq	%r12, %r10
	movq	%r13, %rsi
	movq	%rdx, %rax
	.p2align 4,,10
.L130:
	cmpq	%rcx, %r9
	movq	%rsi, %rdi
	jg	.L131
	subq	$8, %rax
	cmpq	%r8, %rcx
	jle	.L132
	.p2align 4,,10
.L133:
	subq	$8, %rax
	movq	(%rax), %r8
	cmpq	%rcx, %r8
	jl	.L133
.L132:
	cmpq	%rax, %rsi
	jnb	.L145
	movq	%r8, (%rsi)
	movq	-8(%rax), %r8
	movq	%r9, (%rax)
	movq	(%rbx), %rcx
.L131:
	movq	(%r10), %r9
	addq	$8, %rsi
	addq	$8, %r10
	jmp	.L130
	.p2align 4,,10
.L124:
	cmpq	%r8, %rcx
	jg	.L143
	cmpq	%r8, %rax
	jle	.L129
.L142:
	movq	%r8, (%rbx)
	movq	%r9, %r8
	movq	%r9, -8(%rdx)
	movq	(%rbx), %rcx
	movq	8(%rbx), %r9
	jmp	.L126
	.p2align 4,,10
.L145:
	movq	%r14, %r8
	movl	%ebp, %r9d
	movq	%rsi, %rcx
	call	_ZSt16__introsort_loopIPxxN9__gnu_cxx5__ops15_Iter_comp_iterISt7greaterIxEEEEvT_S7_T0_T1_
	movq	%rsi, %r8
	subq	%rbx, %r8
	cmpq	$128, %r8
	jle	.L115
	testq	%r14, %r14
	movq	%rsi, %rdx
	jne	.L119
.L117:
	movq	%r8, %rsi
	movq	%rbx, %rcx
	sarq	$3, %rsi
	leaq	-2(%rsi), %rbp
	movq	%rsi, %r8
	sarq	%rbp
	movq	(%rbx,%rbp,8), %r9
	movq	%rbp, %rdx
	call	_ZSt13__adjust_heapIPxxxN9__gnu_cxx5__ops15_Iter_comp_iterISt7greaterIxEEEEvT_T0_S8_T1_T2_
.L120:
	subq	$1, %rbp
	movq	%rsi, %r8
	movq	%rbx, %rcx
	movq	(%rbx,%rbp,8), %r9
	movq	%rbp, %rdx
	call	_ZSt13__adjust_heapIPxxxN9__gnu_cxx5__ops15_Iter_comp_iterISt7greaterIxEEEEvT_T0_S8_T1_T2_
	testq	%rbp, %rbp
	jne	.L120
	.p2align 4,,10
.L121:
	subq	$8, %rdi
	movq	(%rbx), %rax
	xorl	%edx, %edx
	movq	%rbx, %rcx
	movq	(%rdi), %r9
	movq	%rdi, %rsi
	subq	%rbx, %rsi
	movq	%rsi, %r8
	sarq	$3, %r8
	movq	%rax, (%rdi)
	call	_ZSt13__adjust_heapIPxxxN9__gnu_cxx5__ops15_Iter_comp_iterISt7greaterIxEEEEvT_T0_S8_T1_T2_
	cmpq	$8, %rsi
	jg	.L121
.L115:
	addq	$32, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	popq	%r14
	ret
	.p2align 4,,10
.L129:
	movq	%rax, (%rbx)
	movq	%r9, (%r10)
	movq	8(%rbx), %r9
	movq	(%rbx), %rcx
	movq	-8(%rdx), %r8
	jmp	.L126
	.p2align 4,,10
.L144:
	movq	%rdx, %rdi
	jmp	.L117
	.seh_endproc
	.section	.text$_ZSt13__adjust_heapIN9__gnu_cxx17__normal_iteratorIPSt4pairIxxESt6vectorIS3_SaIS3_EEEExS3_NS0_5__ops15_Iter_comp_iterIPFbRKS3_SC_EEEEvT_T0_SH_T1_T2_,"x"
	.linkonce discard
	.p2align 4,,15
	.globl	_ZSt13__adjust_heapIN9__gnu_cxx17__normal_iteratorIPSt4pairIxxESt6vectorIS3_SaIS3_EEEExS3_NS0_5__ops15_Iter_comp_iterIPFbRKS3_SC_EEEEvT_T0_SH_T1_T2_
	.def	_ZSt13__adjust_heapIN9__gnu_cxx17__normal_iteratorIPSt4pairIxxESt6vectorIS3_SaIS3_EEEExS3_NS0_5__ops15_Iter_comp_iterIPFbRKS3_SC_EEEEvT_T0_SH_T1_T2_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt13__adjust_heapIN9__gnu_cxx17__normal_iteratorIPSt4pairIxxESt6vectorIS3_SaIS3_EEEExS3_NS0_5__ops15_Iter_comp_iterIPFbRKS3_SC_EEEEvT_T0_SH_T1_T2_
_ZSt13__adjust_heapIN9__gnu_cxx17__normal_iteratorIPSt4pairIxxESt6vectorIS3_SaIS3_EEEExS3_NS0_5__ops15_Iter_comp_iterIPFbRKS3_SC_EEEEvT_T0_SH_T1_T2_:
.LFB9321:
	pushq	%r15
	.seh_pushreg	%r15
	pushq	%r14
	.seh_pushreg	%r14
	pushq	%r13
	.seh_pushreg	%r13
	pushq	%r12
	.seh_pushreg	%r12
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$88, %rsp
	.seh_stackalloc	88
	movaps	%xmm7, 64(%rsp)
	.seh_savexmm	%xmm7, 64
	.seh_endprologue
	movdqu	(%r9), %xmm7
	movq	192(%rsp), %rbp
	movq	%r8, %rax
	movq	%rcx, %rdi
	movq	%r8, %rcx
	movq	%r8, 176(%rsp)
	subq	$1, %rax
	andl	$1, %ecx
	movq	%rdx, %r13
	movq	%rax, %r12
	movq	%rcx, 40(%rsp)
	shrq	$63, %r12
	addq	%rax, %r12
	movq	%r12, %rax
	sarq	%rax
	cmpq	%rax, %rdx
	movq	%rax, 32(%rsp)
	jge	.L147
	movq	%rdx, %rsi
	.p2align 4,,10
.L149:
	leaq	1(%rsi), %rbx
	leaq	(%rbx,%rbx), %r15
	salq	$5, %rbx
	leaq	-1(%r15), %r14
	addq	%rdi, %rbx
	movq	%r14, %r9
	movq	%rbx, %rcx
	salq	$4, %r9
	leaq	(%rdi,%r9), %r12
	movq	%r12, %rdx
	call	*%rbp
	testb	%al, %al
	cmovne	%r12, %rbx
	cmovne	%r14, %r15
	salq	$4, %rsi
	movq	(%rbx), %rax
	addq	%rdi, %rsi
	cmpq	32(%rsp), %r15
	movq	%rax, (%rsi)
	movq	8(%rbx), %rax
	movq	%rax, 8(%rsi)
	movq	%r15, %rsi
	jl	.L149
	cmpq	$0, 40(%rsp)
	je	.L153
.L150:
	leaq	-1(%r15), %rax
	movaps	%xmm7, 48(%rsp)
	movq	%rax, %r14
	shrq	$63, %r14
	addq	%rax, %r14
	sarq	%r14
	cmpq	%r13, %r15
	jle	.L151
	leaq	48(%rsp), %r12
	jmp	.L152
	.p2align 4,,10
.L166:
	movq	(%rsi), %rax
	leaq	-1(%r14), %rdx
	movq	%r14, %r15
	movq	%rax, (%rbx)
	movq	8(%rsi), %rax
	movq	%rax, 8(%rbx)
	movq	%rdx, %rax
	shrq	$63, %rax
	addq	%rdx, %rax
	sarq	%rax
	cmpq	%r14, %r13
	jge	.L165
	movq	%rax, %r14
.L152:
	movq	%r14, %rsi
	movq	%r12, %rdx
	salq	$4, %rsi
	addq	%rdi, %rsi
	movq	%rsi, %rcx
	call	*%rbp
	movq	%r15, %r8
	salq	$4, %r8
	testb	%al, %al
	leaq	(%rdi,%r8), %rbx
	jne	.L166
.L151:
	movq	48(%rsp), %rax
	movq	%rax, (%rbx)
	movq	56(%rsp), %rax
	movq	%rax, 8(%rbx)
	movaps	64(%rsp), %xmm7
	addq	$88, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	ret
	.p2align 4,,10
.L147:
	movq	%rdx, %rbx
	salq	$4, %rbx
	addq	%rdi, %rbx
	cmpq	$0, 40(%rsp)
	jne	.L167
	movq	%r13, %r15
	.p2align 4,,10
.L153:
	movq	176(%rsp), %rax
	subq	$2, %rax
	movq	%rax, %r14
	shrq	$63, %r14
	addq	%rax, %r14
	sarq	%r14
	cmpq	%r15, %r14
	jne	.L150
	leaq	1(%r15,%r15), %r15
	movq	%r15, %rax
	salq	$4, %rax
	addq	%rdi, %rax
	movq	(%rax), %rdx
	movq	%rdx, (%rbx)
	movq	8(%rax), %rdx
	movq	%rdx, 8(%rbx)
	movq	%rax, %rbx
	jmp	.L150
	.p2align 4,,10
.L165:
	movq	%rsi, %rbx
	jmp	.L151
.L167:
	movaps	%xmm7, 48(%rsp)
	jmp	.L151
	.seh_endproc
	.section	.text$_ZSt13__heap_selectIN9__gnu_cxx17__normal_iteratorIPSt4pairIxxESt6vectorIS3_SaIS3_EEEENS0_5__ops15_Iter_comp_iterIPFbRKS3_SC_EEEEvT_SG_SG_T0_,"x"
	.linkonce discard
	.p2align 4,,15
	.globl	_ZSt13__heap_selectIN9__gnu_cxx17__normal_iteratorIPSt4pairIxxESt6vectorIS3_SaIS3_EEEENS0_5__ops15_Iter_comp_iterIPFbRKS3_SC_EEEEvT_SG_SG_T0_
	.def	_ZSt13__heap_selectIN9__gnu_cxx17__normal_iteratorIPSt4pairIxxESt6vectorIS3_SaIS3_EEEENS0_5__ops15_Iter_comp_iterIPFbRKS3_SC_EEEEvT_SG_SG_T0_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt13__heap_selectIN9__gnu_cxx17__normal_iteratorIPSt4pairIxxESt6vectorIS3_SaIS3_EEEENS0_5__ops15_Iter_comp_iterIPFbRKS3_SC_EEEEvT_SG_SG_T0_
_ZSt13__heap_selectIN9__gnu_cxx17__normal_iteratorIPSt4pairIxxESt6vectorIS3_SaIS3_EEEENS0_5__ops15_Iter_comp_iterIPFbRKS3_SC_EEEEvT_SG_SG_T0_:
.LFB9242:
	pushq	%r14
	.seh_pushreg	%r14
	pushq	%r13
	.seh_pushreg	%r13
	pushq	%r12
	.seh_pushreg	%r12
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$64, %rsp
	.seh_stackalloc	64
	.seh_endprologue
	movq	%rdx, %rax
	movq	%rcx, %rsi
	movq	%rdx, %rbx
	subq	%rcx, %rax
	movq	%r8, %r12
	movq	%r9, %rbp
	movq	%rax, %r13
	sarq	$4, %r13
	cmpq	$16, %rax
	jle	.L169
	leaq	-2(%r13), %rax
	leaq	48(%rsp), %r14
	movq	%rax, %rdi
	shrq	$63, %rdi
	addq	%rax, %rdi
	sarq	%rdi
	jmp	.L171
	.p2align 4,,10
.L181:
	subq	$1, %rdi
.L171:
	movq	%rdi, %rax
	movq	%r14, %r9
	movq	%r13, %r8
	salq	$4, %rax
	movq	%rdi, %rdx
	movq	%rsi, %rcx
	movdqu	(%rsi,%rax), %xmm0
	movq	%rbp, 32(%rsp)
	movaps	%xmm0, 48(%rsp)
	call	_ZSt13__adjust_heapIN9__gnu_cxx17__normal_iteratorIPSt4pairIxxESt6vectorIS3_SaIS3_EEEExS3_NS0_5__ops15_Iter_comp_iterIPFbRKS3_SC_EEEEvT_T0_SH_T1_T2_
	testq	%rdi, %rdi
	jne	.L181
.L169:
	leaq	48(%rsp), %rdi
	cmpq	%rbx, %r12
	ja	.L174
	jmp	.L168
	.p2align 4,,10
.L173:
	addq	$16, %rbx
	cmpq	%rbx, %r12
	jbe	.L168
.L174:
	movq	%rsi, %rdx
	movq	%rbx, %rcx
	call	*%rbp
	testb	%al, %al
	je	.L173
	movq	(%rsi), %rcx
	movq	%rdi, %r9
	movq	%r13, %r8
	addq	$16, %rbx
	movq	-8(%rbx), %rdx
	movq	-16(%rbx), %rax
	movq	%rcx, -16(%rbx)
	movq	8(%rsi), %rcx
	movq	%rcx, -8(%rbx)
	movq	%rsi, %rcx
	movq	%rdx, 56(%rsp)
	xorl	%edx, %edx
	movq	%rbp, 32(%rsp)
	movq	%rax, 48(%rsp)
	call	_ZSt13__adjust_heapIN9__gnu_cxx17__normal_iteratorIPSt4pairIxxESt6vectorIS3_SaIS3_EEEExS3_NS0_5__ops15_Iter_comp_iterIPFbRKS3_SC_EEEEvT_T0_SH_T1_T2_
	cmpq	%rbx, %r12
	ja	.L174
.L168:
	addq	$64, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	popq	%r14
	ret
	.seh_endproc
	.section	.text$_ZSt16__introsort_loopIN9__gnu_cxx17__normal_iteratorIPSt4pairIxxESt6vectorIS3_SaIS3_EEEExNS0_5__ops15_Iter_comp_iterIPFbRKS3_SC_EEEEvT_SG_T0_T1_,"x"
	.linkonce discard
	.p2align 4,,15
	.globl	_ZSt16__introsort_loopIN9__gnu_cxx17__normal_iteratorIPSt4pairIxxESt6vectorIS3_SaIS3_EEEExNS0_5__ops15_Iter_comp_iterIPFbRKS3_SC_EEEEvT_SG_T0_T1_
	.def	_ZSt16__introsort_loopIN9__gnu_cxx17__normal_iteratorIPSt4pairIxxESt6vectorIS3_SaIS3_EEEExNS0_5__ops15_Iter_comp_iterIPFbRKS3_SC_EEEEvT_SG_T0_T1_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt16__introsort_loopIN9__gnu_cxx17__normal_iteratorIPSt4pairIxxESt6vectorIS3_SaIS3_EEEExNS0_5__ops15_Iter_comp_iterIPFbRKS3_SC_EEEEvT_SG_T0_T1_
_ZSt16__introsort_loopIN9__gnu_cxx17__normal_iteratorIPSt4pairIxxESt6vectorIS3_SaIS3_EEEExNS0_5__ops15_Iter_comp_iterIPFbRKS3_SC_EEEEvT_SG_T0_T1_:
.LFB9095:
	pushq	%r15
	.seh_pushreg	%r15
	pushq	%r14
	.seh_pushreg	%r14
	pushq	%r13
	.seh_pushreg	%r13
	pushq	%r12
	.seh_pushreg	%r12
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$88, %rsp
	.seh_stackalloc	88
	.seh_endprologue
	movq	%rdx, %rax
	movq	%rcx, %rbx
	movq	%r8, %r12
	subq	%rcx, %rax
	movq	%r9, %rdi
	movq	%rdx, %rbp
	cmpq	$256, %rax
	jle	.L182
	leaq	16(%rcx), %r13
	testq	%r8, %r8
	je	.L209
.L186:
	movq	%rbp, %rsi
	movq	%r13, %rcx
	subq	$1, %r12
	leaq	-16(%rbp), %r14
	subq	%rbx, %rsi
	movq	%rsi, %rax
	sarq	$4, %rax
	movq	%rax, %rsi
	shrq	$63, %rsi
	addq	%rax, %rsi
	sarq	%rsi
	salq	$4, %rsi
	addq	%rbx, %rsi
	movq	%rsi, %rdx
	call	*%rdi
	movq	%r14, %rdx
	testb	%al, %al
	je	.L189
	movq	%rsi, %rcx
	call	*%rdi
	testb	%al, %al
	je	.L190
	movq	(%rbx), %rax
.L194:
	movq	(%rsi), %rdx
	movq	%rdx, (%rbx)
	movq	8(%rsi), %rdx
	movq	%rax, (%rsi)
	movq	8(%rbx), %rax
	movq	%rdx, 8(%rbx)
	movq	%rax, 8(%rsi)
.L191:
	movq	%r13, %rsi
	movq	%rbp, %r14
	.p2align 4,,10
.L195:
	movq	%rsi, 56(%rsp)
	movq	%rbx, %rdx
	movq	%rsi, %rcx
	call	*%rdi
	testb	%al, %al
	jne	.L196
	leaq	-16(%r14), %r15
	.p2align 4,,10
.L197:
	movq	%r15, %rdx
	movq	%rbx, %rcx
	movq	%r15, %r14
	call	*%rdi
	subq	$16, %r15
	testb	%al, %al
	jne	.L197
	cmpq	%r14, %rsi
	jnb	.L210
	movq	(%rsi), %rax
	movq	(%r14), %rdx
	movq	%rdx, (%rsi)
	movq	8(%r14), %rdx
	movq	%rax, (%r14)
	movq	8(%rsi), %rax
	movq	%rdx, 8(%rsi)
	movq	%rax, 8(%r14)
.L196:
	addq	$16, %rsi
	jmp	.L195
	.p2align 4,,10
.L210:
	movq	%rdi, %r9
	movq	%r12, %r8
	movq	%rbp, %rdx
	movq	%rsi, %rcx
	call	_ZSt16__introsort_loopIN9__gnu_cxx17__normal_iteratorIPSt4pairIxxESt6vectorIS3_SaIS3_EEEExNS0_5__ops15_Iter_comp_iterIPFbRKS3_SC_EEEEvT_SG_T0_T1_
	movq	%rsi, %rax
	subq	%rbx, %rax
	cmpq	$256, %rax
	jle	.L182
	testq	%r12, %r12
	movq	%rsi, %rbp
	jne	.L186
.L184:
	movq	56(%rsp), %r15
	leaq	64(%rsp), %r12
	movq	%rdi, %r9
	movq	%rbx, %rcx
	movq	%r15, %r8
	movq	%r15, %rdx
	subq	$16, %r15
	call	_ZSt13__heap_selectIN9__gnu_cxx17__normal_iteratorIPSt4pairIxxESt6vectorIS3_SaIS3_EEEENS0_5__ops15_Iter_comp_iterIPFbRKS3_SC_EEEEvT_SG_SG_T0_
	.p2align 4,,10
.L187:
	movq	(%rbx), %rcx
	movq	%r15, %rbp
	movq	%r12, %r9
	subq	$16, %r15
	movq	24(%r15), %rdx
	subq	%rbx, %rbp
	movq	16(%r15), %rax
	movq	%rbp, %r8
	sarq	$4, %r8
	movq	%rcx, 16(%r15)
	movq	8(%rbx), %rcx
	movq	%rcx, 24(%r15)
	movq	%rbx, %rcx
	movq	%rdx, 72(%rsp)
	xorl	%edx, %edx
	movq	%rdi, 32(%rsp)
	movq	%rax, 64(%rsp)
	call	_ZSt13__adjust_heapIN9__gnu_cxx17__normal_iteratorIPSt4pairIxxESt6vectorIS3_SaIS3_EEEExS3_NS0_5__ops15_Iter_comp_iterIPFbRKS3_SC_EEEEvT_T0_SH_T1_T2_
	cmpq	$16, %rbp
	jg	.L187
.L182:
	addq	$88, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	ret
	.p2align 4,,10
.L189:
	movq	%r13, %rcx
	call	*%rdi
	testb	%al, %al
	je	.L193
	movq	(%rbx), %rax
.L208:
	movq	16(%rbx), %rdx
	movq	%rax, 16(%rbx)
	movq	8(%rbx), %rax
	movq	%rdx, (%rbx)
	movq	24(%rbx), %rdx
	movq	%rax, 24(%rbx)
	movq	%rdx, 8(%rbx)
	jmp	.L191
	.p2align 4,,10
.L190:
	movq	%r14, %rdx
	movq	%r13, %rcx
	call	*%rdi
	testb	%al, %al
	movq	(%rbx), %rax
	je	.L208
.L207:
	movq	-16(%rbp), %rdx
	movq	%rdx, (%rbx)
	movq	-8(%rbp), %rdx
	movq	%rax, -16(%rbp)
	movq	8(%rbx), %rax
	movq	%rdx, 8(%rbx)
	movq	%rax, -8(%rbp)
	jmp	.L191
	.p2align 4,,10
.L193:
	movq	%r14, %rdx
	movq	%rsi, %rcx
	call	*%rdi
	testb	%al, %al
	movq	(%rbx), %rax
	je	.L194
	jmp	.L207
	.p2align 4,,10
.L209:
	movq	%rdx, 56(%rsp)
	jmp	.L184
	.seh_endproc
	.section	.text$_ZSt13__adjust_heapIPxxxN9__gnu_cxx5__ops15_Iter_less_iterEEvT_T0_S5_T1_T2_,"x"
	.linkonce discard
	.p2align 4,,15
	.globl	_ZSt13__adjust_heapIPxxxN9__gnu_cxx5__ops15_Iter_less_iterEEvT_T0_S5_T1_T2_
	.def	_ZSt13__adjust_heapIPxxxN9__gnu_cxx5__ops15_Iter_less_iterEEvT_T0_S5_T1_T2_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZSt13__adjust_heapIPxxxN9__gnu_cxx5__ops15_Iter_less_iterEEvT_T0_S5_T1_T2_
_ZSt13__adjust_heapIPxxxN9__gnu_cxx5__ops15_Iter_less_iterEEvT_T0_S5_T1_T2_:
.LFB9325:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	.seh_endprologue
	leaq	-1(%r8), %rax
	movq	%r8, %rbp
	movq	%rax, %rdi
	andl	$1, %ebp
	shrq	$63, %rdi
	addq	%rax, %rdi
	sarq	%rdi
	cmpq	%rdi, %rdx
	jge	.L212
	movq	%rdx, %rsi
	.p2align 4,,10
.L214:
	leaq	1(%rsi), %rax
	leaq	(%rax,%rax), %r10
	salq	$4, %rax
	leaq	(%rcx,%rax), %r11
	movq	(%r11), %rbx
	cmpq	-8(%rcx,%rax), %rbx
	jge	.L213
	subq	$1, %r10
	leaq	(%rcx,%r10,8), %r11
	movq	(%r11), %rbx
.L213:
	cmpq	%rdi, %r10
	movq	%rbx, (%rcx,%rsi,8)
	movq	%r10, %rsi
	jl	.L214
	testq	%rbp, %rbp
	je	.L219
.L215:
	leaq	-1(%r10), %rax
	movq	%rax, %r8
	shrq	$63, %r8
	addq	%rax, %r8
	sarq	%r8
	cmpq	%rdx, %r10
	jle	.L216
	movq	(%rcx,%r8,8), %rbx
	cmpq	%rbx, %r9
	jg	.L217
	jmp	.L216
	.p2align 4,,10
.L218:
	movq	(%rcx,%rax,8), %rbx
	movq	%r8, %r10
	movq	%rax, %r8
	cmpq	%rbx, %r9
	jle	.L216
.L217:
	movq	%rbx, (%rcx,%r10,8)
	leaq	-1(%r8), %r10
	leaq	(%rcx,%r8,8), %r11
	movq	%r10, %rax
	shrq	$63, %rax
	addq	%r10, %rax
	sarq	%rax
	cmpq	%r8, %rdx
	jl	.L218
.L216:
	movq	%r9, (%r11)
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	ret
	.p2align 4,,10
.L212:
	leaq	(%rcx,%rdx,8), %r11
	testq	%rbp, %rbp
	jne	.L216
	movq	%rdx, %r10
	.p2align 4,,10
.L219:
	leaq	-2(%r8), %rax
	movq	%rax, %r8
	shrq	$63, %r8
	addq	%rax, %r8
	sarq	%r8
	cmpq	%r10, %r8
	jne	.L215
	leaq	2(%r10,%r10), %r10
	movq	-8(%rcx,%r10,8), %rax
	subq	$1, %r10
	movq	%rax, (%r11)
	leaq	(%rcx,%r10,8), %r11
	jmp	.L215
	.seh_endproc
	.text
	.p2align 4,,15
	.def	_ZSt16__introsort_loopIPxxN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_T1_.isra.92;	.scl	3;	.type	32;	.endef
	.seh_proc	_ZSt16__introsort_loopIPxxN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_T1_.isra.92
_ZSt16__introsort_loopIPxxN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_T1_.isra.92:
.LFB9447:
	pushq	%r13
	.seh_pushreg	%r13
	pushq	%r12
	.seh_pushreg	%r12
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$40, %rsp
	.seh_stackalloc	40
	.seh_endprologue
	movq	%r8, %r13
	movq	%rdx, %r8
	movq	%rcx, %rbx
	subq	%rcx, %r8
	cmpq	$128, %r8
	jle	.L224
	leaq	8(%rcx), %r12
	testq	%r13, %r13
	leaq	16(%rcx), %rbp
	je	.L251
.L228:
	sarq	$4, %r8
	movq	8(%rbx), %rcx
	subq	$1, %r13
	leaq	(%rbx,%r8,8), %r10
	movq	(%rbx), %r9
	movq	(%r10), %rax
	movq	-8(%rdx), %r8
	cmpq	%rax, %rcx
	jge	.L231
	cmpq	%r8, %rax
	jl	.L236
	cmpq	%r8, %rcx
	jl	.L249
.L250:
	movq	%rcx, (%rbx)
	movq	%r9, 8(%rbx)
	movq	-8(%rdx), %r8
.L233:
	movq	%rbp, %r10
	movq	%r12, %rsi
	movq	%rdx, %rax
	.p2align 4,,10
.L237:
	cmpq	%rcx, %r9
	movq	%rsi, %rdi
	jl	.L238
	subq	$8, %rax
	cmpq	%rcx, %r8
	jle	.L239
	.p2align 4,,10
.L240:
	subq	$8, %rax
	movq	(%rax), %r8
	cmpq	%rcx, %r8
	jg	.L240
.L239:
	cmpq	%rax, %rsi
	jnb	.L252
	movq	%r8, (%rsi)
	movq	-8(%rax), %r8
	movq	%r9, (%rax)
	movq	(%rbx), %rcx
.L238:
	movq	(%r10), %r9
	addq	$8, %rsi
	addq	$8, %r10
	jmp	.L237
	.p2align 4,,10
.L231:
	cmpq	%r8, %rcx
	jl	.L250
	cmpq	%r8, %rax
	jge	.L236
.L249:
	movq	%r8, (%rbx)
	movq	%r9, %r8
	movq	%r9, -8(%rdx)
	movq	(%rbx), %rcx
	movq	8(%rbx), %r9
	jmp	.L233
	.p2align 4,,10
.L252:
	movq	%r13, %r8
	movq	%rsi, %rcx
	call	_ZSt16__introsort_loopIPxxN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_T1_.isra.92
	movq	%rsi, %r8
	subq	%rbx, %r8
	cmpq	$128, %r8
	jle	.L224
	testq	%r13, %r13
	movq	%rsi, %rdx
	jne	.L228
.L226:
	movq	%r8, %rsi
	movq	%rbx, %rcx
	sarq	$3, %rsi
	leaq	-2(%rsi), %rbp
	movq	%rsi, %r8
	sarq	%rbp
	movq	(%rbx,%rbp,8), %r9
	movq	%rbp, %rdx
	call	_ZSt13__adjust_heapIPxxxN9__gnu_cxx5__ops15_Iter_less_iterEEvT_T0_S5_T1_T2_
.L229:
	subq	$1, %rbp
	movq	%rsi, %r8
	movq	%rbx, %rcx
	movq	(%rbx,%rbp,8), %r9
	movq	%rbp, %rdx
	call	_ZSt13__adjust_heapIPxxxN9__gnu_cxx5__ops15_Iter_less_iterEEvT_T0_S5_T1_T2_
	testq	%rbp, %rbp
	jne	.L229
	.p2align 4,,10
.L230:
	subq	$8, %rdi
	movq	(%rbx), %rax
	xorl	%edx, %edx
	movq	%rbx, %rcx
	movq	(%rdi), %r9
	movq	%rdi, %rsi
	subq	%rbx, %rsi
	movq	%rsi, %r8
	sarq	$3, %r8
	movq	%rax, (%rdi)
	call	_ZSt13__adjust_heapIPxxxN9__gnu_cxx5__ops15_Iter_less_iterEEvT_T0_S5_T1_T2_
	cmpq	$8, %rsi
	jg	.L230
.L224:
	addq	$40, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	ret
	.p2align 4,,10
.L236:
	movq	%rax, (%rbx)
	movq	%r9, (%r10)
	movq	-8(%rdx), %r8
	movq	8(%rbx), %r9
	movq	(%rbx), %rcx
	jmp	.L233
	.p2align 4,,10
.L251:
	movq	%rdx, %rdi
	jmp	.L226
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section	.text.startup,"x"
	.p2align 4,,15
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB8500:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%r15
	.seh_pushreg	%r15
	pushq	%r14
	.seh_pushreg	%r14
	pushq	%r13
	.seh_pushreg	%r13
	pushq	%r12
	.seh_pushreg	%r12
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$136, %rsp
	.seh_stackalloc	136
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	call	__main
	leaq	-32(%rbp), %rbx
	movl	$27745, %edx
	movl	$1953391986, -16(%rbp)
	leaq	16(%rbx), %rax
	movl	$1, %ecx
	movq	%rax, -32(%rbp)
	movw	%dx, 4(%rax)
	movq	%rbx, %rdx
	movq	$6, -24(%rbp)
	movb	$0, -10(%rbp)
.LEHB9:
	call	_Z9handle_iobNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
.LEHE9:
	movq	-32(%rbp), %rcx
	leaq	16(%rbx), %rax
	cmpq	%rax, %rcx
	je	.L254
	call	_ZdlPv
.L254:
	movq	.refptr._ZSt3cin(%rip), %rcx
	leaq	-48(%rbp), %rdx
.LEHB10:
	call	_ZNSi10_M_extractIxEERSiRT_
	leaq	-40(%rbp), %rdx
	movq	%rax, %rcx
	call	_ZNSi10_M_extractIxEERSiRT_
	movq	%rbx, %rdx
	movq	%rax, %rcx
	call	_ZNSi10_M_extractIxEERSiRT_
	movq	-48(%rbp), %rdx
	leaq	15(,%rdx,8), %rax
	andq	$-16, %rax
	call	___chkstk_ms
	movq	-40(%rbp), %rbx
	subq	%rax, %rsp
	testq	%rbx, %rbx
	leaq	32(%rsp), %rax
	movq	%rax, -80(%rbp)
	je	.L306
	movabsq	$1152921504606846975, %rax
	cmpq	%rax, %rbx
	ja	.L336
	movq	%rbx, %r13
	salq	$4, %r13
	movq	%r13, %rcx
	call	_Znwy
.LEHE10:
	movq	%rax, %rdi
	.p2align 4,,10
.L257:
	movq	$0, (%rax)
	addq	$16, %rax
	movq	$0, -8(%rax)
	subq	$1, %rbx
	jne	.L257
	movq	-48(%rbp), %rdx
	addq	%rdi, %r13
.L255:
	cmpq	%rdx, -32(%rbp)
	movq	%rdx, %r12
	cmovge	-32(%rbp), %r12
	leaq	0(,%r12,8), %r14
	leaq	15(%r14), %rax
	andq	$-16, %rax
	call	___chkstk_ms
	xorl	%ebx, %ebx
	movq	.refptr._ZSt3cin(%rip), %r15
	movq	-80(%rbp), %rsi
	subq	%rax, %rsp
	testq	%rdx, %rdx
	leaq	32(%rsp), %rax
	movq	%rax, -72(%rbp)
	jle	.L261
	.p2align 4,,10
.L262:
	movq	%rsi, %rdx
	movq	%r15, %rcx
.LEHB11:
	call	_ZNSi10_M_extractIxEERSiRT_
	addq	$1, %rbx
	addq	$8, %rsi
	cmpq	%rbx, -48(%rbp)
	jg	.L262
.L261:
	cmpq	$0, -40(%rbp)
	jle	.L259
	movq	.refptr._ZSt3cin(%rip), %r15
	movq	%rdi, %rbx
	xorl	%esi, %esi
	.p2align 4,,10
.L266:
	movq	%rbx, %rdx
	movq	%r15, %rcx
	call	_ZNSi10_M_extractIxEERSiRT_
	leaq	8(%rbx), %rdx
	movq	%rax, %rcx
	call	_ZNSi10_M_extractIxEERSiRT_
	addq	$1, %rsi
	addq	$16, %rbx
	cmpq	%rsi, -40(%rbp)
	jg	.L266
.L259:
	xorl	%ebx, %ebx
	testq	%r12, %r12
	movq	.refptr._ZSt3cin(%rip), %rsi
	jg	.L263
	jmp	.L269
	.p2align 4,,10
.L267:
	movq	$0, (%rax,%rbx,8)
	addq	$1, %rbx
	cmpq	%r12, %rbx
	je	.L269
.L263:
	cmpq	%rbx, -32(%rbp)
	movq	-72(%rbp), %rax
	jle	.L267
	leaq	(%rax,%rbx,8), %rdx
	movq	%rsi, %rcx
	call	_ZNSi10_M_extractIxEERSiRT_
	addq	$1, %rbx
	cmpq	%r12, %rbx
	jne	.L263
.L269:
	movq	-48(%rbp), %rax
	leaq	0(,%rax,8), %rsi
	movq	-80(%rbp), %rax
	leaq	(%rax,%rsi), %rbx
	cmpq	%rax, %rbx
	je	.L265
	movq	%rsi, %rax
	movq	-80(%rbp), %r15
	movl	$63, %r8d
	xorl	%r9d, %r9d
	sarq	$3, %rax
	movq	%rbx, %rdx
	bsrq	%rax, %rax
	xorq	$63, %rax
	cltq
	movq	%r15, %rcx
	subq	%rax, %r8
	addq	%r8, %r8
	call	_ZSt16__introsort_loopIPxxN9__gnu_cxx5__ops15_Iter_comp_iterISt7greaterIxEEEEvT_S7_T0_T1_
	addq	$-128, %rsi
	jle	.L270
	leaq	128(%r15), %rsi
	xorl	%r8d, %r8d
	movq	%r15, %rcx
	movq	%rsi, %rdx
	call	_ZSt16__insertion_sortIPxN9__gnu_cxx5__ops15_Iter_comp_iterISt7greaterIxEEEEvT_S7_T0_
	cmpq	%rsi, %rbx
	je	.L265
	.p2align 4,,10
.L271:
	movq	(%rsi), %r8
	leaq	-8(%rsi), %rax
	movq	-8(%rsi), %rdx
	cmpq	%rdx, %r8
	jg	.L274
	jmp	.L337
	.p2align 4,,10
.L309:
	movq	%rcx, %rax
.L274:
	movq	%rdx, 8(%rax)
	movq	-8(%rax), %rdx
	leaq	-8(%rax), %rcx
	cmpq	%rdx, %r8
	jg	.L309
.L273:
	addq	$8, %rsi
	movq	%r8, (%rax)
	cmpq	%rsi, %rbx
	jne	.L271
.L265:
	cmpq	%r13, %rdi
	je	.L276
	movq	%r13, %rbx
	movl	$63, %r8d
	movq	%r13, %rdx
	leaq	_Z3cmpRKSt4pairIxxES2_(%rip), %r9
	subq	%rdi, %rbx
	movq	%rdi, %rcx
	movq	%rbx, %rax
	sarq	$4, %rax
	bsrq	%rax, %rax
	xorq	$63, %rax
	cltq
	subq	%rax, %r8
	addq	%r8, %r8
	call	_ZSt16__introsort_loopIN9__gnu_cxx17__normal_iteratorIPSt4pairIxxESt6vectorIS3_SaIS3_EEEExNS0_5__ops15_Iter_comp_iterIPFbRKS3_SC_EEEEvT_SG_T0_T1_
	cmpq	$256, %rbx
	jle	.L277
	leaq	256(%rdi), %rbx
	movq	%rdi, %rcx
	leaq	_Z3cmpRKSt4pairIxxES2_(%rip), %r8
	movq	%rbx, %rdx
	call	_ZSt16__insertion_sortIN9__gnu_cxx17__normal_iteratorIPSt4pairIxxESt6vectorIS3_SaIS3_EEEENS0_5__ops15_Iter_comp_iterIPFbRKS3_SC_EEEEvT_SG_T0_
	cmpq	%r13, %rbx
	je	.L276
	leaq	_Z3cmpRKSt4pairIxxES2_(%rip), %rsi
	.p2align 4,,10
.L279:
	movq	%rsi, %rdx
	movq	%rbx, %rcx
	call	_ZSt25__unguarded_linear_insertIN9__gnu_cxx17__normal_iteratorIPSt4pairIxxESt6vectorIS3_SaIS3_EEEENS0_5__ops14_Val_comp_iterIPFbRKS3_SC_EEEEvT_T0_
	addq	$16, %rbx
	cmpq	%rbx, %r13
	jne	.L279
.L276:
	movq	-72(%rbp), %rbx
	leaq	(%rbx,%r14), %rsi
	cmpq	%rbx, %rsi
	je	.L281
	movq	%r14, %rax
	movl	$63, %r8d
	movq	%rsi, %rdx
	sarq	$3, %rax
	movq	%rbx, %rcx
	bsrq	%rax, %rax
	xorq	$63, %rax
	cltq
	subq	%rax, %r8
	addq	%r8, %r8
	call	_ZSt16__introsort_loopIPxxN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_T1_.isra.92
	addq	$-128, %r14
	jle	.L282
	movq	%rbx, %rcx
	xorl	%r8d, %r8d
	leaq	128(%rbx), %rbx
	movq	%rbx, %rdx
	call	_ZSt16__insertion_sortIPxN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_
	cmpq	%rbx, %rsi
	je	.L281
	.p2align 4,,10
.L286:
	movq	(%rbx), %r8
	leaq	-8(%rbx), %rax
	movq	-8(%rbx), %rdx
	cmpq	%r8, %rdx
	jg	.L285
	jmp	.L338
	.p2align 4,,10
.L311:
	movq	%rcx, %rax
.L285:
	movq	%rdx, 8(%rax)
	movq	-8(%rax), %rdx
	leaq	-8(%rax), %rcx
	cmpq	%rdx, %r8
	jl	.L311
.L284:
	addq	$8, %rbx
	movq	%r8, (%rax)
	cmpq	%rbx, %rsi
	jne	.L286
.L281:
	movq	-48(%rbp), %r15
	leaq	1(%r15), %r12
	leaq	15(,%r12,8), %rax
	movq	%rax, %rdx
	movq	%rax, -88(%rbp)
	andq	$-16, %rdx
	movq	%rdx, %rax
	call	___chkstk_ms
	subq	%rax, %rsp
	leaq	39(%rsp), %rax
	shrq	$3, %rax
	testq	%r15, %r15
	leaq	0(,%rax,8), %r14
	movq	$0, 0(,%rax,8)
	jle	.L287
	movq	%r15, -96(%rbp)
	movq	-40(%rbp), %r13
	leaq	8(%r14), %r11
	xorl	%eax, %eax
	movq	-80(%rbp), %r15
	xorl	%r10d, %r10d
	movl	$1, %esi
	.p2align 4,,10
.L293:
	cmpq	%r10, %r13
	movq	-8(%r15,%rsi,8), %r8
	movq	%rax, (%r11)
	jle	.L288
	movq	%r10, %rdx
	salq	$4, %rdx
	leaq	(%rdi,%rdx), %rbx
	movq	(%rbx), %rcx
	movq	8(%rbx), %r9
	cmpq	%rcx, %r8
	jl	.L289
	imulq	%rcx, %r9
	movq	$0, (%rbx)
	addq	%r9, %rax
	subq	%rcx, %r8
	movq	%rax, (%r11)
	je	.L288
	leaq	16(%rdi,%rdx), %rdx
	jmp	.L290
	.p2align 4,,10
.L339:
	imulq	%rcx, %r9
	movq	$0, (%rdx)
	addq	$16, %rdx
	addq	%rax, %r9
	subq	%rcx, %r8
	movq	%r9, (%r11)
	je	.L288
.L290:
	addq	$1, %r10
	cmpq	%r13, %r10
	je	.L288
	movq	(%rdx), %rcx
	movq	%rdx, %rbx
	movq	8(%rdx), %r9
	movq	(%r11), %rax
	cmpq	%rcx, %r8
	jge	.L339
.L289:
	subq	%r8, %rcx
	imulq	%r9, %r8
	movq	%rcx, (%rbx)
	addq	%r8, %rax
	movq	%rax, (%r11)
.L288:
	leaq	1(%rsi), %rdx
	cmpq	%rdx, %r12
	je	.L292
	movq	(%r11), %rax
	movq	%rdx, %rsi
	addq	$8, %r11
	jmp	.L293
	.p2align 4,,10
.L292:
	movq	-88(%rbp), %rax
	movq	-96(%rbp), %r15
	andq	$-16, %rax
	call	___chkstk_ms
	movq	$-1, %rdx
	movq	-72(%rbp), %rbx
	subq	%rax, %rsp
	leaq	39(%rsp), %rax
	shrq	$3, %rax
	leaq	0(,%rax,8), %rcx
	movq	$0, 0(,%rax,8)
	movq	%r15, %rax
	notq	%rax
	addq	-32(%rbp), %rax
	movq	%rcx, %r8
	cmovs	%rdx, %rax
	leaq	(%rbx,%rax,8), %r9
	movl	$1, %eax
	jmp	.L297
	.p2align 4,,10
.L294:
	movq	-8(%rcx,%rax,8), %rdx
	movq	%rdx, (%rcx,%rax,8)
.L295:
	addq	(%r9,%rax,8), %rdx
	cmpq	%rax, %rsi
	movq	%rdx, (%rcx,%rax,8)
	leaq	1(%rax), %rdx
	je	.L296
	movq	%rdx, %rax
.L297:
	cmpq	$1, %rax
	jne	.L294
	movq	$0, 8(%rcx)
	xorl	%edx, %edx
	jmp	.L295
	.p2align 4,,10
.L296:
	movq	(%rcx,%r15,8), %r9
.L305:
	movq	%r9, %rdx
	xorl	%eax, %eax
	.p2align 4,,10
.L298:
	movq	(%r14,%rax,8), %rcx
	addq	%r9, %rcx
	subq	(%r8,%rax,8), %rcx
	cmpq	%rcx, %rdx
	cmovl	%rcx, %rdx
	addq	$1, %rax
	cmpq	%r12, %rax
	jne	.L298
.L304:
	movq	.refptr._ZSt4cout(%rip), %rcx
	call	_ZNSo9_M_insertIxEERSoT_
	leaq	-49(%rbp), %rdx
	movl	$1, %r8d
	movq	%rax, %rcx
	movb	$10, -49(%rbp)
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x
	testq	%rdi, %rdi
	je	.L318
	movq	%rdi, %rcx
	call	_ZdlPv
.L318:
	xorl	%eax, %eax
	leaq	8(%rbp), %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	ret
.L282:
	movq	-72(%rbp), %rcx
	xorl	%r8d, %r8d
	movq	%rsi, %rdx
	call	_ZSt16__insertion_sortIPxN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_T0_
	jmp	.L281
.L277:
	leaq	_Z3cmpRKSt4pairIxxES2_(%rip), %r8
	movq	%r13, %rdx
	movq	%rdi, %rcx
	call	_ZSt16__insertion_sortIN9__gnu_cxx17__normal_iteratorIPSt4pairIxxESt6vectorIS3_SaIS3_EEEENS0_5__ops15_Iter_comp_iterIPFbRKS3_SC_EEEEvT_SG_T0_
.LEHE11:
	jmp	.L276
.L270:
	movq	-80(%rbp), %rcx
	xorl	%r8d, %r8d
	movq	%rbx, %rdx
	call	_ZSt16__insertion_sortIPxN9__gnu_cxx5__ops15_Iter_comp_iterISt7greaterIxEEEEvT_S7_T0_
	jmp	.L265
.L306:
	xorl	%edi, %edi
	xorl	%r13d, %r13d
	jmp	.L255
.L338:
	movq	%rbx, %rax
	jmp	.L284
.L337:
	movq	%rsi, %rax
	jmp	.L273
.L287:
	movq	%rdx, %rax
	call	___chkstk_ms
	subq	%rax, %rsp
	leaq	39(%rsp), %rax
	shrq	$3, %rax
	testq	%r15, %r15
	leaq	0(,%rax,8), %r8
	movq	$0, 0(,%rax,8)
	movq	(%r8,%r15,8), %rdx
	movq	%rdx, %r9
	jne	.L304
	jmp	.L305
.L336:
.LEHB12:
	call	_ZSt17__throw_bad_allocv
.L312:
	movq	-32(%rbp), %rcx
	addq	$16, %rbx
	movq	%rax, %rsi
	cmpq	%rbx, %rcx
	je	.L301
	call	_ZdlPv
.L301:
	movq	%rsi, %rcx
	call	_Unwind_Resume
.L313:
	testq	%rdi, %rdi
	movq	%rax, %rbx
	je	.L303
	movq	%rdi, %rcx
	call	_ZdlPv
.L303:
	movq	%rbx, %rcx
	call	_Unwind_Resume
	nop
.LEHE12:
	.seh_handler	__gxx_personality_seh0, @unwind, @except
	.seh_handlerdata
.LLSDA8500:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE8500-.LLSDACSB8500
.LLSDACSB8500:
	.uleb128 .LEHB9-.LFB8500
	.uleb128 .LEHE9-.LEHB9
	.uleb128 .L312-.LFB8500
	.uleb128 0
	.uleb128 .LEHB10-.LFB8500
	.uleb128 .LEHE10-.LEHB10
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB11-.LFB8500
	.uleb128 .LEHE11-.LEHB11
	.uleb128 .L313-.LFB8500
	.uleb128 0
	.uleb128 .LEHB12-.LFB8500
	.uleb128 .LEHE12-.LEHB12
	.uleb128 0
	.uleb128 0
.LLSDACSE8500:
	.section	.text.startup,"x"
	.seh_endproc
	.p2align 4,,15
	.def	_GLOBAL__sub_I__Z9handle_iobNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE;	.scl	3;	.type	32;	.endef
	.seh_proc	_GLOBAL__sub_I__Z9handle_iobNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
_GLOBAL__sub_I__Z9handle_iobNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE:
.LFB9354:
	subq	$40, %rsp
	.seh_stackalloc	40
	.seh_endprologue
	leaq	_ZStL8__ioinit(%rip), %rcx
	call	_ZNSt8ios_base4InitC1Ev
	leaq	__tcf_0(%rip), %rcx
	addq	$40, %rsp
	jmp	atexit
	.seh_endproc
	.section	.ctors,"w"
	.align 8
	.quad	_GLOBAL__sub_I__Z9handle_iobNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
.lcomm _ZStL8__ioinit,1,1
	.ident	"GCC: (x86_64-win32-seh-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	_ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	memmove;	.scl	2;	.type	32;	.endef
	.def	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERyy;	.scl	2;	.type	32;	.endef
	.def	memcpy;	.scl	2;	.type	32;	.endef
	.def	_ZSt19__throw_logic_errorPKc;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base15sync_with_stdioEb;	.scl	2;	.type	32;	.endef
	.def	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_appendEPKcy;	.scl	2;	.type	32;	.endef
	.def	freopen;	.scl	2;	.type	32;	.endef
	.def	_ZdlPv;	.scl	2;	.type	32;	.endef
	.def	_ZSt20__throw_length_errorPKc;	.scl	2;	.type	32;	.endef
	.def	_Unwind_Resume;	.scl	2;	.type	32;	.endef
	.def	_ZNSi10_M_extractIxEERSiRT_;	.scl	2;	.type	32;	.endef
	.def	_Znwy;	.scl	2;	.type	32;	.endef
	.def	_ZNSo9_M_insertIxEERSoT_;	.scl	2;	.type	32;	.endef
	.def	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x;	.scl	2;	.type	32;	.endef
	.def	_ZSt17__throw_bad_allocv;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	atexit;	.scl	2;	.type	32;	.endef
	.section	.rdata$.refptr._ZSt4cout, "dr"
	.globl	.refptr._ZSt4cout
	.linkonce	discard
.refptr._ZSt4cout:
	.quad	_ZSt4cout
	.section	.rdata$.refptr._ZSt3cin, "dr"
	.globl	.refptr._ZSt3cin
	.linkonce	discard
.refptr._ZSt3cin:
	.quad	_ZSt3cin
