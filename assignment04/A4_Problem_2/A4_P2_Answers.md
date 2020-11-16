Answers to Assignment 04, problem 2
Richard Hensel
11/15/20

Create a function "func1" with 5 arguments and call "func1" from within another function "func2". Trace through the assembler and note:

2a How does the calling function "func2" pass the values to the called function "func1"?
The calling function uses local registers, R0 - R4 to hold the arguments, but first pushes the current values in R2, R3, and R4 to the stack.

2b What extra code did the compiler generate before calling the function "func1" with the multiple arguments?
Within the calling “func2” prior to calling "func1", the code pushes R2, R3, R4, in addition to LR, to the stack, then loads the 5 arguments into R0 - R4, then stores contents of R4 (the 5th argument) to the top of stack.

2c What extra code did the compiler generate inside the called function "func1" with the multiple arguments?
R4 is pushed to the stack, making R4 available for local use within func1.
R4 is loaded with the value at the address SP + 0x4 offset (the next register from the top, which happens to be the value of the 5th argument mentioned above.  "func1" then has all 5 arguments available in local registers R0 - R4.

2d Any observations?
The compiler relies the stack to temporarily store the 5th argument.
The stack became 7 registers at the largest state.
One stack register held the LR needed to return to main()
One stack register held the LR needed to return to func2 from func1.
Passing 6 arguments requires 10 stack registers when the stack is the largest.
Passing 7 arguments requires 13 registers...
Passing 4 arguments requires 4 registers...
Passing 3 arguments requires 4 registers...
The pattern suggests 3 additional stack registers are needed for every argument passed above 4. For whatever reason the compiler uses the stack rather than other available local registers, like R8, R9, etc.
In general, calling functions requires stack operations to hold LR contents, and functions with more arguments require additional stack operations.
