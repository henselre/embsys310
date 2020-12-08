//  Assignhment 7, problem 1
//  R. Hensel
//  12-3-20
//  Define a user-defined vector table and use SysTick timer to blink LED1 on the STM32L475 board
#include <stdint.h>
#include "delay.h"
#include "stm32l475xx.h"
#include "stm32l4xx_it.h"

// LD1 --> PA5 -- Homework
// LD2 --> PB14 -- In Class

#define SYS_CLOCK_HZ 4000000u   // Default internal 4 MHz clock after startup
                                // Section 3.11 in STM32L475 datasheet DS10969
                                // a clock of 4 MHz frequency will count 4M cycles in 1 second

// define gloal veriable that will be decremented by the SysTick interrupt
uint32_t Tick = 0;

void SysTick_Initialize(void);

void main(void)
{
    // RCC AHB2 peripheral clock enable register (RCC_AHB2ENR)
    // RCC Base Address: 0x40021000
    // Address offset: 0x4C
    // Set bit[1] to 1
    // 1. Enable clock to Peripheral  
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;
    
    //RCC_AHB2ENR:   Enables clock to GPIOA,
    //offset is 0x4C and bit 0 enables GPIOA see page 280 of RM0351
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
    
    // GPIO port mode register (GPIOx_MODER) (x = A..E and H)
    // GPIOB Base Address: 0x48000400
    // Address offset: 0x00
    // Set bit[29:28] to 0x01  so --> 0x400 // To enable PB14 as output
    GPIOB->MODER &= ~GPIO_MODER_MODE14_1;
    GPIOB->MODER |= GPIO_MODER_MODE14_0;
    
    // GPIO port mode register (GPIOx_MODER) (x = A..E and H)
    // GPIOA Base Address: 0x48000000
    // Address offset: 0x00
    GPIOA->MODER &= ~GPIO_MODER_MODE5_1;
    GPIOA->MODER |= GPIO_MODER_MODE5_0;
    
    // GPIO port output data register (GPIOx_ODR) (x = A..E and H)
    // GPIOB Base Address: 0x48000400
    // Address offset: 0x14
    // Set bit[14] to 1 --> 0x4000; // Turn LED ON
    // Set bit[14] to 0 --> 0x0; // Turn LED OFF
    
    // GPIOA Base Address:  0x4800 0000    see page 78 of RM0351
    // Address offset: 0x14
    // Set bit[5] to 1 --> 0x0020; // Turn LED ON
    // Set bit[5] to 0 --> 0x0; // Turn LED OFF
    
    SysTick_Initialize();

    while(1)
    {
        //  alternate LED1 and LED2 on approximately every second      
        GPIOA->ODR ^= GPIO_ODR_OD5;
        delay(1000);
        GPIOB->ODR ^= GPIO_ODR_OD14;
        
    }    
}

void SysTick_Initialize(void)
{
    SysTick->LOAD = SYS_CLOCK_HZ/1000;       // 0xE000E014 - Counts down to 0
                                            // load with the number of cycles equivalent to 1 msec. Since 4M cycles is about 1 sec, divide by 1000 to count 1 msec
    SysTick->VAL = 0x0;                     // 0xE000E018 - Clears initial value
    SysTick->CTRL = 0x7;                    // 0xE000E010 - Enable interrupts
}

void SysTick_Handler(void)
{
    __disable_irq();
    //GPIOB->ODR ^= GPIO_ODR_OD14;
    //GPIOA->ODR ^= GPIO_ODR_OD5;
    if (Tick >0)
        Tick--;
    
    __enable_irq();
}