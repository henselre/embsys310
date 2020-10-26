Q1a)  -2147483648
Q1b)  0x80000000
Q1c)  N is set to one because the result is a negative number in 2's complement representation.  The V flag is set to one because the result of adding two positive numbers was a negative, indicating overflow.

Q2a)  Counter goes to zero because -1 + 1 = 0
Q2b)  N and V flags are zero because the result is not negative and there is no overflow.

Q3a)  Unsigned int 0x7FFFFFFF = 2147483647, and 2147483648 in Locals after incrementing.
Q3b)  N flag is set because the MSB is one, and V flag is set because two operands with MSB=0 were added together giving a result with MSB = 1.

Q4a) Unsigned 0xFFFFFFFF = 4294967295 in Locals, and 0 in Locals after incrementing.  The Locals window indicates the variable type as Unsigned int which suggests the compiler/linker treats unsigned and unsigned int.
Q4b) N flag not set because MSB is 0, and V flag is not set because one operand had MSB = 1 and the other MSB = 0.  If both operands had MSB = 1 giving a result with MSB=0, the V flag would have been set.

Q5a) The scope of "counter" is global.
Q5b) Not visible in Locals view
Q5c) Use the Watch view to monitor "counter"
Q5d) Location is 0x20000000

Q6a) Value of "counter" is 4 at the end of main().
Q6b) The program incremented the variable stored at memory address 0x20000000 four times.

Q7a) on device, counter is stored at 0x20000000.
Q7b) stored in RAM
Q7c) counter = 4 at end of main().
