Answers to Assignment 04, problem 1
Richard Hensel
11/15/20

1a What instructions does the compiler produce in assembly for "writing" to the GPIO bit when using bit-band address?
The bit-banding method uses one assembly instruction (STR).

1b What were the instructions produced when writing to the GPIOx_ODR without using bit-banding?
The other method requires 3 assembly instructions, one to load the GPIO register, a second to modify with the mask, and the third to write to the store back to the GPIO register.  Without added precaution against something external modifying the GPIO register between the loading and storing instructions, the system could behave unpredictably.   
