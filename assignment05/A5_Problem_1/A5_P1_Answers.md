Answers to Assignment 05, problem 1
Richard Hensel
11/22/20

Problem 1  Create a function in C that swaps two pointers
1a Explain what the main function does in order to set up the input arguments prior to calling the swap_pointer function.
Main() loads values for x and y onto the stack.  It also loads the addresses of x and y onto the stack (the pointers to x and y).  Just before calling swap_pointer() main loads the address of the pointers to x and y into R0 and R1.

1b What are the values in R0 and R1 when swap_pointer() is called?
The addresses of the pointers to x and y.

1c  Share a screen shot of the local variables inside main() after the function swap_pointer() returns showing the values of the pointers and what they are pointing to.

![image of screenshot](C:\UW_Workspace\repos\embsys310\embsys310a\assignment05\A5_Problem_1\A5 P1 screenshot.png)
