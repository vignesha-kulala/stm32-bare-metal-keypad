# STM32 Bare Metal Keypad

A 4×4 Matrix Keypad interfacing project using the **STM32C031C6** microcontroller. This project is implemented in **Embedded C** using **direct register programming (Bare Metal)** without relying on the STM32 HAL or external libraries.

---

## Features

- Direct register-level programming
- GPIO configuration using STM32 registers
- 4×4 matrix keypad scanning
- Internal pull-up resistor configuration
- Detects key presses and prints the corresponding key
- Implemented without HAL or CubeMX

---

## Hardware

- STM32 NUCLEO-C031C6
- 4×4 Matrix Keypad

---

## Pin Connections

| STM32 Pin | Keypad Pin | Function                      |
|-----------|------------|-------------------------------|
| PA4       | R1         | Row 1 (Output)                |
| PA5       | R2         | Row 2 (Output)                |
| PA6       | R3         | Row 3 (Output)                |
| PA7       | R4         | Row 4 (Output)                |
| PB11      | C1         | Column 1 (Input with Pull-up) |
| PB12      | C2         | Column 2 (Input with Pull-up) |
| PB13      | C3         | Column 3 (Input with Pull-up) |
| PB14      | C4         | Column 4 (Input with Pull-up) |

---

## Project Structure

```text
stm32-bare-metal-keypad/
├── LICENSE
├── README.md
├── main.c
├── diagram.json
├── images/
│   └── wiring.png
└── docs/
    └── circuit.png
```

---

## Circuit Diagram

See:

- `docs/circuit.png`

---

## Wiring

See:

- `images/wiring.png`

---

## Software

- VS code
- Wokwi Simulator

---

## Future Improvements

- Software debouncing
- Modular keypad driver (`keypad.c` / `keypad.h`)
- UART output support
- LCD interface
- Interrupt-based keypad detection

---

## Author

**Vignesha Kulala**

---

## License

This project is licensed under the MIT License.
