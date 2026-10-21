# ESP32 PS5 Basic
ESP32 Radio Controlled code using PS5 controller

This is a simple code for controlling two motors with ESP32 Devkit.

It was made with the library ps5-esp32 by rodneybakiskan:
https://github.com/rodneybakiskan/ps5-esp32

## Features
- Variable speed using PS5 triggers
- Direction control (forward / backward / left / right)
- Deadzone handling
- Safety stop on controller disconnect

## How to find your MAC Address (Windows)
Before you can connect your controller you must get your controller's MAC address

### Steps:
1. Connect your control via Bluetooth to your PC
2. Open Device Manager
3. Go Bluetooth section
4. Find your control
5. Right click on your controller's name and pick properties
6. Details
7. Search "Bluetooth device address"
8. You must see 12 characters, this is your controller's MAC address
