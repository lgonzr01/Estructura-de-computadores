	.data

datos1:	.half 4,7,2
	.align 2
	.word 1,-5
	.byte 4
	.align 1
	.half 3
	.align 2
	.word -3
	.space 2
	.byte 'c'
	
datos2: .byte 2,3,5,7

cad1: .asciiz " Primer valor "
cad2: .asciiz " Segundo valor "
cad3: .asciiz " Resultado "

	.globl main
	.text
main:
	lw $t0,datos1+8
	
	li $v0,4
	la $a0,cad1
	syscall
	
	li $v0,1
	move $a0,$t0
	syscall
	
	lh $t1,datos1+18
	
	li $v0,4
	la $a0,cad2
	syscall
	
	li $v0,1
	move $a0,$t1
	syscall
	
	li $v0,4
	la $a0,cad3
	syscall
	
	add $t2,$t1,$t0
	
	li $v0,1
	move $a0,$t2
	syscall
	
	li $v0, 10
	syscall