/*******************************************************************************
File name       : swapCharsAsm.s
Description     : Assembly language function for swapping two characters
*******************************************************************************/   

    EXTERN PrintString  // PrintString is defined outside this file.
    EXTERN myCstr       // myCstr defined outside this file.
    
    PUBLIC swapCharsAsm       // Exports symbols to other modules
                        // Making available to other modules.
    
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
Function Name   : swapCharsAsm 
Description     : Calls C code to print a string; 
                  swaps two characters in registers referenced by pointers passed as input arguments
C Prototype     : swapCharsAsm(char* char1, char* char2)
                : Where char1 and char2 are two pointers to character variables
Parameters      : R0: pointer to charater
                : R1: pointer to character
Return value    : none
*******************************************************************************/  
  
swapCharsAsm
    PUSH {R4,LR}         // save R4 and return address
    MOV R2, R0         //  move pointer argument 1 in R0 to R2
    LDRB R4, [R1]      //  R4 = value in pointer argument 2
    LDRB R3, [R2]      //  R3 = value in pointer argument 1
    STRB R4, [R2]      //  put value of pointer argument 2 into address in R2
    MOVS R0, #1        // put the number 1 into R0
    CMP R3, R4         // compare the two argument values
    IT  EQ               // if compare in previous instruction indicates equal execute the next instructon
    MOVEQ R0, #0        //  put a 0 into R1 if CMP result is equal
    STRB R3, [R1]        //  put the value of argument 1 into address in R1 
    POP {R4,LR}         // Restore R4 and LR
    BX LR               // return
                        // R0 contains the result returned by the function
    END
