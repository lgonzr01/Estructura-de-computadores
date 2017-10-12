	.data
cad1: .asciiz "Introduzca el numero: "
cad2: .asciiz "El resultado es: "

	.globl main
	.text
main:
	li $v0,4
	la $a0,cad1
	syscall
	
	li $v0,5
	syscall
	move $a0,$v0
	
	jal factorial
	
	move $t0,$v1
	
	li $v0,1
	move $a0,$t0
	syscall 
	
	li $v0,10
	syscall
	
factorial:
	move $t0,$a0
	move $v1,$a0
	li $t2,1
bucle:	beq $t0,$t2 fin
	sub $t0,$t0,1
	mul $v1,$v1,$t0
	j bucle
	
fin:	jr $ra