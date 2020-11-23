// Project for Assignment 4, problem 1
// blink LED1 using bit banding
// LED1 is connected to PA5 on the STM32L475VG Development board
// want to enable AHB2 peripheral bus beacause that bus connects GPIOA to the MCU
//
//RCC base register is 0x40021000. See page 79 of RM0351
#define RCC_BASE 0x40021000
//
//RCC_AHB2ENR:   Enables clock to GPIOA,
//offset is 0x4C and bit 0 enables GPIOA see page 280 of RM0351
#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4C)))
//
// GPIOB Base Address:  0x4800 0400    see page 78 of RM0351
#define GPIOB_BASE 0x48000400
// GPIOA Base Address:  0x4800 0000    see page 78 of RM0351
#define GPIOA_BASE 0x48000000

// GPIOX_MODER see page 305 of RM0351.  GPIOX_MODR is zero offset from base
#define GPIOB_MODER (*((unsigned int*)(GPIOB_BASE + 0x00)))
// GPIOX_MODER see page 305 of RM0351.  GPIOX_MODR is zero offset from base
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x00)))

// GPIOA_ODR and GPIOB_ODR are 0x14 offset from base.  See page 307 of RM0351
#define GPIOB_ODR (*((unsigned int*)(GPIOB_BASE + 0x14)))
// define a binary with all zeros except in bit(14) position to use as mask
#define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE + 0x14)))

// define a binary with all zeros except in bit(14) position to use as mask
#define ORD14 (1<<14)
// define a binary with all zeros except in bit(5) position to use as mask
#define ORD5 (1<<5)
//

int counter = 0;

void main(void)
{
    // enable clock to peripheral GPIOA by setting RCC_AHB2ENR using bit banding
    //RCC_AHB2ENR = 0x1;  /* this method writes zeros to all bits except lsb */
    *((unsigned int*)((0x42000000) + (0x2104C * 32) + (0 * 4))) = 0x1;  /* this method uses bit banding to modify only one bit with one assembly instruction  */
    // see page 32 of 262 in PM0214 programming manual
    //  RCC base register is 0x40021000, which falls in the range of peripheral memory that can be aliased
    // alias address is 0x42000000 + byte offset * 32 + bit number *4
    //
    //enable PA5 output
    GPIOA_MODER &= 0xFFFFF7FF;
    
    while(1)
    {
        // turn on LED after delay
       counter=0;  
        while (counter < 100000)
        {
            counter++;
        }
        GPIOA_ODR |= ORD5;  /*  this load, modify and store operation requies 3 assembly instructions  */
        
        //  turn off LED after delay
        counter=0;  
        while (counter < 100000)
        {
            counter++;
        }
        GPIOA_ODR &= ~ORD5;   /*  this load, modify and store operation requies 3 assembly instructions  */
    }
}
