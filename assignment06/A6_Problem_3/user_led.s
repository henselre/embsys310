/*******************************************************************************
File name       : user_led.s
Description     : Assembly language function for controlling the user LED
*******************************************************************************/   

    EXTERN delay                    // delay() is defined outside this file

    PUBLIC control_user_led1        // Exports symbols to other modules

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
Function Name   : control_user_led1
Description     : - Uses Peripheral registers at base 0x4800.0000
                    to set GPIOA Output Data Register.
                  - Calls another assembly function delay to insert
                    delay loop

C Prototype     : void control_user_led(uint8_t state, uint32_t duration)
                : Where state indicates if LED should be on or off.
Parameters      : R0: uint8_t state
                : R1: uint32_t duration
Return value    : None
*******************************************************************************/  

GPIOA_BASE  EQU 0x48000000
GPIOA_ODR  EQU 0x48000014
GPIOA_BIT_5 EQU 0x20

control_user_led1                // R0 contains on/off control, R1 contans delay duration
     PUSH {R7, LR}               // Push R7 to preserve in main and LR to return to main
     LDR R7, =GPIOA_ODR         //  use R7 to hold address of GPIOA output direction register for PA5
     UXTB R0, R0                 // extend unsigned 8 bit to unsigned 32 bit
     CMP R0, #1                  // check whether on-off argument is on
     BNE.N L1                    // if on-off argument is off branch to L1 to turn off LED
     LDR R2, [R7]                 // on/off control is 1 so turn on LED.  Fist load contents of GPIOA ODR at address held in R7
     ORRS.W R2, R2, #GPIOA_BIT_5   // logical OR of R2 and GPIPA_BIT_5, put result in R2
     STR R2, [R7]                  //  store modified R2 back to address held in R7
     B.N L2                       //  branch to delay function call
L1:  LDR R2, [R7]                  // turn off LED when on/off control is 0
     BICS.W R2, R2, #GPIOA_BIT_5   // bit clear takes AND of R2 with complemet of GPIPA_BIT_5, put result in the ODR out
     STR R2, [R7]                  // store modified R2 back to address held in R7
L2:  MOVS R0, R1           // move duration argument into R0
     BL delay              // call delay
     POP {R0, PC}          // restore R7 and put PC at LR for return

    END
