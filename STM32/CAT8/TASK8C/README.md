# CAT 8 — Task 8C: Short Press vs Long Press

## Experiment details

- **Course:** 25CS2741 — Fundamentals of Internet of Things + Lab
- **Assessment:** Continuous Lab Evaluation 8C
- **Date on assignment:** 18/09/2026
- **Experiment:** STM32 Short Press vs Long Press Classification
- **Board:** STM32 Blue Pill (STM32F103C8T6)
- **IDE / framework:** STM32CubeMX, Keil MDK-ARM, STM32 HAL

## Aim

Classify a button press by its duration and control the LED according to the assignment:

| User action | Required system response |
|---|---|
| Short press (< 1 second) | Toggle LED |
| Long press (≥ 1 second) | Enter continuous blinking mode |
| Next short press | Stop blinking |
| Long press again | Return to blinking mode |

## Hardware setup

| Component / signal | Connection | Configuration |
|---|---|---|
| Push-button SW1 | 3.3 V to PA0 when pressed | PA0 input with internal pull-down |
| LED D1 anode | PA1 through 220–330 Ω resistor | PA1 push-pull output |
| LED D1 cathode | GND | Common ground |

The button is normally open. PA0 is LOW when released and HIGH when pressed. The external LED is driven by PA1 through a series current-limiting resistor.

## Circuit diagram

![Task 8C circuit diagram](circuit.png)

## Working principle

The firmware uses a non-blocking state machine. It does not wait inside a delay to decide whether a press is long.

1. `Switch_Update()` debounces the PA0 input using a 30 ms stability interval.
2. When a debounced press is detected (PA0 becomes HIGH), the firmware records `pressStart = HAL_GetTick()`.
3. The main loop continues executing while the button is held.
4. When the debounced release is detected (PA0 becomes LOW), the firmware calculates `duration = HAL_GetTick() - pressStart`.
5. If the duration is at least **1000 ms**, the firmware enables blinking mode.
6. If the duration is less than 1000 ms, it is a short press:
   - If blinking is active, blinking is stopped.
   - Otherwise, the LED is toggled.
7. While blinking is active, the LED is toggled every **250 ms** using `HAL_GetTick()`.

A long press after blinking has been stopped enables blinking again, as required by the assignment. `HAL_GetTick()` subtraction is used for elapsed-time calculations, which also works across tick-counter rollover.

## Core logic / pseudocode

1. Initialize HAL, system clock and GPIO.
2. Configure PA0 as input with pull-down and PA1 as output.
3. Set debounce interval = 30 ms, long-press threshold = 1000 ms, blink interval = 250 ms.
4. Continuously call the non-blocking switch update routine.
5. On a debounced press, record the start tick.
6. On a debounced release, calculate the press duration.
7. If duration ≥ 1000 ms, enable blinking.
8. Otherwise, if blinking is active, stop blinking; if not, toggle the LED.
9. If blinking is active and 250 ms has elapsed, toggle the LED.
10. Repeat continuously.

## HAL functions used

- `HAL_GPIO_ReadPin()` — read the button.
- `HAL_GetTick()` — record press time, calculate duration and schedule LED blinking.
- `HAL_GPIO_TogglePin()` — toggle the LED output.
- `HAL_GPIO_WritePin()` — initialize the LED output.
- `HAL_Init()` — initialize HAL and SysTick.

## Important constraint

**Do not use `HAL_Delay()` or another blocking delay to detect a long press.** The application must continue executing while the button is held. The implementation uses `HAL_GetTick()` for both press-duration measurement and non-blocking blink timing.

## Expected observation / result

- A press shorter than 1 second toggles the LED once.
- A press lasting 1 second or longer enables continuous blinking.
- A short press while blinking stops the blinking.
- A subsequent long press re-enters blinking mode.

Record the result observed on your own hardware before submission.

## Inference

This task demonstrates non-blocking time-based event classification using the STM32 HAL millisecond tick. The press duration determines whether the application performs a short-press toggle or enters blinking mode. The debounce and blink timing logic allow the main loop to remain responsive without blocking delays.

## Files

- `Core/Src/main.c` — application state machine and timing logic.
- `Core/Inc/main.h` — application and HAL declarations.
- `Blinky.ioc` — STM32CubeMX configuration.
- `MDK-ARM/Blinky.uvprojx` — Keil project.
- `MDK-ARM/startup_stm32f103xb.s` — startup code.
- `circuit.png` — wiring diagram.

## Safety and wiring checks

- Connect the button between PA0 and 3.3 V; PA0 uses an internal pull-down.
- Never apply 5 V to PA0.
- Use a 220–330 Ω series resistor with the LED.
- Check the LED anode/cathode orientation before powering the board.
