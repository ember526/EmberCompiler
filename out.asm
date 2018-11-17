	# standard Decaf preamble 
	  .text
	  .align 2
	  .globl main
  __TakeArray:
	# BeginFunc 136
	  subu $sp, $sp, 8	# decrement sp to make space to save ra, fp
	  sw $fp, 8($sp)	# save fp
	  sw $ra, 4($sp)	# save ra
	  addiu $fp, $sp, 8	# set up new fp
	  subu $sp, $sp, 136	# decrement sp to make space for locals/temps
	# _tmp0 = "TakeArray:"
	  .data			# create string constant marked with label
	  _string1: .asciiz "TakeArray:"
	  .text
	  la $t0, _string1	# load label
	# PushParam _tmp0
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t0, 4($sp)	# copy param value to stack
	# LCall _PrintString
	# (save modified registers before flow of control change)
	  sw $t0, -8($fp)	# spill _tmp0 from $t0 to $fp-8
	  jal _PrintString   	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# _tmp1 = " "
	  .data			# create string constant marked with label
	  _string2: .asciiz " "
	  .text
	  la $t0, _string2	# load label
	# PushParam _tmp1
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t0, 4($sp)	# copy param value to stack
	# LCall _PrintString
	# (save modified registers before flow of control change)
	  sw $t0, -12($fp)	# spill _tmp1 from $t0 to $fp-12
	  jal _PrintString   	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# _tmp2 = 4
	  li $t0, 4		# load constant value 4 into $t0
	# _tmp3 = 0
	  li $t1, 0		# load constant value 0 into $t1
	# _tmp4 = 4
	  li $t2, 4		# load constant value 4 into $t2
	# _tmp5 = *(x)
	  lw $t3, 4($fp)	# load x from $fp+4 into $t3
	  lw $t4, 0($t3) 	# load with offset
	# _tmp6 = _tmp5 < _tmp2
	  slt $t5, $t4, $t0	
	# _tmp7 = _tmp2 == _tmp5
	  seq $t6, $t0, $t4	
	# _tmp8 = _tmp7 || _tmp6
	  or $t7, $t6, $t5	
	# _tmp9 = _tmp2 < _tmp3
	  slt $s0, $t0, $t1	
	# _tmp10 = _tmp9 || _tmp8
	  or $s1, $s0, $t7	
	# IfZ _tmp10 Goto _L0
	# (save modified registers before flow of control change)
	  sw $t0, -16($fp)	# spill _tmp2 from $t0 to $fp-16
	  sw $t1, -20($fp)	# spill _tmp3 from $t1 to $fp-20
	  sw $t2, -24($fp)	# spill _tmp4 from $t2 to $fp-24
	  sw $t4, -28($fp)	# spill _tmp5 from $t4 to $fp-28
	  sw $t5, -32($fp)	# spill _tmp6 from $t5 to $fp-32
	  sw $t6, -36($fp)	# spill _tmp7 from $t6 to $fp-36
	  sw $t7, -40($fp)	# spill _tmp8 from $t7 to $fp-40
	  sw $s0, -44($fp)	# spill _tmp9 from $s0 to $fp-44
	  sw $s1, -48($fp)	# spill _tmp10 from $s1 to $fp-48
	  beqz $s1, _L0	# branch if _tmp10 is zero 
	# _tmp11 = "Decaf runtime error: Array subscript out of bound..."
	  .data			# create string constant marked with label
	  _string3: .asciiz "Decaf runtime error: Array subscript out of bounds\n"
	  .text
	  la $t0, _string3	# load label
	# PushParam _tmp11
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t0, 4($sp)	# copy param value to stack
	# LCall _PrintString
	# (save modified registers before flow of control change)
	  sw $t0, -52($fp)	# spill _tmp11 from $t0 to $fp-52
	  jal _PrintString   	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# LCall _Halt
	  jal _Halt          	# jump to function
  _L0:
	# _tmp12 = _tmp2 * _tmp4
	  lw $t0, -16($fp)	# load _tmp2 from $fp-16 into $t0
	  lw $t1, -24($fp)	# load _tmp4 from $fp-24 into $t1
	  mul $t2, $t0, $t1	
	# _tmp13 = _tmp12 + _tmp4
	  add $t3, $t2, $t1	
	# _tmp14 = x + _tmp13
	  lw $t4, 4($fp)	# load x from $fp+4 into $t4
	  add $t5, $t4, $t3	
	# _tmp15 = *(_tmp14)
	  lw $t6, 0($t5) 	# load with offset
	# PushParam _tmp15
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t6, 4($sp)	# copy param value to stack
	# LCall _PrintInt
	# (save modified registers before flow of control change)
	  sw $t2, -56($fp)	# spill _tmp12 from $t2 to $fp-56
	  sw $t3, -60($fp)	# spill _tmp13 from $t3 to $fp-60
	  sw $t5, -64($fp)	# spill _tmp14 from $t5 to $fp-64
	  sw $t6, -68($fp)	# spill _tmp15 from $t6 to $fp-68
	  jal _PrintInt      	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# _tmp16 = " "
	  .data			# create string constant marked with label
	  _string4: .asciiz " "
	  .text
	  la $t0, _string4	# load label
	# PushParam _tmp16
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t0, 4($sp)	# copy param value to stack
	# LCall _PrintString
	# (save modified registers before flow of control change)
	  sw $t0, -72($fp)	# spill _tmp16 from $t0 to $fp-72
	  jal _PrintString   	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# _tmp17 = 5
	  li $t0, 5		# load constant value 5 into $t0
	# _tmp18 = 0
	  li $t1, 0		# load constant value 0 into $t1
	# _tmp19 = 4
	  li $t2, 4		# load constant value 4 into $t2
	# _tmp20 = *(x)
	  lw $t3, 4($fp)	# load x from $fp+4 into $t3
	  lw $t4, 0($t3) 	# load with offset
	# _tmp21 = _tmp20 < _tmp17
	  slt $t5, $t4, $t0	
	# _tmp22 = _tmp17 == _tmp20
	  seq $t6, $t0, $t4	
	# _tmp23 = _tmp22 || _tmp21
	  or $t7, $t6, $t5	
	# _tmp24 = _tmp17 < _tmp18
	  slt $s0, $t0, $t1	
	# _tmp25 = _tmp24 || _tmp23
	  or $s1, $s0, $t7	
	# IfZ _tmp25 Goto _L1
	# (save modified registers before flow of control change)
	  sw $t0, -76($fp)	# spill _tmp17 from $t0 to $fp-76
	  sw $t1, -80($fp)	# spill _tmp18 from $t1 to $fp-80
	  sw $t2, -84($fp)	# spill _tmp19 from $t2 to $fp-84
	  sw $t4, -88($fp)	# spill _tmp20 from $t4 to $fp-88
	  sw $t5, -92($fp)	# spill _tmp21 from $t5 to $fp-92
	  sw $t6, -96($fp)	# spill _tmp22 from $t6 to $fp-96
	  sw $t7, -100($fp)	# spill _tmp23 from $t7 to $fp-100
	  sw $s0, -104($fp)	# spill _tmp24 from $s0 to $fp-104
	  sw $s1, -108($fp)	# spill _tmp25 from $s1 to $fp-108
	  beqz $s1, _L1	# branch if _tmp25 is zero 
	# _tmp26 = "Decaf runtime error: Array subscript out of bound..."
	  .data			# create string constant marked with label
	  _string5: .asciiz "Decaf runtime error: Array subscript out of bounds\n"
	  .text
	  la $t0, _string5	# load label
	# PushParam _tmp26
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t0, 4($sp)	# copy param value to stack
	# LCall _PrintString
	# (save modified registers before flow of control change)
	  sw $t0, -112($fp)	# spill _tmp26 from $t0 to $fp-112
	  jal _PrintString   	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# LCall _Halt
	  jal _Halt          	# jump to function
  _L1:
	# _tmp27 = _tmp17 * _tmp19
	  lw $t0, -76($fp)	# load _tmp17 from $fp-76 into $t0
	  lw $t1, -84($fp)	# load _tmp19 from $fp-84 into $t1
	  mul $t2, $t0, $t1	
	# _tmp28 = _tmp27 + _tmp19
	  add $t3, $t2, $t1	
	# _tmp29 = x + _tmp28
	  lw $t4, 4($fp)	# load x from $fp+4 into $t4
	  add $t5, $t4, $t3	
	# _tmp30 = *(_tmp29)
	  lw $t6, 0($t5) 	# load with offset
	# PushParam _tmp30
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t6, 4($sp)	# copy param value to stack
	# LCall _PrintInt
	# (save modified registers before flow of control change)
	  sw $t2, -116($fp)	# spill _tmp27 from $t2 to $fp-116
	  sw $t3, -120($fp)	# spill _tmp28 from $t3 to $fp-120
	  sw $t5, -124($fp)	# spill _tmp29 from $t5 to $fp-124
	  sw $t6, -128($fp)	# spill _tmp30 from $t6 to $fp-128
	  jal _PrintInt      	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# _tmp31 = " "
	  .data			# create string constant marked with label
	  _string6: .asciiz " "
	  .text
	  la $t0, _string6	# load label
	# PushParam _tmp31
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t0, 4($sp)	# copy param value to stack
	# LCall _PrintString
	# (save modified registers before flow of control change)
	  sw $t0, -132($fp)	# spill _tmp31 from $t0 to $fp-132
	  jal _PrintString   	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# _tmp32 = *(x)
	  lw $t0, 4($fp)	# load x from $fp+4 into $t0
	  lw $t1, 0($t0) 	# load with offset
	# PushParam _tmp32
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t1, 4($sp)	# copy param value to stack
	# LCall _PrintInt
	# (save modified registers before flow of control change)
	  sw $t1, -136($fp)	# spill _tmp32 from $t1 to $fp-136
	  jal _PrintInt      	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# _tmp33 = "\n"
	  .data			# create string constant marked with label
	  _string7: .asciiz "\n"
	  .text
	  la $t0, _string7	# load label
	# PushParam _tmp33
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t0, 4($sp)	# copy param value to stack
	# LCall _PrintString
	# (save modified registers before flow of control change)
	  sw $t0, -140($fp)	# spill _tmp33 from $t0 to $fp-140
	  jal _PrintString   	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# EndFunc
	# (below handles reaching end of fn body with no explicit return)
	  move $sp, $fp		# pop callee frame off stack
	  lw $ra, -4($fp)	# restore saved ra
	  lw $fp, 0($fp)	# restore saved fp
	  jr $ra		# return from function
  __MakeArray:
	# BeginFunc 92
	  subu $sp, $sp, 8	# decrement sp to make space to save ra, fp
	  sw $fp, 8($sp)	# save fp
	  sw $ra, 4($sp)	# save ra
	  addiu $fp, $sp, 8	# set up new fp
	  subu $sp, $sp, 92	# decrement sp to make space for locals/temps
	# _tmp34 = 0
	  li $t0, 0		# load constant value 0 into $t0
	# _tmp35 = size < _tmp34
	  lw $t1, 4($fp)	# load size from $fp+4 into $t1
	  slt $t2, $t1, $t0	
	# IfZ _tmp35 Goto _L2
	# (save modified registers before flow of control change)
	  sw $t0, -12($fp)	# spill _tmp34 from $t0 to $fp-12
	  sw $t2, -16($fp)	# spill _tmp35 from $t2 to $fp-16
	  beqz $t2, _L2	# branch if _tmp35 is zero 
	# _tmp36 = "Decaf runtime error: Array size is <= 0\n"
	  .data			# create string constant marked with label
	  _string8: .asciiz "Decaf runtime error: Array size is <= 0\n"
	  .text
	  la $t0, _string8	# load label
	# PushParam _tmp36
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t0, 4($sp)	# copy param value to stack
	# LCall _PrintString
	# (save modified registers before flow of control change)
	  sw $t0, -20($fp)	# spill _tmp36 from $t0 to $fp-20
	  jal _PrintString   	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# LCall _Halt
	  jal _Halt          	# jump to function
  _L2:
	# _tmp37 = 4
	  li $t0, 4		# load constant value 4 into $t0
	# _tmp38 = size * _tmp37
	  lw $t1, 4($fp)	# load size from $fp+4 into $t1
	  mul $t2, $t1, $t0	
	# _tmp39 = _tmp38 + _tmp37
	  add $t3, $t2, $t0	
	# PushParam _tmp39
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t3, 4($sp)	# copy param value to stack
	# _tmp40 = LCall _Alloc
	# (save modified registers before flow of control change)
	  sw $t0, -24($fp)	# spill _tmp37 from $t0 to $fp-24
	  sw $t2, -28($fp)	# spill _tmp38 from $t2 to $fp-28
	  sw $t3, -32($fp)	# spill _tmp39 from $t3 to $fp-32
	  jal _Alloc         	# jump to function
	  move $t0, $v0		# copy function return value from $v0
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# *(_tmp40) = size
	  lw $t1, 4($fp)	# load size from $fp+4 into $t1
	  sw $t1, 0($t0) 	# store with offset
	# b = _tmp40
	  move $t2, $t0		# copy value
	# _tmp41 = 5
	  li $t3, 5		# load constant value 5 into $t3
	# _tmp42 = 0
	  li $t4, 0		# load constant value 0 into $t4
	# _tmp43 = 0
	  li $t5, 0		# load constant value 0 into $t5
	# _tmp44 = 4
	  li $t6, 4		# load constant value 4 into $t6
	# _tmp45 = *(b)
	  lw $t7, 0($t2) 	# load with offset
	# _tmp46 = _tmp45 < _tmp42
	  slt $s0, $t7, $t4	
	# _tmp47 = _tmp42 == _tmp45
	  seq $s1, $t4, $t7	
	# _tmp48 = _tmp47 || _tmp46
	  or $s2, $s1, $s0	
	# _tmp49 = _tmp42 < _tmp43
	  slt $s3, $t4, $t5	
	# _tmp50 = _tmp49 || _tmp48
	  or $s4, $s3, $s2	
	# IfZ _tmp50 Goto _L3
	# (save modified registers before flow of control change)
	  sw $t0, -36($fp)	# spill _tmp40 from $t0 to $fp-36
	  sw $t2, -8($fp)	# spill b from $t2 to $fp-8
	  sw $t3, -40($fp)	# spill _tmp41 from $t3 to $fp-40
	  sw $t4, -44($fp)	# spill _tmp42 from $t4 to $fp-44
	  sw $t5, -48($fp)	# spill _tmp43 from $t5 to $fp-48
	  sw $t6, -52($fp)	# spill _tmp44 from $t6 to $fp-52
	  sw $t7, -56($fp)	# spill _tmp45 from $t7 to $fp-56
	  sw $s0, -60($fp)	# spill _tmp46 from $s0 to $fp-60
	  sw $s1, -64($fp)	# spill _tmp47 from $s1 to $fp-64
	  sw $s2, -68($fp)	# spill _tmp48 from $s2 to $fp-68
	  sw $s3, -72($fp)	# spill _tmp49 from $s3 to $fp-72
	  sw $s4, -76($fp)	# spill _tmp50 from $s4 to $fp-76
	  beqz $s4, _L3	# branch if _tmp50 is zero 
	# _tmp51 = "Decaf runtime error: Array subscript out of bound..."
	  .data			# create string constant marked with label
	  _string9: .asciiz "Decaf runtime error: Array subscript out of bounds\n"
	  .text
	  la $t0, _string9	# load label
	# PushParam _tmp51
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t0, 4($sp)	# copy param value to stack
	# LCall _PrintString
	# (save modified registers before flow of control change)
	  sw $t0, -80($fp)	# spill _tmp51 from $t0 to $fp-80
	  jal _PrintString   	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# LCall _Halt
	  jal _Halt          	# jump to function
  _L3:
	# _tmp52 = _tmp42 * _tmp44
	  lw $t0, -44($fp)	# load _tmp42 from $fp-44 into $t0
	  lw $t1, -52($fp)	# load _tmp44 from $fp-52 into $t1
	  mul $t2, $t0, $t1	
	# _tmp53 = _tmp52 + _tmp44
	  add $t3, $t2, $t1	
	# _tmp54 = b + _tmp53
	  lw $t4, -8($fp)	# load b from $fp-8 into $t4
	  add $t5, $t4, $t3	
	# _tmp55 = *(_tmp54)
	  lw $t6, 0($t5) 	# load with offset
	# *(_tmp54) = _tmp41
	  lw $t7, -40($fp)	# load _tmp41 from $fp-40 into $t7
	  sw $t7, 0($t5) 	# store with offset
	# Return b
	  move $v0, $t4		# assign return value into $v0
	  move $sp, $fp		# pop callee frame off stack
	  lw $ra, -4($fp)	# restore saved ra
	  lw $fp, 0($fp)	# restore saved fp
	  jr $ra		# return from function
	# EndFunc
	# (below handles reaching end of fn body with no explicit return)
	  move $sp, $fp		# pop callee frame off stack
	  lw $ra, -4($fp)	# restore saved ra
	  lw $fp, 0($fp)	# restore saved fp
	  jr $ra		# return from function
  main:
	# BeginFunc 260
	  subu $sp, $sp, 8	# decrement sp to make space to save ra, fp
	  sw $fp, 8($sp)	# save fp
	  sw $ra, 4($sp)	# save ra
	  addiu $fp, $sp, 8	# set up new fp
	  subu $sp, $sp, 260	# decrement sp to make space for locals/temps
	# _tmp56 = 10
	  li $t0, 10		# load constant value 10 into $t0
	# _tmp57 = 0
	  li $t1, 0		# load constant value 0 into $t1
	# _tmp58 = _tmp56 < _tmp57
	  slt $t2, $t0, $t1	
	# IfZ _tmp58 Goto _L4
	# (save modified registers before flow of control change)
	  sw $t0, -16($fp)	# spill _tmp56 from $t0 to $fp-16
	  sw $t1, -20($fp)	# spill _tmp57 from $t1 to $fp-20
	  sw $t2, -24($fp)	# spill _tmp58 from $t2 to $fp-24
	  beqz $t2, _L4	# branch if _tmp58 is zero 
	# _tmp59 = "Decaf runtime error: Array size is <= 0\n"
	  .data			# create string constant marked with label
	  _string10: .asciiz "Decaf runtime error: Array size is <= 0\n"
	  .text
	  la $t0, _string10	# load label
	# PushParam _tmp59
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t0, 4($sp)	# copy param value to stack
	# LCall _PrintString
	# (save modified registers before flow of control change)
	  sw $t0, -28($fp)	# spill _tmp59 from $t0 to $fp-28
	  jal _PrintString   	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# LCall _Halt
	  jal _Halt          	# jump to function
  _L4:
	# _tmp60 = 4
	  li $t0, 4		# load constant value 4 into $t0
	# _tmp61 = _tmp56 * _tmp60
	  lw $t1, -16($fp)	# load _tmp56 from $fp-16 into $t1
	  mul $t2, $t1, $t0	
	# _tmp62 = _tmp61 + _tmp60
	  add $t3, $t2, $t0	
	# PushParam _tmp62
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t3, 4($sp)	# copy param value to stack
	# _tmp63 = LCall _Alloc
	# (save modified registers before flow of control change)
	  sw $t0, -32($fp)	# spill _tmp60 from $t0 to $fp-32
	  sw $t2, -36($fp)	# spill _tmp61 from $t2 to $fp-36
	  sw $t3, -40($fp)	# spill _tmp62 from $t3 to $fp-40
	  jal _Alloc         	# jump to function
	  move $t0, $v0		# copy function return value from $v0
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# *(_tmp63) = _tmp56
	  lw $t1, -16($fp)	# load _tmp56 from $fp-16 into $t1
	  sw $t1, 0($t0) 	# store with offset
	# y = _tmp63
	  move $t2, $t0		# copy value
	# _tmp64 = 3
	  li $t3, 3		# load constant value 3 into $t3
	# _tmp65 = 4
	  li $t4, 4		# load constant value 4 into $t4
	# _tmp66 = 0
	  li $t5, 0		# load constant value 0 into $t5
	# _tmp67 = 4
	  li $t6, 4		# load constant value 4 into $t6
	# _tmp68 = *(y)
	  lw $t7, 0($t2) 	# load with offset
	# _tmp69 = _tmp68 < _tmp65
	  slt $s0, $t7, $t4	
	# _tmp70 = _tmp65 == _tmp68
	  seq $s1, $t4, $t7	
	# _tmp71 = _tmp70 || _tmp69
	  or $s2, $s1, $s0	
	# _tmp72 = _tmp65 < _tmp66
	  slt $s3, $t4, $t5	
	# _tmp73 = _tmp72 || _tmp71
	  or $s4, $s3, $s2	
	# IfZ _tmp73 Goto _L5
	# (save modified registers before flow of control change)
	  sw $t0, -44($fp)	# spill _tmp63 from $t0 to $fp-44
	  sw $t2, -8($fp)	# spill y from $t2 to $fp-8
	  sw $t3, -48($fp)	# spill _tmp64 from $t3 to $fp-48
	  sw $t4, -52($fp)	# spill _tmp65 from $t4 to $fp-52
	  sw $t5, -56($fp)	# spill _tmp66 from $t5 to $fp-56
	  sw $t6, -60($fp)	# spill _tmp67 from $t6 to $fp-60
	  sw $t7, -64($fp)	# spill _tmp68 from $t7 to $fp-64
	  sw $s0, -68($fp)	# spill _tmp69 from $s0 to $fp-68
	  sw $s1, -72($fp)	# spill _tmp70 from $s1 to $fp-72
	  sw $s2, -76($fp)	# spill _tmp71 from $s2 to $fp-76
	  sw $s3, -80($fp)	# spill _tmp72 from $s3 to $fp-80
	  sw $s4, -84($fp)	# spill _tmp73 from $s4 to $fp-84
	  beqz $s4, _L5	# branch if _tmp73 is zero 
	# _tmp74 = "Decaf runtime error: Array subscript out of bound..."
	  .data			# create string constant marked with label
	  _string11: .asciiz "Decaf runtime error: Array subscript out of bounds\n"
	  .text
	  la $t0, _string11	# load label
	# PushParam _tmp74
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t0, 4($sp)	# copy param value to stack
	# LCall _PrintString
	# (save modified registers before flow of control change)
	  sw $t0, -88($fp)	# spill _tmp74 from $t0 to $fp-88
	  jal _PrintString   	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# LCall _Halt
	  jal _Halt          	# jump to function
  _L5:
	# _tmp75 = _tmp65 * _tmp67
	  lw $t0, -52($fp)	# load _tmp65 from $fp-52 into $t0
	  lw $t1, -60($fp)	# load _tmp67 from $fp-60 into $t1
	  mul $t2, $t0, $t1	
	# _tmp76 = _tmp75 + _tmp67
	  add $t3, $t2, $t1	
	# _tmp77 = y + _tmp76
	  lw $t4, -8($fp)	# load y from $fp-8 into $t4
	  add $t5, $t4, $t3	
	# _tmp78 = *(_tmp77)
	  lw $t6, 0($t5) 	# load with offset
	# *(_tmp77) = _tmp64
	  lw $t7, -48($fp)	# load _tmp64 from $fp-48 into $t7
	  sw $t7, 0($t5) 	# store with offset
	# _tmp79 = 4
	  li $s0, 4		# load constant value 4 into $s0
	# _tmp80 = 5
	  li $s1, 5		# load constant value 5 into $s1
	# _tmp81 = 0
	  li $s2, 0		# load constant value 0 into $s2
	# _tmp82 = 4
	  li $s3, 4		# load constant value 4 into $s3
	# _tmp83 = *(y)
	  lw $s4, 0($t4) 	# load with offset
	# _tmp84 = _tmp83 < _tmp80
	  slt $s5, $s4, $s1	
	# _tmp85 = _tmp80 == _tmp83
	  seq $s6, $s1, $s4	
	# _tmp86 = _tmp85 || _tmp84
	  or $s7, $s6, $s5	
	# _tmp87 = _tmp80 < _tmp81
	  slt $t8, $s1, $s2	
	# _tmp88 = _tmp87 || _tmp86
	  or $t9, $t8, $s7	
	# IfZ _tmp88 Goto _L6
	# (save modified registers before flow of control change)
	  sw $t2, -92($fp)	# spill _tmp75 from $t2 to $fp-92
	  sw $t3, -96($fp)	# spill _tmp76 from $t3 to $fp-96
	  sw $t5, -100($fp)	# spill _tmp77 from $t5 to $fp-100
	  sw $t6, -104($fp)	# spill _tmp78 from $t6 to $fp-104
	  sw $s0, -108($fp)	# spill _tmp79 from $s0 to $fp-108
	  sw $s1, -112($fp)	# spill _tmp80 from $s1 to $fp-112
	  sw $s2, -116($fp)	# spill _tmp81 from $s2 to $fp-116
	  sw $s3, -120($fp)	# spill _tmp82 from $s3 to $fp-120
	  sw $s4, -124($fp)	# spill _tmp83 from $s4 to $fp-124
	  sw $s5, -128($fp)	# spill _tmp84 from $s5 to $fp-128
	  sw $s6, -132($fp)	# spill _tmp85 from $s6 to $fp-132
	  sw $s7, -136($fp)	# spill _tmp86 from $s7 to $fp-136
	  sw $t8, -140($fp)	# spill _tmp87 from $t8 to $fp-140
	  sw $t9, -144($fp)	# spill _tmp88 from $t9 to $fp-144
	  beqz $t9, _L6	# branch if _tmp88 is zero 
	# _tmp89 = "Decaf runtime error: Array subscript out of bound..."
	  .data			# create string constant marked with label
	  _string12: .asciiz "Decaf runtime error: Array subscript out of bounds\n"
	  .text
	  la $t0, _string12	# load label
	# PushParam _tmp89
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t0, 4($sp)	# copy param value to stack
	# LCall _PrintString
	# (save modified registers before flow of control change)
	  sw $t0, -148($fp)	# spill _tmp89 from $t0 to $fp-148
	  jal _PrintString   	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# LCall _Halt
	  jal _Halt          	# jump to function
  _L6:
	# _tmp90 = _tmp80 * _tmp82
	  lw $t0, -112($fp)	# load _tmp80 from $fp-112 into $t0
	  lw $t1, -120($fp)	# load _tmp82 from $fp-120 into $t1
	  mul $t2, $t0, $t1	
	# _tmp91 = _tmp90 + _tmp82
	  add $t3, $t2, $t1	
	# _tmp92 = y + _tmp91
	  lw $t4, -8($fp)	# load y from $fp-8 into $t4
	  add $t5, $t4, $t3	
	# _tmp93 = *(_tmp92)
	  lw $t6, 0($t5) 	# load with offset
	# *(_tmp92) = _tmp79
	  lw $t7, -108($fp)	# load _tmp79 from $fp-108 into $t7
	  sw $t7, 0($t5) 	# store with offset
	# PushParam y
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t4, 4($sp)	# copy param value to stack
	# _tmp94 = LCall __TakeArray
	# (save modified registers before flow of control change)
	  sw $t2, -152($fp)	# spill _tmp90 from $t2 to $fp-152
	  sw $t3, -156($fp)	# spill _tmp91 from $t3 to $fp-156
	  sw $t5, -160($fp)	# spill _tmp92 from $t5 to $fp-160
	  sw $t6, -164($fp)	# spill _tmp93 from $t6 to $fp-164
	  jal __TakeArray    	# jump to function
	  move $t0, $v0		# copy function return value from $v0
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# _tmp95 = 10
	  li $t1, 10		# load constant value 10 into $t1
	# PushParam _tmp95
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t1, 4($sp)	# copy param value to stack
	# _tmp96 = LCall __MakeArray
	# (save modified registers before flow of control change)
	  sw $t0, -168($fp)	# spill _tmp94 from $t0 to $fp-168
	  sw $t1, -172($fp)	# spill _tmp95 from $t1 to $fp-172
	  jal __MakeArray    	# jump to function
	  move $t0, $v0		# copy function return value from $v0
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# b = _tmp96
	  move $t1, $t0		# copy value
	# _tmp97 = "Main:"
	  .data			# create string constant marked with label
	  _string13: .asciiz "Main:"
	  .text
	  la $t2, _string13	# load label
	# PushParam _tmp97
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t2, 4($sp)	# copy param value to stack
	# LCall _PrintString
	# (save modified registers before flow of control change)
	  sw $t0, -176($fp)	# spill _tmp96 from $t0 to $fp-176
	  sw $t1, -12($fp)	# spill b from $t1 to $fp-12
	  sw $t2, -180($fp)	# spill _tmp97 from $t2 to $fp-180
	  jal _PrintString   	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# _tmp98 = " "
	  .data			# create string constant marked with label
	  _string14: .asciiz " "
	  .text
	  la $t0, _string14	# load label
	# PushParam _tmp98
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t0, 4($sp)	# copy param value to stack
	# LCall _PrintString
	# (save modified registers before flow of control change)
	  sw $t0, -184($fp)	# spill _tmp98 from $t0 to $fp-184
	  jal _PrintString   	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# _tmp99 = 0
	  li $t0, 0		# load constant value 0 into $t0
	# _tmp100 = 0
	  li $t1, 0		# load constant value 0 into $t1
	# _tmp101 = 4
	  li $t2, 4		# load constant value 4 into $t2
	# _tmp102 = *(b)
	  lw $t3, -12($fp)	# load b from $fp-12 into $t3
	  lw $t4, 0($t3) 	# load with offset
	# _tmp103 = _tmp102 < _tmp99
	  slt $t5, $t4, $t0	
	# _tmp104 = _tmp99 == _tmp102
	  seq $t6, $t0, $t4	
	# _tmp105 = _tmp104 || _tmp103
	  or $t7, $t6, $t5	
	# _tmp106 = _tmp99 < _tmp100
	  slt $s0, $t0, $t1	
	# _tmp107 = _tmp106 || _tmp105
	  or $s1, $s0, $t7	
	# IfZ _tmp107 Goto _L7
	# (save modified registers before flow of control change)
	  sw $t0, -188($fp)	# spill _tmp99 from $t0 to $fp-188
	  sw $t1, -192($fp)	# spill _tmp100 from $t1 to $fp-192
	  sw $t2, -196($fp)	# spill _tmp101 from $t2 to $fp-196
	  sw $t4, -200($fp)	# spill _tmp102 from $t4 to $fp-200
	  sw $t5, -204($fp)	# spill _tmp103 from $t5 to $fp-204
	  sw $t6, -208($fp)	# spill _tmp104 from $t6 to $fp-208
	  sw $t7, -212($fp)	# spill _tmp105 from $t7 to $fp-212
	  sw $s0, -216($fp)	# spill _tmp106 from $s0 to $fp-216
	  sw $s1, -220($fp)	# spill _tmp107 from $s1 to $fp-220
	  beqz $s1, _L7	# branch if _tmp107 is zero 
	# _tmp108 = "Decaf runtime error: Array subscript out of bound..."
	  .data			# create string constant marked with label
	  _string15: .asciiz "Decaf runtime error: Array subscript out of bounds\n"
	  .text
	  la $t0, _string15	# load label
	# PushParam _tmp108
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t0, 4($sp)	# copy param value to stack
	# LCall _PrintString
	# (save modified registers before flow of control change)
	  sw $t0, -224($fp)	# spill _tmp108 from $t0 to $fp-224
	  jal _PrintString   	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# LCall _Halt
	  jal _Halt          	# jump to function
  _L7:
	# _tmp109 = _tmp99 * _tmp101
	  lw $t0, -188($fp)	# load _tmp99 from $fp-188 into $t0
	  lw $t1, -196($fp)	# load _tmp101 from $fp-196 into $t1
	  mul $t2, $t0, $t1	
	# _tmp110 = _tmp109 + _tmp101
	  add $t3, $t2, $t1	
	# _tmp111 = b + _tmp110
	  lw $t4, -12($fp)	# load b from $fp-12 into $t4
	  add $t5, $t4, $t3	
	# _tmp112 = *(_tmp111)
	  lw $t6, 0($t5) 	# load with offset
	# PushParam _tmp112
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t6, 4($sp)	# copy param value to stack
	# LCall _PrintInt
	# (save modified registers before flow of control change)
	  sw $t2, -228($fp)	# spill _tmp109 from $t2 to $fp-228
	  sw $t3, -232($fp)	# spill _tmp110 from $t3 to $fp-232
	  sw $t5, -236($fp)	# spill _tmp111 from $t5 to $fp-236
	  sw $t6, -240($fp)	# spill _tmp112 from $t6 to $fp-240
	  jal _PrintInt      	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# _tmp113 = " "
	  .data			# create string constant marked with label
	  _string16: .asciiz " "
	  .text
	  la $t0, _string16	# load label
	# PushParam _tmp113
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t0, 4($sp)	# copy param value to stack
	# LCall _PrintString
	# (save modified registers before flow of control change)
	  sw $t0, -244($fp)	# spill _tmp113 from $t0 to $fp-244
	  jal _PrintString   	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# _tmp114 = *(b)
	  lw $t0, -12($fp)	# load b from $fp-12 into $t0
	  lw $t1, 0($t0) 	# load with offset
	# PushParam _tmp114
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t1, 4($sp)	# copy param value to stack
	# LCall _PrintInt
	# (save modified registers before flow of control change)
	  sw $t1, -248($fp)	# spill _tmp114 from $t1 to $fp-248
	  jal _PrintInt      	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# _tmp115 = " "
	  .data			# create string constant marked with label
	  _string17: .asciiz " "
	  .text
	  la $t0, _string17	# load label
	# PushParam _tmp115
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t0, 4($sp)	# copy param value to stack
	# LCall _PrintString
	# (save modified registers before flow of control change)
	  sw $t0, -252($fp)	# spill _tmp115 from $t0 to $fp-252
	  jal _PrintString   	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# _tmp116 = 5
	  li $t0, 5		# load constant value 5 into $t0
	# PushParam _tmp116
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t0, 4($sp)	# copy param value to stack
	# _tmp117 = LCall __MakeArray
	# (save modified registers before flow of control change)
	  sw $t0, -256($fp)	# spill _tmp116 from $t0 to $fp-256
	  jal __MakeArray    	# jump to function
	  move $t0, $v0		# copy function return value from $v0
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# _tmp118 = *(_tmp117)
	  lw $t1, 0($t0) 	# load with offset
	# PushParam _tmp118
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t1, 4($sp)	# copy param value to stack
	# LCall _PrintInt
	# (save modified registers before flow of control change)
	  sw $t0, -260($fp)	# spill _tmp117 from $t0 to $fp-260
	  sw $t1, -264($fp)	# spill _tmp118 from $t1 to $fp-264
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
subu $sp, $sp, 8 # decrement sp to make space to save ra, fp
sw $fp, 8($sp) # save fp
sw $ra, 4($sp) # save ra
addiu $fp, $sp, 8  # set up new fp
li $v0, 1		# system call code for print_int
lw $a0, 4($fp)		 # integer to print
syscall		 # print it;
move $sp, $fp    # pop callee frame off stack
lw $ra, -4($fp)  # restore saved ra
lw $fp, 0($fp) # restore saved fp
jr $ra   # return from function
_PrintString:
li $v0, 4		# system call code for print_string
lw $a0, 4($sp)		 # integer to print
syscall		 # print it;
jr $ra		# return from function
_ReadLine:
li $a0, 1		 # place to print
li $v0, 9		# system call code for read_string
syscall		 # print it;
move $a0, $v0		 # place to print
li $v0, 8		# system call code for read_string
syscall		 # print it;
move $v0, $a0
move $sp, $fp		# pop callee frame off stack
jr $ra		# return from function
_StringEqual:
cmploop:
    lb      $t2,4($sp)        
    lb      $t3,8($sp)        
    bne     $t2,$t3,cmpne    
    beq     $t2,$zero,cmpeq  
    beq     $t3,$zero,cmpeq  
    addi    $s2,$s2,1        
    addi    $s3,$s3,1        
    j       cmploop          
    cmpne:                   
    li    $v0, 0             
    j   cout                 
    cmpeq:                   
    li    $v0, 1             
    cout:                    
    move $sp, $fp		# pop callee frame off stack
    jr $ra		# return from function
_Alloc:
li $v0, 9		# system call code for print_int
lw $a0, 4($sp)		 # integer to print
syscall		 # print it;
move $sp, $fp		# pop callee frame off stack
jr $ra		# return from function
_Halt:
li $v0, 10		# system call code for print_int
syscall		 # print it;
