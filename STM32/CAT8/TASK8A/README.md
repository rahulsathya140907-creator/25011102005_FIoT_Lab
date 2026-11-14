# CAT8A – STM32 GPIO Input / Output

## Experiment Details

- **Course:** 25CS2741 – Fundamentals of Internet of Things + Lab
- **Assessment:** Continuous Lab Evaluation 8A
- **Date:** 18/09/2026
- **Experiment:** STM32 GPIO Bring-Up and Switch-Controlled LED
- **Board:** STM32 Blue Pill (STM32F103C8T6)
- **IDE:** STM32CubeMX and Keil MDK-ARM
- **Framework:** STM32 HAL

## 1. Aim

To interface a push-button and an LED with the STM32 microcontroller and configure GPIO pins so that the LED follows the state of the push-button.

## 2. Hardware Requirements

- STM32 Blue Pill development board
- Normally-open push-button
- External LED
- 220–330 Ω current-limiting resistor
- Breadboard and jumper wires
- USB power supply

## 3. Hardware Connections

| Component | STM32 Connection |
|---|---|
| Push-button terminal 1 | 3.3 V |
| Push-button terminal 2 | PA0 |
| LED anode | PA1 through 220–330 Ω resistor |
| LED cathode | GND |
| Board power | USB / regulated 3.3 V |

### GPIO Configuration

| Pin | Mode | Configuration |
|---|---|---|
| PA0 | GPIO Input | Internal Pull-Down |
| PA1 | GPIO Output | Push-Pull |

## 4. Circuit Diagram

![CAT8A Circuit Diagram](circuit.png)

## 5. Working Principle

The STM32 GPIO peripheral is configured to read the push-button state through PA0 and control the external LED through PA1.

- When the button is released, the internal pull-down keeps PA0 LOW.
- When the button is pressed, PA0 receives 3.3 V and becomes HIGH.
- The firmware reads PA0 using `HAL_GPIO_ReadPin()`.
- The corresponding state is written to PA1 using `HAL_GPIO_WritePin()`.

Therefore, the LED remains ON while the button is pressed and turns OFF when the button is released.

## 6. Core Logic / Pseudocode

1. Initialize the HAL library and system clock.
2. Initialize GPIO peripherals.
3. Configure PA0 as input with internal pull-down.
4. Configure PA1 as push-pull output.
5. Initialize the LED output to LOW.
6. Continuously read the PA0 input state.
7. If PA0 is HIGH, set PA1 HIGH.
8. Otherwise, set PA1 LOW.
9. Repeat continuously.

## 7. HAL Functions Used

- `HAL_Init()` – Initializes the STM32 HAL library.
- `HAL_GPIO_ReadPin()` – Reads the push-button input state.
- `HAL_GPIO_WritePin()` – Controls the LED output state.
- `HAL_RCC_OscConfig()` – Configures the system oscillator.
- `HAL_RCC_ClockConfig()` – Configures the system clock.

## 8. Expected Observation

| Button State | PA0 Input | PA1 Output | LED |
|---|---|---|---|
| Released | LOW | LOW | OFF |
| Pressed | HIGH | HIGH | ON |

## 9. Inference

The experiment demonstrates digital GPIO input and output interfacing using the STM32 HAL framework. The internal pull-down resistor ensures a stable LOW input when the button is released, preventing the input pin from floating.

By continuously polling the input pin and controlling the output pin, the LED successfully follows the push-button state.

## 10. Project Files

- `Core/Src/main.c` – Main application source code.
- `Core/Inc/main.h` – Application header file.
- `Blinky.ioc` – STM32CubeMX configuration.
- `MDK-ARM/Blinky.uvprojx` – Keil project file.
- `MDK-ARM/startup_stm32f103xb.s` – Startup assembly file.
- `circuit.png` – Hardware circuit diagram.

## 11. Safety Notes

- Use 3.3 V for the push-button input. Do not apply 5 V to PA0.
- Configure PA0 with an internal pull-down resistor.
- Use a 220–330 Ω resistor in series with the external LED.
- Verify LED polarity before powering the circuit.
- Ensure all circuit connections share a common ground.
