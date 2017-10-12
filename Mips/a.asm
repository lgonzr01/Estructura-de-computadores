	.data
cad1: .asciiz "Introduzca una cadena "

	.align 2
cadena:	.space 100

	.align 0
letra: .byte 'a'

	.globl main
	.text
main:
	li $v0,4
	la $a0,cad1
	syscall
	
	li $v0,8
	la $a0,cadena
	li $a1,100
	syscall
	
	li $t0,0
	la $t1,cadena
	
	lb $t3,letra
	
bucle:  lb $t2,($t1)
	beq $t2,$zero,fin
	addi $t1,$t1,1
	bne $t2,$t3,bucle
	addi $t0,$t0,1
	j bucle
	
fin:
	li $v0,1
	move $a0,$t0
	syscall
	
	li $v0,10
	syscall
	