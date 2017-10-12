	.data
cad1: .asciiz "Introduzca el primer numero "
cad2: .asciiz "Introduzca el segundo numero "
cad3: .asciiz "Introduzca el tercer numero "
cad4: .asciiz "Introduzca el cuarto numero "

a:	.asciiz "A + B= "
b: 	.asciiz "  C - D= "
c: 	.asciiz "  A + B + C + D="
d: 	.asciiz "  A^2= "
e: 	.asciiz "  A<<3= "
	
	.globl main
	.text
	
main:
	li $v0 4
	la $a0,cad1
	syscall
	
	li $v0,5
	syscall
	move $t0,$v0
	
	li $v0 4
	la $a0,cad2
	syscall
	
	li $v0,5
	syscall
	move $t1,$v0

	
	li $v0 4
	la $a0,cad3
	syscall
	
	li $v0,5
	syscall
	move $t2,$v0
	
	li $v0 4
	la $a0,cad4
	syscall
	
	li $v0,5
	syscall
	move $t3,$v0
	
	li $v0 4
	la $a0,a 
	syscall
	
	add $t4,$t0,$t1
	li $v0,1
	move $a0,$t4
	syscall
	
	li $v0 4
	la $a0,b
	syscall
	
	sub $t5,$t2,$t3
	li $v0, 1
	move $a0,$t5
	syscall
	
	li $v0 4
	la $a0,c
	syscall
	
	add $t6,$t0,$t1
	add $t7,$t2,$t3
	add $t6,$t6,$t7
	
	li $v0,1
	move $a0,$t6
	syscall
	
	li $v0,4
	la $a0,d
	syscall
	
	mul $t7,$t0,$t0
	li $v0,1
	move $a0,$t7
	syscall
	
	li $v0,4
	la $a0,e
	syscall
	
	sll $t8,$t0,3
	li $v0,1
	move $a0,$t8
	syscall
	
	li $v0 10
	syscall