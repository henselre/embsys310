Answers to Assignment 08, problem 1
Richard Hensel
12/14/20

Problem 1:  Use timer counter-based PWM to dim LED as described in the tutorial.
https://www.waveshare.com/wiki/STM32CubeMX_Tutorial_Series:_PWM

The tutorial described a 108MHz clock source for the timers on that controller. According to the STM32CubeMX timer clock map for our controller, the TIM2 and TIM15 sources are 80 MHz, so instead of the 1080 prescale, I used 800 (timer clock of 0.1 MHz).  To have the same period as the PWM in the tutorial of 20 msec, I used the same counter compare value of 2000.

![image of screenshot](https://github.com/henselre/embsys310/blob/main/assignment08/A8_Problem_1/Cube_Chip.png)

![image of screenshot](https://github.com/henselre/embsys310/blob/main/assignment08/A8_Problem_1/Clock.png)
