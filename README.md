
# Arduino Radar Tracking System

This project is a complete radar-style distance detection system built using an Arduino Uno, HC-SR04 Ultrasonic Sensor, SG90 Servo Motor, and a Processing-based GUI. The servo sweeps across a defined angle range while the ultrasonic sensor measures distance at each step. The readings are then visualized in real time on a radar interface created using the Processing IDE.

---

## Project Overview

The radar system works by continuously rotating a servo motor from 15° to 165° and back. At each degree, the ultrasonic sensor measures the distance to any obstacles in front of it. The Arduino sends angle and distance data to the computer through serial communication. The Processing sketch reads this data and displays it on a radar screen similar to traditional scanning radars.

---

## Components Used

- Arduino Uno  
- HC-SR04 Ultrasonic Sensor  
- SG90 Servo Motor  
- Jumper Wires  
- Breadboard (optional)  
- USB Cable  
- Processing IDE (for visualization)

---

## Hardware Connections

### Ultrasonic Sensor (HC-SR04)
- VCC → Arduino 5V  
- GND → Arduino GND  
- Trig → Arduino Pin 10  
- Echo → Arduino Pin 11  

### Servo Motor (SG90)
- Red → 5V  
- Brown/Black → GND  
- Yellow/Orange → Arduino Pin 12  

---

## How the System Works

1. The servo rotates from 15° to 165°, then reverses back.  
2. At each angle step, the ultrasonic sensor:
   - Sends an ultrasonic pulse.
   - Measures the time taken for the echo to return.
   - Calculates the distance based on sound speed.
3. Arduino sends data to the serial port in the format:  
   angle,distance.
4. Processing reads this serial data, parses angle and distance, and plots:
   - Sweep line  
   - Objects detected (within range)  
   - Angle labels  
   - Range markings (10 cm, 20 cm, 30 cm, 40 cm)

---

## Software Required

- Arduino IDE  
- Processing IDE  

---

## Serial Data Format

The Arduino continuously sends values formatted as:

angle,distance.

Example:

45,23.  
46,24.  
47,21.  

- angle = current servo position  
- distance = measured distance from ultrasonic sensor (in cm)  
- '.' indicates packet end

---

## Project Structure

arduino-radar-tracking-system/  
│  
├── Arduino/  
│   └── radar.ino  
│  
├── Processing/  
│   └── radar_visualizer.pde  
│  
└── README.md  

---

## How to Run the Project

### 1. Upload Arduino Code
- Open Arduino IDE  
- Select Arduino Uno  
- Select correct COM port  
- Upload radar.ino  

### 2. Run Processing Radar Interface
- Open Processing IDE  
- Load radar_visualizer.pde  
- Update COM port string  
- Run the sketch  

### 3. View Radar Output  
A sweeping radar line appears, detecting objects in real time.

---

## Testing Tips

- Test with no obstacles first.  
- Place objects at various distances (10–40 cm).  
- Ensure smooth servo movement.  
- Keep ultrasonic sensor unobstructed.

---

## Common Issues & Fixes

### Servo not moving
- Incorrect wiring  
- Low voltage  
- Loose wires  

### Always shows "Out of Range"
- Wrong trig/echo wiring  
- Sensor damaged  
- Object too far  

### Processing window blank
- Wrong COM port  
- Serial port busy  

---

## Future Enhancements

- Add buzzer alert  
- Add OLED/LCD display  
- Add WiFi/Bluetooth  
- Use a 360° servo  
- Add 3D printed base  

---

## Author
Created by Tejas  
Arduino Radar Tracking System
