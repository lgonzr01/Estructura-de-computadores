	.data
cad1: .asciiz "Introduzca una cadena "
cad2: .asciiz "La cadena copiada es "

cadena: .space 100
cadcopia: .space 200

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
	
	la $a0,cadena
	la $a1,cadcopia
	
	jal strcpy
	
	li $v0,4
	la $a0,cad2
	syscall
	
	li $v0,4
	la $a0,cadcopia
	syscall
	
	li $v0 10
	syscall

strcpy:
	li $t0,0
	li $t1,0
bucle:	
	lb $t0,($a0)	
	beqz $t0, fin
	sb $t0,($a1)
	addi $a0,$a0,1
	addi $a1,$a1,1
	j bucle
fin:
	jr $ra