CAT2 - 8051 Tool Chain Setup and Bare-Metal LED Blink

EXP
CAT2

DATE
20/07/2026

NAME OF EXP
8051 Tool Chain Setup - Development Board - AT89S52

HARDWARE SETUP / PLATFORM
Microcontroller: AT89S52
Architecture: 8051
Development Board: AT89S52 Development Board
LED: On-board LED
GPIO Pin: To be verified

TASK NO
1. Hardware Board Bring-Up
2. Bare-Metal LED Blink
3. Custom library function for delay functionality.

![Circuit Diagram](circuit.png)

CORE LOGIC / PSEUDOCODE / CODE BASE

Hardware Board Bring-Up:
- Identify the AT89S52 microcontroller.
- Identify the power supply and programmer.
- Identify the onboard LED and GPIO pin.
- Verify power connections.

Bare-Metal LED Blink:
- Configure the GPIO pin.
- Control the LED using direct register access.
- Toggle the LED continuously.
- Implement software delay.

Custom Delay Function:
- Create a reusable delay function.
- Use nested loops to generate delays.
- Call the delay function from the main program.

INFERENCE
The AT89S52 development board was used to understand the 8051 toolchain and hardware bring-up process. A bare-metal C program was developed to control an LED using direct register access. A custom software delay function was implemented for LED blinking.
