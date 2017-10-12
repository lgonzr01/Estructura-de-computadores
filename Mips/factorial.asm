	.data
cad1: .asciiz "Introduzca un numero :"
cad2: .asciiz "El resultado es :"

	.globl main
	.text

main:
	li $v0,4
	la $a0, cad1
	syscall
	
	li $v0 5
	syscall
	move $t0,$v0
	
	move $t1,$v0
	li $t2,1
	
bucle:
	beq $t0,$t2,fin
	sub $t0,$t0,1
	mul $t1,$t1,$t0
	j bucle
	
fin:
	li $v0,4
	la $a0,cad2
	syscall
	
	li $v0,1
	move $a0,$t1
	syscall
	
	li $v0,10
	syscall