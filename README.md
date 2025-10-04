# SOUND_BASED_LED_ARDUINO_UNO
This project uses an Arduino Uno, LM393 sound sensor, I2C 16x2 LCD, white LED, and buzzer to implement a clap-controlled lighting system that turns ON the LED upon detecting one clap, turns it OFF with two claps, ignores any additional claps beyond two, displays the current LED state on the LCD, and triggers two buzzer beeps each time the LED state changes.
# 🔊 Sound-Based LED System (Arduino UNO)

## Overview
This project demonstrates a sound-activated LED system using Arduino UNO and a sound sensor module. It detects audio input (such as claps or voice) and triggers LED illumination in real time. The repository includes source code, documentation, pin mapping, and circuit visuals for easy replication and understanding.

## Tech Stack
- Arduino UNO (`sound_based_led_system.ino`)
- Sound sensor module (e.g., microphone or clap sensor)
- LED output
- Excel for pin configuration
- Word documentation for system overview

## Files Included
- `sound_based_led_system.ino`: Arduino sketch for sound detection and LED control
- `sound_based_led_system.docx`: Detailed documentation of system design and operation
- `SOUND_BASED_LED_SYSTEM_PIN_OUT.xlsx`: Pin configuration and hardware mapping
- `SOUND_BASED_LED.jpg`: Photo of the physical setup
- `circuit_image(10).png`: Circuit diagram
- `README.md`: Project overview and instructions

## Highlights
- Real-time sound detection and LED response
- Adjustable sensitivity for different sound thresholds
- Modular code structure for easy customization
- Clear documentation and pin mapping for reproducibility
- Visual assets for hardware setup and circuit layout

## How It Works
- The sound sensor detects audio input and sends a signal to the Arduino
- Arduino processes the signal and activates the LED based on sound intensity
- Circuit and pin mapping ensure accurate signal flow and control

## Author
**Manohar** – Embedded Systems Enthusiast  
📫 [GitHub Profile](https://github.com/manohar146)
