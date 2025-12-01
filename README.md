
# Arduino Radar Tracking System

A simple **Arduino-based Radar Tracking System** using a **Servo Motor**, **Ultrasonic Sensor (HC-SR04)**, and **Arduino Uno**.  
The servo sweeps 0–180° while the ultrasonic sensor measures distance and plots objects on a radar-style display.

---

## 📸 Circuit Connection Diagram (Reference Images)

### **Ultrasonic Sensor (HC-SR04) Connections**
![SONAR](sonar.png)

| Pin | Arduino Pin |
|-----|-------------|
| **VCC** | 5V |
| **GND** | GND |
| **Trig** | Pin 10 |
| **Echo** | Pin 11 |

---

### **Servo Motor (SG90) Connections**
![SERVO](servo.png)

| Servo Wire | Arduino Pin |
|------------|-------------|
| **Red**        | 5V |
| **Black/Brown**| GND |
| **Yellow/Orange** | Pin 12 |

---

## 🧰 Required Components

- Arduino Uno  
- SG90 Servo Motor  
- HC-SR04 Ultrasonic Sensor  
- Breadboard  
- Jumper Wires  
- USB Cable  

---

## ⚡ Circuit Summary

- The **Servo** rotates from **0° to 180°** and back.
- The **Ultrasonic Sensor** measures object distance at each angle.
- Data is sent to Serial Monitor or radar GUI.

---

## 🧠 Working Principle

1. Servo rotates from 0° → 180° in steps.
2. At each angle, ultrasonic sensor sends a pulse and measures return_echo.
3. Distance is calculated using speed of sound formula:
   ```
   distance = (duration × 0.034) / 2
   ```
4. Arduino outputs angle + distance values.

---

## 🧾 Arduino Code Example

```cpp
#include <Servo.h>

Servo myservo;

const int trigPin = 10;
const int echoPin = 11;
long duration;
int distance;

void setup() {
  Serial.begin(9600);
  myservo.attach(12);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  for (int angle = 0; angle <= 180; angle++) {
    myservo.write(angle);
    distance = getDistance();
    Serial.print(angle);
    Serial.print(",");
    Serial.println(distance);
    delay(50);
  }

  for (int angle = 180; angle >= 0; angle--) {
    myservo.write(angle);
    distance = getDistance();
    Serial.print(angle);
    Serial.print(",");
    Serial.println(distance);
    delay(50);
  }
}

int getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  int dist = duration * 0.034 / 2;
  return dist;
}
```

---

## 🧩 Folder Structure

```
Radar-Tracking-System/
│-- README.md
│-- radar.ino
│-- images/
    │-- sonar.png
    │-- servo.png
```

---

## ✔ Future Improvements

- Add OLED/LCD screen  
- Add buzzer for alerts  
- Add Bluetooth/WiFi  
- Create 3D printed rotating base  

---

## 👨‍💻 Author

**Tejas – Arduino Radar Tracking System**

