# Detection System 

### 📌 Overview
This project implements an obstacle detection system for a car using Arduino.  
It detects objects from four directions:
- Front Left
- Front Right
- Bottom Left
- Bottom Right  
Based on the distance, the system provides visual (LED) and audio (buzzer) alerts.

---

## ⚙️ Features
- Detects obstacles using ultrasonic sensors
- Covers 4 directions around the vehicle
- LED indication for each direction
- Buzzer alert with variable frequency:
  - 🔊 Slow beep (0.5s gap) → object < 80 cm
  - 🔊 Fast beep (0.2s gap) → object < 30 cm
- Real-time distance monitoring

---

## 🔌 Hardware Components
- Arduino UNO  
- 4 × Ultrasonic Sensors 
- 4 × LEDs  
- 1 × Buzzer  
- Resistors  
- Breadboard & jumper wires  

---

## Circuit Diagram
<img width="500" height="500" alt="Circuit" src="https://github.com/user-attachments/assets/b5f22aff-4559-4554-837d-e7e03cb2795c" />


---

### 🔗 TinkerCAD Simulation
https://www.tinkercad.com/things/dWy3pQvCsDe-detection-system?sharecode=NS0Cak75f5zy_ONAfkO_vNoR56v0EtluCmhf-OkQWoo

## 🚀 How to Run
1. Open the TinkerCAD link above
2. Click ```Start Simulation```
3. Place an object in front of any ultrasonic sensor  
4. Observe behavior:
   - LED turns ON for the detected direction  
   - Buzzer beeps:
     - Slow (0.5s gap) → distance < 80 cm  
     - Fast (0.2s gap) → distance < 30 cm  

‼️Note: This project is shared for career-related purposes. If used for academic coursework, please follow your institution’s academic integrity policy.

