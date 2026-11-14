# EXPERIMENT DETAILS

**EXP:** CONTINUOUS ASSESSMENT 5 (CAT5)

**DATE:** 10/08/2026

**NAME OF EXP:** Hardware Timer and Interrupt-Based Timing for LED Fading, Pulse Generation, and Stepper Motor Control

**HARDWARE SETUP / PLATFORM:** AT89S52 (11.0592 MHz) + Keil C51 uVision + Oscilloscope

---

## TASK 5B.2: Variable-Frequency Square-Wave Generator

### 1. Hardware Setup & Circuit Diagram

- **MCU:** AT89S52 @ 11.0592 MHz
- **Signal Output Pin:** `P1.1` → Oscilloscope Channel 1
- **Mode Selector Button:** `P3.2`
- **Frequency Modes:** 100 Hz, 500 Hz, 1 kHz, 2 kHz, 5 kHz

![CAT5B.2 Circuit Diagram](circuit.png)

### 2. Core Logic / Pseudocode / Code Base

**Working Principle:**

Timer 0 operates in Mode 1 to generate interrupts at selected half-period intervals. A lookup table containing Timer 0 reload values determines the output frequency. Each interrupt toggles `P1.1`, producing a 50% duty-cycle square wave.

Pressing the mode selector button connected to `P3.2` cycles through the five available frequency modes.

**Pseudocode:**

1. Precompute 16-bit Timer 0 reload values for the five frequency modes.
2. Configure Timer 0 in Mode 1.
3. In the Timer 0 ISR:
   - Reload `TH0` and `TL0` using the selected lookup-table values.
   - Toggle the `P1.1` output pin.
4. Poll the `P3.2` button and debounce the input.
5. Increment `freq_mode` modulo 5 when the button is pressed.

**Code Base:**

- `th_table[]` and `tl_table[]` store the Timer 0 reload values.
- Lookup tables avoid runtime division inside the interrupt service routine.
- `freq_mode` selects the current output frequency.

**Build Note:** Rebuild `TASK5B_2.uvproj` in Keil C51 uVision to regenerate `Objects/TASK5B_2.hex` before flashing the AT89S52 board.

### 3. Inference

Timer 0 reload lookup tables enable variable-frequency square-wave generation from 100 Hz to 5 kHz. The output maintains an approximately 50% duty cycle, and the frequency can be changed using the mode selector button.
