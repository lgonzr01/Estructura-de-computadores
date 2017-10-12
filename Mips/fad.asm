	.data
cad1: .asciiz "Escribe una cadena "
cad2: .asciiz "Introduzca una letra "
cad3: .asciiz "Resultado "

cadena: .space 100
resultado: .space 200
	.align 1
letra: .space 2

	.globl main
	.text
main:
	li $v0,4
	la $a0,cad1
	syscall
	
	li $v0,8
	la $a0,cadena
	li $a1,99
	syscall
	
	li $v0,4
	la $a0,cad2
	syscall
	
	li $v0,8
	la $a0,letra
	li $a1,2
	syscall
	
	la $a0,cadena
	la $a1,letra
	la $a2,resultado
	jal res
	
	li $v0,4
	la $a0,cad3
	syscall
	
	li $v0,4
	la $a0,resultado
	syscall
	
	li $v0,10
	syscall
	
res:
	lb $t1,($a1)
	
bucle:	lb $t0,($a0)
	sb $t0,($a2)
	beqz $t0,fin
	addi $a2,$a2,1
	sb $t1,($a2)
	addi $a0,$a0,1
	addi $a2,$a2,1
	j bucle
fin:
	jr $ra