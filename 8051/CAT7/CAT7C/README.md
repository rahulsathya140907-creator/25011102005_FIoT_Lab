# EXPERIMENT DETAILS

**EXP:** CONTINUOUS ASSESSMENT 7 (CAT7)

**DATE:** 24/08/2026

**NAME OF EXP:** LCD Interfacing and Display Control

**HARDWARE SETUP / PLATFORM:**
- Microcontroller: AT89S52 (8051)
- Display: 16×2 LCD (HD44780 compatible)
- Input: 4×4 Matrix Keypad
- LCD Interface: 4-bit mode
- Crystal Frequency: 11.0592 MHz
- Software: Keil µVision

**TASK NO:** CAT7C – Keypad-Based Character Movement

## CIRCUIT DIAGRAM

![CAT7C Circuit Diagram](circuit.png)

## OBJECTIVE

- Interface a 4×4 matrix keypad with the AT89S52.
- Interface a 16×2 LCD with the microcontroller.
- Detect key presses and control character movement.
- Move the displayed character in four directions using keypad inputs.

## CORE LOGIC

1. Initialize the LCD in 4-bit mode.
2. Configure the keypad rows and columns for scanning.
3. Continuously scan the keypad to detect key presses.
4. Assign directional controls to the following keys:
   - **2** – Move Up
   - **8** – Move Down
   - **4** – Move Left
   - **6** – Move Right
5. Read the pressed key and determine the required movement direction.
6. Update the character's row and column position.
7. Clear or update the LCD display and show the character at its new position.
8. Repeat the process continuously.

## INFERENCE

The 4×4 matrix keypad was interfaced with the AT89S52 to control character movement on a 16×2 LCD. Directional key inputs were detected and used to update the character's position on the display.
