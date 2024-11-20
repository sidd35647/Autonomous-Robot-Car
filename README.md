

# Autonomous Robot Car

This project implements an autonomous robot car that can navigate through obstacles using ultrasonic sensors and servo motors. The robot is programmed to move forward until it detects an obstacle within a certain distance. Upon detecting an obstacle, the robot will stop, analyze the surroundings by checking both the left and right directions, and then decide the best course of action to avoid the obstacle.

## Table of Contents

- [Features](#features)
- [Components](#components)
- [Circuit Diagram](#circuit-diagram)
- [Code Explanation](#code-explanation)
- [Setup Instructions](#setup-instructions)
- [Usage](#usage)

## Features

- Autonomous navigation with obstacle avoidance.
- Distance measurement using ultrasonic sensors.
- Decision-making to determine the optimal direction to avoid obstacles.
- Servo motor control for directional checking.
- Motor control for forward, backward, left, and right movements.

## Components

- Arduino Uno
- Ultrasonic Sensor (HC-SR04)
- Servo Motor (SG90)
- L298N Motor Driver Module
- DC Motors (for wheels)
- Battery Pack
- Jumper Wires
- Breadboard
- Chassis for mounting the components

## Circuit Diagram

Here’s a basic outline of how to connect the components:

- **Servo Motor**: Connect the control pin to Arduino pin 5.
- **Ultrasonic Sensor**: 
  - Trigger pin to Arduino pin 4.
  - Echo pin to Arduino pin 10 (or 3 in the second code).
- **Motor Driver Module**:
  - Enable pins to Arduino pins 3 and 5.
  - Motor control pins for Motor A to Arduino pins 8 and 9.
  - Motor control pins for Motor B to Arduino pins 6 and 7.
  - Power the motors using a suitable power source.

## Code Explanation

The code consists of two parts:

### 1. **Obstacle Detection and Avoidance**
   - The ultrasonic sensor measures the distance to obstacles.
   - If an obstacle is detected within 30 cm (or 20 cm in the second code), the robot stops.
   - The servo motor checks the left and right directions to determine the clearest path.
   - The robot then turns in the direction with the most space and continues moving forward.

### 2. **Motor Control**
   - The L298N motor driver controls the movement of the robot's wheels.
   - The robot can move forward, backward, left, and right based on the input from the ultrasonic sensor.

### 3. **Servo Motor Control**
   - The servo motor is used to rotate the ultrasonic sensor to check left and right directions before deciding the best path.

## Setup Instructions

1. **Wiring:**
   - Connect all components according to the circuit diagram provided above.

2. **Uploading the Code:**
   - Open the Arduino IDE.
   - Connect your Arduino board to your computer.
   - Copy the provided code and paste it into the Arduino IDE.
   - Select the appropriate board and port from the 'Tools' menu.
   - Click on the 'Upload' button to upload the code to the Arduino.

3. **Powering the Robot:**
   - Use a suitable battery pack to power the Arduino and the motors.
   - Ensure that the power supply is sufficient for the motors and the Arduino board.

## Usage

- Once powered on, the robot will start moving forward.
- If an obstacle is detected, it will stop and check the surrounding environment.
- The robot will choose the best direction and continue moving to avoid obstacles.
