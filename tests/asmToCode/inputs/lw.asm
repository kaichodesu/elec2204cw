    addi $sp, $zero, 0x1000
    sw $ra, 0($sp)
    addi $t0, $zero, 0x2000
    lw $s0, 0($t0)
    lw $ra, 0($sp)
    addi $sp, $sp, 4
