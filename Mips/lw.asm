	.data
n1: .word 1056

	.align 0
n2: .byte 5

	.align 2
resultado: .space 4
	
	.globl main
	.text
main:

	lw $t0,n1
	lb $t1,n2
	
	add $t2,$t0,$t1
	sw $t2,resultado
	
	li $v0,10
	syscall
