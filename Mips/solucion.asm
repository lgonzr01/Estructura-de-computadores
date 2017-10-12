.data
cadena: .space 100 
letra: .space 2 
cadenares: .space 200 
.text
.globl main
main:
li $v0, 8
la $a0, cadena 
li $a1, 99 
syscall

li $v0, 8
la $a0, letra 
li $a1, 2 
syscall
la $a0, cadena
lb $a2, letra
la $a1, cadenares 
jal funcion
li $v0, 4
la $a0, cadenares 
syscall
li $v0, 10 
syscall
funcion:
lb $t0, ($a0)
sb $t0, ($a1) 
beqz $t0, fin 
addi $a1, $a1, 1 
sb $a2, ($a1) 
addi $a1, $a1, 1 
addi $a0, $a0, 1 
j funcion
fin:
jr $ra

