	.data 
cad1: .asciiz "Introduzca un numero"

	   .align 2
resultado: .space 4

	.globl main
	.text	
main:
	li $v0, 4
	la $a0, cad1
	syscall
	
	li $v0,5
	syscall
	move $t0,$v0
	
	sw $t0,resultado
	
	li $v0,10
	syscall