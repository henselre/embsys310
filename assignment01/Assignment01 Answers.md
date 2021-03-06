Assignment 1
Richard Hensel, 10/17/20

Question 1 answer
The embedded controller for the inverter in an electric vehicle.  The inverter’s job is to condition the electric energy from the battery into a form needed to run the motor.  Assuming the motor is an AC induction type, the power transistors in the inverter are turned on and off by the embedded controller with precise timing to achieve the desired direction, torque, and speed.  The controller takes as inputs the signal from the driver to speed up (accelerator) or slow down (brake) as well as process inputs, including motor temperature, motor speed, motor current, and the DC voltage of the battery.  The inverter controller must be capable of directing energy back to the battery when the vehicle is in a regenerative braking mode.  Design challenges include tuning the controller behavior to match battery, transistor, and motor characteristics, ensuring the controller’s clock frequency is adequate for the response time needed by the system, ensuring the hardware tolerates the wide range of hot and cold temperatures in which the vehicle is expected to operate.  The need for building in controller program flexibility as EV battery and motor technology improves may be another challenge.

Question 2 answer

2’ complement is a way to represent both positive and negative binary numbers within a range limited by the register's size in bits. Representing negative numbers in 2’s complement allows addition, subtraction and multiplication to be performed with the same logic circuits as for strictly positive numbers.
