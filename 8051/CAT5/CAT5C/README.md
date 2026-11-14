# EXPERIMENT DETAILS

**EXP:** CONTINUOUS ASSESSMENT 5 (CAT5)

**DATE:** 10/08/2026

**NAME OF EXP:** Hardware Timer and Interrupt-Based Timing for LED Fading, Pulse Generation, and Stepper Motor Control

**HARDWARE SETUP / PLATFORM:** AT89S52 (11.0592 MHz) + 8051 Development Board

---

## TASK 5C: Stepper Motor Speed and Direction Control

### 1. Hardware Setup & Circuit Diagram

- **MCU:** AT89S52 @ 11.0592 MHz
- **Output Device:** Stepper Motor
- **Control Method:** Timer Interrupt-Based Step Sequencing
- **Task Status:** Optional for this week

![CAT5C Circuit Diagram](circuit.png)

### 2. Core Logic / Pseudocode / Code Base

**Working Principle:**

The Timer 0 interrupt determines the step interval of the stepper motor. At every interrupt, the controller generates the next step sequence to rotate the motor.

The motor speed is controlled by changing the time interval between consecutive steps.

**Step Sequence:**

```text
1000
0100
0010
0001
```

**Speed Settings:**

- **Slow:** 100 ms/step
- **Medium:** 50 ms/step
- **Fast:** 10 ms/step

**Pseudocode:**

1. Configure Timer 0 to generate periodic interrupts.
2. Store the stepper motor sequence.
3. On every timer interrupt:
   - Generate the next step pattern.
   - Send the pattern to the motor interface.
   - Advance to the next step.
4. Change the timer interval to control motor speed.
5. Repeat the sequence continuously.

### 3. Inference

Timer-based step sequencing enables controlled stepper motor rotation without software delay loops. Changing the timer interval controls motor speed while maintaining a consistent stepping sequence.
