# CAT3 – Timer-Based LED Pattern Generator and Button Interrupt Controller

**EXP:** CAT3

**DATE:** 27/07/2026

**NAME OF EXP:** Timer-Based LED Pattern Generator and Button Interrupt Controller

**HARDWARE SETUP / PLATFORM:**
- Microcontroller: AT89S52
- Architecture: 8051
- Development Board: AT89S52 Development Board
- LEDs: Four LEDs connected to GPIO pins
- Input: One push-button connected to a GPIO pin

**TASK NO:**
- Design and implement a register-level GPIO controller.
- Configure four LEDs as digital outputs.
- Configure a push-button as a digital input.
- Implement four LED operating modes using bare-metal Embedded C.
- Implement switch debouncing to ensure one state transition per button press.

**CIRCUIT DIAGRAM:**

![CAT3 Circuit Diagram](circuit.png)

**CORE LOGIC / PSEUDOCODE / CODE BASE:**

**1. GPIO Configuration**
- Configure four GPIO pins as LED outputs.
- Configure one GPIO pin as button input.
- Use direct register access.

**2. Button Handling**
- Monitor the push-button input.
- Implement software debouncing.
- Detect valid button presses.
- Advance to the next operating mode on each valid press.

**3. LED Operating Modes**

- **Mode 1 – Running LED:** LEDs turn ON sequentially from LED1 to LED4 and repeat.
- **Mode 2 – Binary Counter:** LEDs display a four-bit binary count from 0000 to 1111 and repeat.
- **Mode 3 – Alternating Pattern:** LEDs alternate between 1010 and 0101.
- **Mode 4 – All LED Flash:** All four LEDs flash between 1111 and 0000.

**4. Mode Switching**
- Initially, all LEDs remain OFF.
- Each valid button press advances the operating mode.
- After Mode 4, the system returns to Mode 1.

**INFERENCE:**

A four-state LED control system is implemented using the AT89S52 microcontroller. The system demonstrates register-level GPIO control, LED sequencing, binary counting, alternating LED patterns and button-based mode switching with software debouncing.
