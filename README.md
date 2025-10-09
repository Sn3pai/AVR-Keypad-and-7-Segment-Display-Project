AVR Keypad and 7-Segment Display Project

This project demonstrates interfacing a 4x4 keypad with a 7-segment display using the ATmega328P microcontroller.
When a key is pressed on the keypad, the corresponding digit or symbol is displayed on the 7-segment display.

⚙️ Features

4x4 keypad input scanning using PORTD

7-segment display output via PORTB

Displays numbers (0–9) and letters/symbols (C, F, H, -)

Debounce handling using software delays

Fully compatible with Atmel Studio / Microchip Studio

🧩 Hardware Connections
Component	Port/Pin	Description
Keypad Rows	PD0–PD3	Output to keypad rows
Keypad Columns	PD4–PD7	Input from keypad columns (with pull-ups)
7-Segment Display	PB0–PB7	Segment control pins (a–g, dp)

Ensure your 7-segment display is common cathode and connected properly.

🧠 Working Principle

The microcontroller scans each row of the keypad.

When a key is pressed, the corresponding column goes low.

The program detects the pressed key and displays the mapped value on the 7-segment display.

🛠️ Requirements

Microcontroller: ATmega328P

Clock: 16 MHz

Software: Microchip Studio / Atmel Studio

Programmer: USBasp or Arduino as ISP

🚀 How to Run

Open the .cpp file in Microchip Studio.

Connect the circuit according to the pin configuration above.

Build and flash the program onto the ATmega328P.

Press any key on the keypad — it will appear on the 7-segment display!
