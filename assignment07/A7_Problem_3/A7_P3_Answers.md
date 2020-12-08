Answers to Assignment 07, problem 3
Richard Hensel
12/7/20

Problem 3  Is there anything that can be done to optimize the usage of ROM or RAM resources?

The stack size allocation in RAM set by the linker can be reduced when the code doesn't require a larger stack.  For this assignment, reducing the stack allocation by half resulted in a corresponding reduction of RAM.  Actual stack usage did not appear to go beyond two registers at a time, so stack allocation was well above the minimum required for this code.

ROM usage could be reduced by optimizing code.  Also, since constants are stored in ROM, code that uses fewer constant registers will use less ROM.

A consequence of reducing memory usage may be additional operations by the CPU when code is executing, which could impact performance if that is a concern.
