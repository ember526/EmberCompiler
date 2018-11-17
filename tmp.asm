	# standard Decaf preamble 
	  .text
	  .align 2
	  .globl main
  main:
	# BeginFunc 20
	  subu $sp, $sp, 8	# decrement sp to make space to save ra, fp
	  sw $fp, 8($sp)	# save fp
	  sw $ra, 4($sp)	# save ra
	  addiu $fp, $sp, 8	# set up new fp
	  subu $sp, $sp, 20	# decrement sp to make space for locals/temps
	# _tmp0 = 10
	  li $t0, 10		# load constant value 10 into $t0
	# a = _tmp0
	  move $t1, $t0		# copy value
	# _tmp1 = 82
	  li $t2, 82		# load constant value 82 into $t2
	# b = _tmp1
	  move $t3, $t2		# copy value
	# _tmp2 = 5
	  li $t4, 5		# load constant value 5 into $t4
	# b = _tmp2
	  move $t3, $t4		# copy value
	# PushParam b
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t3, 4($sp)	# copy param value to stack
	# LCall _PrintInt
	# (save modified registers before flow of control change)
	  sw $t0, -12($fp)	# spill _tmp0 from $t0 to $fp-12
	  sw $t1, 0($gp)	# spill a from $t1 to $gp+0
	  sw $t2, -16($fp)	# spill _tmp1 from $t2 to $fp-16
	  sw $t3, 4($gp)	# spill b from $t3 to $gp+4
	  sw $t4, -24($fp)	# spill _tmp2 from $t4 to $fp-24
	  jal _PrintInt      	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# PushParam a
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  lw $t0, 0($gp)	# load a from $gp+0 into $t0
	  sw $t0, 4($sp)	# copy param value to stack
	# LCall _PrintInt
	  jal _PrintInt      	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# PushParam b
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  lw $t0, 4($gp)	# load b from $gp+4 into $t0
	  sw $t0, 4($sp)	# copy param value to stack
	# LCall _PrintInt
	  jal _PrintInt      	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# EndFunc
	# (below handles reaching end of fn body with no explicit return)
	  move $sp, $fp		# pop callee frame off stack
	  lw $ra, -4($fp)	# restore saved ra
	  lw $fp, 0($fp)	# restore saved fp
	  jr $ra		# return from function
_PrintInt:
sw $ra, -4($fp)	# save ra
sw $fp, 0($fp)	#  save fp
li $v0, 1		# system call code for print_int
lw $a0, 4($sp)		 # integer to print
syscall		 # print it;
move $sp, $fp		# pop callee frame off stack
lw $ra, -4($fp)	# restore saved ra
lw $fp, 0($fp)	# restore saved fp
jr $ra		# return from function
