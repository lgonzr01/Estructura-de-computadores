funcion:
	li $t4,0
	
bucle:	lw $t0,($a0)
	lw $t1,($a1)
	beq $t4,$t3,fin	
	add $t2,$t1,$t0
	sw $t2,($a2)
	addi $t4,$t4,1
	addi $a0,$a0,4
	addi $a1,$a1,4
	addi $a2,$a2,4
	j bucle
fin:
	jr $ra
	