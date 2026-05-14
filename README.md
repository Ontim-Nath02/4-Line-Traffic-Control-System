# Arduino-Based 4-Way Traffic Light Control System with Countdown Timer
# Overview
This project is a 4-way road traffic control system built using an Arduino Uno. It simulates a real-life traffic intersection where two opposite roads operate at the same time, while the other two remain stopped.
A 2-digit 7-segment display is used to show the remaining countdown time for each signal phase.
# Features
1. 4-road traffic system (A, B, C, D)
2. Opposite roads run simultaneously (A+C and B+D)
3. Real-time countdown display
4. Automatic signal switching
5. Built using discrete LEDs and shift register (74HC595)
# Working Principle
The system operates in 4 phases:
1. Phase 1: Road A & C → Green & Road B & D → Red
2. Phase 2: Road A & C → Yellow
3. Phase 3: Road B & D → Green & Road A & C → Red
4. Phase 4: Road B & D → Yellow
Each phase includes a countdown timer displayed on a 7-segment display.
# Components Used
1. Arduino Uno
2. 74HC595 Shift Register
3. 2-digit 7-Segment Display (Common Anode)
4. 12 × LEDs (Red, Yellow, Green × 4 roads)
5. 220Ω Resistors
6. Connecting wires
7. Proteus (for simulation)
# Code Explanation
1. Shift Register is used to reduce Arduino pin usage
2. Multiplexing is used to control both digits of the display
3. countdown() function handles time display
4. displayNumber() refreshes display continuously
5. Traffic phases are controlled inside loop()
# Circuit
<img width="1265" height="872" alt="Circuit_Sch" src="https://github.com/user-attachments/assets/9395e846-18b6-4867-a713-9146176a274e" />
# Simulation Preview
<img width="1275" height="888" alt="Simulation" src="https://github.com/user-attachments/assets/e1b54fdc-7651-4f06-85f8-ab04aa1a0fc0" />
# Future Improvements
1. Add vehicle detection sensors 
2. Use LCD display instead of 7-segment 
3. Implement adaptive traffic control
4. Add pedestrian crossing system 🚶

