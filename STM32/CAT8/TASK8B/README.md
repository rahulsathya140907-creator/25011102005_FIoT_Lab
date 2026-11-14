# CAT8B – STM32 Event-Based Control (Switch Debouncing)

## Experiment Details

- **Course:** 25CS2741 – Fundamentals of Internet of Things + Lab
- **Assessment:** Continuous Lab Evaluation 8B
- **Date:** 18/09/2026
- **Experiment:** STM32 Event-Based Control (Switch Debouncing)
- **Board:** STM32 Blue Pill (STM32F103C8T6)
- **IDE:** STM32CubeMX and Keil MDK-ARM
- **Framework:** STM32 HAL

## 1. Aim

To modify the GPIO application so that each valid push-button press toggles the LED exactly once. The experiment investigates mechanical switch bouncing and implements a software-based debounce mechanism.

## 2. Hardware Requirements

- STM32 Blue Pill development board
- Normally-open push-button
- External LED
- 220–330 Ω current-limiting resistor
- Breadboard and jumper wires
- USB power supply

## 3. Hardware Connections

| Component / Signal | Connection |
|---|---|
| Push-button SW1 | 3.3 V to PA0 when pressed |
| LED D1 Anode | PA1 through 220–330 Ω resistor |
| LED D1 Cathode | GND |
| Board Power | USB / regulated 3.3 V |

### GPIO Configuration

| Pin | Mode | Configuration |
|---|---|---|
| PA0 | GPIO Input | Internal Pull-Down |
| PA1 | GPIO Output | Push-Pull |

## 4. Circuit Diagram

![CAT8B Circuit Diagram](circuit.png)

## 5. Working Principle

Mechanical push-buttons may produce multiple rapid HIGH/LOW transitions when their contacts make or break. This phenomenon is called **switch bouncing**. Without debouncing, a single physical press may be detected as multiple button presses.

The firmware implements a non-blocking debounce routine called `Switch_Update()`.

The routine works as follows:

1. Read the raw switch state using `HAL_GPIO_ReadPin()`.
2. Compare the current raw state with the previous raw reading.
3. If the raw state changes, update the previous state and record the current time using `HAL_GetTick()`.
4. Accept the new state only when it remains unchanged for at least 30 ms.
5. When the accepted stable state becomes HIGH, toggle the LED using `HAL_GPIO_TogglePin()`.

The main loop continues executing during the debounce interval without using `HAL_Delay()`.

## 6. Core Logic / Pseudocode

1. Initialize HAL and configure the system clock.
2. Configure PA0 as GPIO input with internal pull-down.
3. Configure PA1 as push-pull output.
4. Set the debounce interval to 30 ms.
5. Read the raw push-button state.
6. If the raw state changes, update the previous state and timestamp.
7. Check whether the input has remained stable for 30 ms.
8. If the stable state differs from the accepted state, update it.
9. If the accepted state is HIGH, toggle the LED once.
10. Repeat continuously.

## 7. HAL Functions Used

- `HAL_Init()` – Initializes the HAL library and SysTick time base.
- `HAL_GPIO_ReadPin()` – Reads the raw push-button input.
- `HAL_GetTick()` – Measures the input stability duration.
- `HAL_GPIO_TogglePin()` – Toggles the LED on a valid press event.

## 8. Expected Observation

- Each physical button press should toggle the LED exactly once.
- Releasing the button should not produce another toggle.
- Contact bouncing should not cause multiple LED toggles.
- The application should continue running without blocking delays.

## 9. Inference

The experiment demonstrates event-based GPIO input handling and software debouncing using the STM32 HAL framework.

By accepting a switch state only after it remains stable for 30 ms, the firmware filters short contact-bounce transitions and generates one toggle event per valid button press.

## 10. Project Files

- `Core/Src/main.c` – Main application source code and debounce routine.
- `Core/Inc/main.h` – Application and HAL declarations.
- `Blinky.ioc` – STM32CubeMX configuration.
- `MDK-ARM/Blinky.uvprojx` – Keil project file.
- `MDK-ARM/startup_stm32f103xb.s` – Startup assembly file.
- `circuit.png` – Hardware circuit diagram.

## 11. Safety and Wiring Checks

- Connect the push-button between PA0 and 3.3 V.
- Ensure PA0 is configured with an internal pull-down.
- Never apply 5 V directly to PA0.
- Use a 220–330 Ω current-limiting resistor with the external LED.
- Verify LED polarity before powering the circuit.
- Ensure all components share a common ground.
