# CAT4 – 8051 Matrix Keypad, Seven-Segment Display and LED Interfacing

## Experiment Details
- **Course:** 25CS2741 – Fundamentals of Internet of Things + Lab
- **Date:** 03/08/2026
- **Microcontroller:** AT89S52 (8051)
- **Software:** Keil µVision
- **Programming Language:** Embedded C

## Aim
To interface a 4×4 matrix keypad, seven-segment display and LEDs with the AT89S52 microcontroller to perform different operations based on keypad inputs.

## Hardware Requirements
- AT89S52 Development Board
- 4×4 Matrix Keypad
- D168K Seven-Segment Display
- On-board LEDs
- USB Programmer

## Pin Configuration
- **P2.0–P2.3:** Keypad columns
- **P2.4–P2.7:** Keypad rows
- **P0.0–P0.7:** Seven-segment display
- **P1.0:** On-board LED

## Circuit Diagram

![CAT4 Circuit Diagram](circuit.png)

## Task Description
- Scan the 4×4 matrix keypad to detect key presses.
- Display the corresponding digit on the seven-segment display.
- Control LED operations according to the detected key.
- Implement running LED, alternate LED, binary counter and blinking patterns.
- Reset the system when key 0 is pressed.

## Algorithm
1. Initialize the keypad, seven-segment display and LEDs.
2. Continuously scan the keypad.
3. Identify the pressed key.
4. Display the corresponding digit.
5. Execute the assigned LED operation.
6. Repeat the process.

## Source Files
- `week4_logic.c` – Embedded C program.
- `week4.uvproj` – Keil project.
- `Objects/week4.hex` – Compiled HEX file.
- `circuit.png` – Circuit diagram.

## Result
The matrix keypad, seven-segment display and LEDs were interfaced with the AT89S52 microcontroller. Keypad inputs were used to display digits and execute the corresponding LED operations.
