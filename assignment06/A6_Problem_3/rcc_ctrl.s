/*******************************************************************************
File name       : rcc_ctrl.s
Description     : Assembly language function for controlling the user LED
*******************************************************************************/   

    PUBLIC enable_rcc        // Exports symbols to other modules

// Code is split into logical sections using the SECTION directive.
// Source: http://ftp.iar.se/WWWfiles/arm/webic/doc/EWARM_AssemblerReference.ENU.pdf
// SECTION  section  :type [:flag] [(align)]
//      The data section is used for declaring initialized data or constants. This data does not change at runtime
//      The bss section is used for declaring variables. The syntax for declaring bss section is -
//      The text section is used for keeping the actual code.

// CODE: Interprets subsequent instructions as Arm or Thumb instructions, 
// depending on the setting of related assembler options.

// NOREORDER (the default mode) starts a new fragment in the section
// with the given name, or a new section if no such section exists.
// REORDER starts a new section with the given name.

// NOROOT means that the section fragment is discarded by the linker if
// no symbols in this section fragment are referred to. Normally, all
// section fragments except startup code and interrupt vectors should
// set this flag.

// The (2) is for the (align)
// The power of two to which the address should be aligned.
// The permitted range is 0 to 8. 
// Code aligned at 4 Bytes.

    SECTION .text:CODE:REORDER:NOROOT(2)
    
    THUMB               // Indicates THUMB code is used
                        // Subsequent instructions are assembled as THUMB instructions
    
/*******************************************************************************
Function Name   : enable_rcc
Description     : - Uses Bit-Band registers at base 0x4200.0000
                    to set GPIOA Output Data Register.
                  - Calls another assembly function delay to insert
                    delay loop

C Prototype     : void enable_rcc(uint32_t port)
                : Where port indicates wich port to enable the clock for
Parameters      : R0: uint32_t port

Return value    : None
*******************************************************************************/  

// Bitband address calculation formula for GPIOB
// (0x42000000+(0x2104C *32) + (1*4))) = 0x1;

// Bitband address calculation formula for GPIOA
// (0x42000000+(0x2104C *32) + (0*4))) = 0x1
//  address 0x42420980 = 0x1
RCC_ALIAS_A  EQU 0x42420980
RCC_ALIAS_B  EQU 0x42420984
RCC_AHB2ENR EQU 0x4002104C

enable_rcc                     // R0 contains the port, 0 for enablimg GPIOA, 1 for enabling GPIOB
     PUSH {R2, R6, R7, LR}     // Push R2, R6 and R7 to preserve in main and LR to return to main
     MOVS R2, #1               // use R2 to hold bit to write to alias address
     LDR R6, =RCC_ALIAS_A      // use R6 and R7 to hold alias addresses
     LDR R7, =RCC_ALIAS_B
     CMP R0, #0                  // check port
     BNE.N L1                    // if port argument is not 0 branch to L1 to enable GPIOB
     STR R2, [R6]                // port argumeny is 0 so enable GPIOA. Write a 1 to GPIOA alias
     B.N L2                      // branch to return 
L1:  STR R2, [R7]                // port argument is 1 so enable GPIOB. Write a 1 to GPIOB alias
L2:  POP {R2, R6, R7, PC}          // restore and put PC at LR for return

    END
