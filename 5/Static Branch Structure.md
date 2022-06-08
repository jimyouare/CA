1 Static Branch Structure (3 points)
Which problems arise in the following assembly loop, if Predict Not Taken is chosen by default?
1 addi $s1, $zero, 1024 // s1 := 1024
2 loop: addi $s1, $s1, -1 // s1--
3 jal subroutine // call subroutine()
4 bne $s1, $zero, loop // if (s1 != 0) jump loop
Optimize the example to Predict not Taken.
2 Antidependencies (1 point)
Explain what an antidependency is.
3 Branch Delay Slots (1 point)
Explain what a branch delay slot is.
4 Dynamic Branch Structure (3 points)
Consider the following C program.
1 int t = 0;
2 for( int i = 0; i < 8; i++ )
3 {
4 for( int j = 0; j < 8; j++ )
5 {
6 t = t + i*j;
7 }
8 }
If the processor uses dynamic branch prediction and Taken is choosen by default, answer the
following questions.
• How many wrong predictions occur when a 1-bit counter is used? Explain briefly your counting.
• How many wrong predictions occur when a 2-bit counter is used? Explain briefly your counting.
For each of the two predictors, compute the entries in the branch history table (BHT) in line 6
when i = 6 and j = 3.
5 Multiple-Issue Processors (3 points)
Determine whether each statement is true or false. Briefly explain your answer.
• Pipelining takes advantage of instruction-level parallelism, but does not enable the processor
to execute more than one instruction at a time.
• Multiple-issue processors are able to execute more than one instruction per clock cycle.
• SIMD (single-instruction multiple-data) processors are static multiple-issue processors.
2
Programming Part
The programming exercises can be solved in groups of max. two students. You and your group
member work together such that both contribute equally. In order to ensure that both participants
understand all code they turn in, we require each student to hand in a slightly different version of
the exercise/code. As described below, these versions differ only in a very specific functionality for
which each individual student is responsible.
Preparation
(a) Download the code skeleton from ILIAS. Instructions on how to use the MARS MIPS simulator are provided in Series 4 and on ILIAS.
(b) This exercise is a continuation of the practical part in Series 4. You will need a working
implementation of the countdown clock. If you couldn’t finish it, please contact the teaching
assistants (see slides from week 1) so they can help you find the bugs. We won’t provide
solutions and you are not allowed to copy the code from other students.
Extending the Countdown Clock
In this exercise you will extend the countdown clock with new functionalities:
• The initial value of the countdown can be set with the numeric keys. For simplicity, you can
reduce the countdown to one digit. Feel free to extend this to support setting both digits
with the number keys (not mandatory).
• The countdown can be started with one of the keys labeled ‘a’ to ‘f’.
• During its operation, the countdown clock can also be reset with one of the keys labeled ‘a’
to ‘f’.
Figure 1: The countdown clock can be controlled by the key pad on the right. In this tool, the keys
act as switches. Clicking once pushes the key down, clicking a second time will release the key.
Keyboard Interrupts
There are mainly two ways we can incorporate key presses into our program:
• Polling: In this approach we periodically check the state of the I/O device from our main
program. This is very straightforward to implement, but the disadvantage is that the polling
operation is blocking the execution of the main program. Furthermore, I/O changes between
the polling operations are not detected. For our purposes, this method is not suitable.
• Interrupt: Here the block of instructions that executes on a key press is separated from the
main program. An interrupt can happen at any time and will immediately interrupt (hence
3
the name) current operations. After handling the interrupt, the main program will resume
where it left off (PC is reset to its old value similar to when we return from a subroutine).
The topic of interrupts and I/O was not yet covered in the lecture and will only be briefly
touched. The concept of it is quite easy to understand. Unfortunatly, a proper implementation
is often very challenging as there are many pitfalls one could encounter.
Luckily, we don’t have to deal with all of these challenges since we use a simulator. For
example, we don’t have to handle multiple interrupts at the same time since we can assume
only one I/O device is active (the keypad).
We recommend you read section 6.6, “Interfacing I/O Devices to the Processor, Memory, and
Operating System” in the book “Computer Architecture and Design”, 4-th edition1 by Patterson
and Hennessy. We also provide a simple demo program that shows how to implement a key press
in the Digital Lab Sim in MARS.
Tasks
(a) Carefully study the demo program for interrupts. It is annotated with many useful comments
that explain the interrupt mechanism. You can reuse and adapt this code to solve the following
tasks. The help section in the “Digital Lab Sim” tool may also be useful to you.
(b) Fill the missing information in the header of the main source file. Provide your name and
instructions how to use the program (which key does what). The skeleton we provide contains
many useful comments for each subtask.
(c) Implement the interrupt handling for a key press that starts the countdown. This should be
based on the code you wrote in the previous assignment. Make sure this works before you
move on to the next task.
Individualized versions: The choice of key depends on your matriculation number. If it
ends with digits 0 or 1, choose ‘a’, if it ends with digits 2 or 3, choose ‘b’ and so on until ‘e’
which is chosen if the number ends with digits 8 or 9.
(d) Add the functionality to reset the countdown clock while it is running. You may reuse the
same key as in task (c) for this purpose or choose a new one if you like. Make sure this works
before you move on to the next task.
(e) Make it possible to use keys ‘0’ to ‘9’ to set the initial value of the countdown. For simplicity,
you can reduce the countdown to one digit, but free to extend this to support setting both
digits with the number keys. To pass this subtask, it should at least be possible to choose
between two initial values.
(f) Upload your source code to ILIAS by Tuesday, 17. May 2022 at 3 p.m. If you are working in
a group, you have to upload two versions, one for each student (you can upload them to the
same group folder).
1Newer editions seem to miss this section, but edition four is available online: https://nsec.sjtu.edu.cn/data/
MK.Computer.Organization.and.Design.4th.Edition.Oct.2011.pdf
4
