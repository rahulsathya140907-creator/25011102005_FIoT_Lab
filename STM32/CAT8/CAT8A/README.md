# EXPERIMENT DETAILS

**EXP:** CONTINUOUS LAB EVALUATION 8 (CAT8)

**DATE:** 18/09/2026

**NAME OF EXP:** STM32 GPIO Bring-Up and Switch-Controlled LED

**HARDWARE SETUP / PLATFORM:** STM32 Development Board (Blue Pill / Nucleo) + STM32CubeMX + Keil MDK

**FRAMEWORK:** STM32 HAL Libraries

---

## TASK 8A: GPIO Input/Output

### 1. Hardware Setup & Circuit Diagram

- **Microcontroller:** STM32 Development Board
- **Input Device:** Push Button
- **Output Device:** LED
- **GPIO Configuration:** Input mode for push button and output mode for LED.

![CAT8A Circuit Diagram](circuit.png)

### 2. Core Logic / Pseudocode / Code Base

**Working Principle:**

Interface a push button and an LED with the STM32. Configure the corresponding GPIO pins and develop firmware so that the LED follows the switch state.

**Pseudocode:**

1. Initialize the STM32 GPIO peripherals.
2. Configure the push-button pin as GPIO input.
3. Configure the LED pin as GPIO output.
4. Read the push-button state using `HAL_GPIO_ReadPin()`.
5. Control the LED using `HAL_GPIO_WritePin()` based on the switch state.
6. Repeat continuously.

**Core HAL Functions:**

- `HAL_GPIO_ReadPin()` – Read the push-button state.
- `HAL_GPIO_WritePin()` – Control the LED ON/OFF state.

### 3. Inference

GPIO input/output configuration enables the STM32 to interface with external devices. The LED follows the push-button state through direct GPIO control.
