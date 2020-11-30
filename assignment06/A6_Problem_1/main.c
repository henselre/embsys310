//  Assignhment 6, problem 1
//  R. Hensel
//  11-28-20
//  Use the CMSIS to blink LED1 on the STM32L475 board

#include <stdint.h>
#include "delay.h"
//#include "stm32f401xe.h"    // CMSIS - Device Specific File
#include "system_stm32l4xx.h"
#include "stm32l475xx.h"

// LD1 --> PA5 -- Homework
// LD2 --> PB14 -- In Class

void main(void)
{     
#if 0
    // RCC AHB2 peripheral clock enable register (RCC_AHB2ENR)
    RCC_AHB2ENR |= 0x3;
    
    // GPIO port mode register (GPIOx_MODER) (x = A..E and H)
    GPIOB_MODER &= 0xDFFFFFFF;
    
    // GPIO port mode register (GPIOx_MODER) (x = A..E and H)
    GPIOA_MODER &= 0xFFFFF7FF;

    while(1)
    {
        GPIOB_ODR |= ORD14;
        delay(100000);

        GPIOB_ODR &= ~ORD14;
        delay(100000);
    }
#endif
    
#if 1
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
    // 
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
    
    while(1)
    {
        //GPIOB->ODR |= GPIO_ODR_OD14;
        GPIOB->ODR &= ~GPIO_ODR_OD14;
        GPIOA->ODR |= GPIO_ODR_OD5;
        delay(100000);
        
        //GPIOB->ODR &= ~GPIO_ODR_OD14;
        GPIOB->ODR |= GPIO_ODR_OD14;
        GPIOA->ODR &= ~GPIO_ODR_OD5;
        delay(100000);
    }    
#endif
}
