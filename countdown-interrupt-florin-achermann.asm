# SKELETON
#
# -------------------------------------------------------------------------------------
# Series 5 - MIPS Programming Part 2 - Countdown Clock with Keyboard Interrupts
# 
# Group members:
# Florin Achermann; Merlin Streilein
# 
# Individualised code by:
# Florin Achermann
#
# IMPORTANT: Provide instructions how to use the program.
# You can press 'a' to start the Countdown and reset it to the set value.
# If the timer hasn't started yet, you can press 'b' to increment the timer by one second.
# 
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

initial:	.word 60	# this is the initial value of the countdown (seconds)
value: 		.word 60  	# this is the current value of the countdown (seconds)

start: 		.asciiz "COUNTDOWN STARTED\n"

# TODO: update with your solution
#	      0     1     2     3     4     5     6     7     8     9
digits: .byte 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F

start_pressed: .byte 0x0

# All program code is placed after the .text assembler directive
.text 		

# The label 'main' represents the starting point
main:


# *************************************************************************************
# TASK (c): Implement the interrupt handling for a key press that starts the countdown. 
# 1. Set the interrupt bit on the row of buttons you want to use (see demo code).
# 2. Implement the interrupt handler (see section at the bottom).
# 3. Add a waiting loop here and branch out if the "start_pressed" byte is != 0.
# *************************************************************************************	

	


	# waiting loop until start key pressed (key 0)
	li $t0, 0xFFFF0012	# this address holds a byte of control bits that allow us to access the keys in Digital Lab Sim
	li $t1, 0x81		# we enable interrupts by activating bit 7 on row 1, i.e., in binary: 1000 0001
	sb $t1, 0($t0)
	
	wait_loop:
	nop 
	beq $s7, $zero, wait_loop
	
 
	# print a start message to stdout
	li      $v0, 4       	
	la      $a0, start  	
	syscall             	
	
	
# *************************************************************************************
# MAIN CODE FOR COUNTDOWN: Add your implementation from Series 4 here. 
# If you don't have a working code, ask the teaching assistants for help.
# You are not allowed to copy someone else's code.
# 
# You may have to slightly adapt it to work with the interrupt handling, but no 
# major changes should be required. Most of the added functionality can be implemented 
# at the start of the program and in the interrupt  handler.
# *************************************************************************************	
	
	
	li      $v0, 4       	# code 4 == print string
	la      $a0, start  	# $a0 == address of the string
	syscall             	# Ask the operating system to print to stdout.
	
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

	
	

# *************************************************************************************
# Tasks (c), (d), (e): Take a look at the demo code for a simple interrupt handler 
# and adapt/extend it. 
#
# *************************************************************************************

# INTERRUPT HANDLER (only runs when a key is pressed).
# 0x80000180 is an address that signifies the location of the instructions in memory. This address is specific to MARS.
# What follows are the kernel mode instructions.
.ktext 0x80000180 

	# TODO: Don't forget to save your registers
	addi $sp, $sp, -8
	sw  $t0, 0($sp)
	sw  $t1, 4($sp)

 	move $k0, $v0   # Save $v0 value
   	move $k1, $a0   # Save $a0 value


	# TODO: paste your interrupt code here. See the example program on ILIAS on how to access the keys.

	li $t0, 0xFFFF0012	
	li $t1, 0x84
	sb $t1, 0($t0)
	
	# Check if a key was pressed in row 1 (which we selected previously)
	# key 0 (row 1, col 1): 0x11
	# key 1 (row 1, col 2): 0x21
	# key 2 (row 1, col 3): 0x41
	# key 3 (row 1, col 4): 0x81
	# same logic applies to other rows/cols
	lw $t0, 0xFFFF0014 
	li $t1, 0x44
	
	beq $t0, $t1, start_clock  	# check if it's key 0, and print the code
	
	li $t1, 0x84
	
	beq $t0, $t1, increment
	
	j exit_interrupt

	start_clock:
	lw $t0, value
	sw $t0, 0($sp)
	
	li $s7, 1
	j exit_interrupt
	
	increment:
	lw $t7, value
	addi $t7, $t7, 1
	sw $t7, value
	
	add $a0, $t0, $zero
	jal get_digits_increment		# $v0 right digit, $v1 left digit
	
	add $a0, $v0, $zero
	li $a1, 0xFFFF0010	# right digit
	jal write_digit_increment
	
	add $a0, $v1, $zero
	li $a1, 0xFFFF0011	# left digit
	jal write_digit_increment
	
	j exit_interrupt
	
	
	get_digits_increment:
	li $a1, 10
	divu $a0, $a1 		
	mfhi $v0
	mflo $v1
	jr $ra

	write_digit_increment:
	la $t1, digits 		# fetch base address of digits
	add $t1, $t1, $a0	# calculate offset, which digit to get
	
	lb $t1, 0($t1)		# fetch byte pattern 
	sb $t1, 0($a1)		# store byte pattern to $a1
		
	jr $ra
	
	

   	exit_interrupt:
   	move $v0, $k0   	# Restore $v0
	move $a0, $k1   	# Restore $a0
	
	
	# TODO: Don't forget to restore registers before return
	lw  $t0, 0($sp)  	
	lw  $t1, 4($sp)
	addi $sp, $sp, 8
	
	eret			# exit the interrupt handler and return to main program
	
