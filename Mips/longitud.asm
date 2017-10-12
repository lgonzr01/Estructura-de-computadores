	.data
cad1: .asciiz "Introduzca una cadena "
cad2: .asciiz "La longitud de la cadena es: "

	.align 2
cadena: .space 100

	.globl main
	
	.text
main:
	li $v0,4
	la $a0, cad1
	syscall
	
	li $v0,8
	la $a0,cadena
	li $a1,100
	syscall
	
	li $t0,0
	la $t1,cadena
	
bucle:	
	lb $t2,($t1)
	beqz $t2,fin
	addi $t0,$t0,1
	addi $t1,$t1,1
	j bucle
fin:
	li $v0,4
	la $a0, cad2
	syscall
	
	li $v0,1
	move $a0,$t0
	syscall
	
	li $v0, 10
	syscall