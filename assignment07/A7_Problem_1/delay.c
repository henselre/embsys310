#include "delay.h"
#include <stdint.h>
extern uint32_t Tick;   // global counter

void delay(uint32_t delayInMilliseconds)
{
    Tick = delayInMilliseconds;  
    while (Tick > 0)
    {
          // do nothing until global counter reaches 0
          // SysTick interrupt decrements counter every 1 msec
    }
    return;
}