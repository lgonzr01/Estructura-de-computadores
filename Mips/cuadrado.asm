	.data
cad1: .asciiz "Introduzca el numero que quiere elevar al cuadrado "
cad2: .asciiz "El resultado es "
 


	.globl main
	
	.text
main:
	li $v0,4
	la $a0,cad1
	syscall
	
	li $v0,5
	syscall
	move $t0,$v0
	
	li $v0,4
	la $a0,cad2
	syscall
	 
	mul $t1,$t0,$t0
	
	li $v0,1
	move $a0,$t1
	syscall
	
	li $v0,10
	syscall
	
	
	