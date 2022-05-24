# SOLUTIONS
#
# -------------------------------------------------------------------------------------
# Series 4 - MIPS Programming Part 1 - Countdown Clock
# 
# Group members:
# Florin Achermann; Merlin Streilein
# 
# Individualised code by:
# Florin Achermann
# 
# Exercise Version:
# ** 2 **
#
# Notes:
# We provide hints and guidance in the comments below and
# strongly encourage you to follow the skeleton.
# However, you are free to change the code as you like.
# 
# -------------------------------------------------------------------------------------

# Declare main as a global function
.globl main 
	
# All memory structures are placed after the .data assembler directive
.data

value: .word 60  # this is the initial value of the countdown (seconds)

start: .asciiz "COUNTDOWN STARTED\n"

# *************************************************************************************
# TASK (c): Add the correct hex code for each digit. One byte (8 bits) fully determines
# the state of one digit in the display. See the exercise sheet for a legend. 
# *************************************************************************************
#
# The .byte assembler directive reserves space
# in memory for a single byte (or multiple bytes when separated by comma)
# and assigns that memory location an initial value
# (or a comma separated list of initial values)
# 
# 	      0     1     2     3     4     5     6     7     8     9
digits: .byte 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F
decimal_points: .byte 0x80, 0x00 # on, off

# All program code is placed after the .text assembler directive
.text 		

# The label 'main' represents the starting point
main:
	li      $v0, 4       	# code 4 == print string
	la      $a0, start  	# $a0 == address of the string
	syscall             	# Ask the operating system to print to stdout.
	
	
# *************************************************************************************
# TASK (e): Implement the main countdown loop. It should stop when the countdown 
# reaches zero. From here you should call the subroutines defined below, some of which
# are already complete and some you have to implement in other tasks.
# *************************************************************************************
	
	lw $t0, value  		# register t0 holds the countdown value
	
	loop:
	
	addi $t0, $t0, -1
	
	add $a0, $t0, $zero
	jal get_digits		# $v0 right digit, $v1 left digit
	
	add $a0, $v0, $zero
	li $a1, 0xFFFF0010	# right digit
	jal write_digit
	
	add $a0, $v1, $zero
	li $a1, 0xFFFF0011	# left digit
	jal write_digit
	
	# stall for 1 second
	
	jal delay
	
	beq $zero, $t0, blink	# if $t0 (the counter) is zero, branch to the blinking animation
	
	jal loop
	
	# 1. Split the countdown value into its two digits (see get_digits subroutine)
	# 2. Write the digits to the display (see write_digit subroutine)
	# 3. Stall for 1 second
	# 4. Check if countdown runs out and continue looping
	
	
# *************************************************************************************
# TASK (f): Alarm signal - create a blinking animation. 
# *************************************************************************************

	blink:
	
	# addresses of the display
	li $t4, 0xFFFF0010
	li $t5, 0xFFFF0011
	
	# turn off decimal points
	sb $zero, 0($t4) 	# write zeros to the address to turn of display
	sb $zero, 0($t5)
	
	# wait
	li $v0, 32 		# code for sleeping
	li $a0, 500 		# 500 ms
	syscall
	
	# turn on decimalpoints
	li $t6, 0x80		# pattern to turn on only the decimal point
	
	sb $t6, 0($t4)
	sb $t6, 0($t5)
	
	# wait
	li $v0, 32 		# code for sleeping
	li $a0, 500 		# 500 ms
	syscall
	
	jal blink
	
	# 1. Turn display off
	# 2. Wait
	# 3. Turn display on
	# 4. Loop
	
	

	# Exit the program by means of a syscall.
	# The code for exit is "10". 
	li $v0, 10 		# sets $v0 to "10" to select exit syscall
	syscall




# This is a helper subroutine. It splits an integer into its two individual digits and
# saves the results in registers v0 and v1.
# Arguments: 
#     a0: an integer value 0 <= x < 100
# Outputs:
#     v0: right digit (10^0)
#     v1: left digit (10^1)
get_digits:
	li $a1, 10
	divu $a0, $a1 		
	mfhi $v0
	mflo $v1
	jr $ra
	
# *************************************************************************************
# TASK (d): Write a digit to the segment display. This subroutine expects two 
# arguments as input, saved in registers a0 and a1. 
# 
# a0 (word): The digit, a number between 0 and 9
#
# a1 (byte): This is the address of the segment status buffer to which we want to 
#	write the segment state. 
# 	This will either be 0xFFFF0010 (right segment) or 0xFFFF0011 (left segment).
#
#
# Hint 1: Make sure to save any temporary registers that you use here to the stack
# and restore them again before returning.
#
# Hint 2: The register "ra" contains the return address
#
# *************************************************************************************
write_digit:
	# 1. Fetch the correct byte pattern depending on digit passed in (see the 
	#    array "digits" defined at the top). 
	#    Hint: You can load an address with the "la" instruction.
	# 2. Save the byte to the memory address in a1. 
	#    Hint: You can store a byte with the "sb" instruction. 
	#          Compare it to the "sw" instruction seen in class.
	# 3. Return.
	la $t1, digits 		# fetch base address of digits
	add $t1, $t1, $a0	# calculate offset, which digit to get
	
	lb $t1, 0($t1)		# fetch byte pattern 
	sb $t1, 0($a1)		# store byte pattern to $a1
		
	jr $ra

delay:
	# delays the program 1 second
	li $v0, 32 		# code for sleeping
	li $a0, 1000 		# 1000 ms
	syscall
	jr $ra
