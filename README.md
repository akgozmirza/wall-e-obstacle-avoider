# 🤖 Arduino Obstacle Avoiding Robot

This project is an **autonomous obstacle-avoiding robot** built using an Arduino microcontroller.  
The robot uses an **ultrasonic sensor** to detect objects in front of it and adjusts its movement to avoid collisions.

---

## 🔧 Features

- 🚗 Moves forward automatically  
- 🧠 Detects obstacles using an ultrasonic distance sensor  
- 🔄 Turns left or right based on obstacle distance  
- ⚡ Powered by Arduino  
- 🔌 Motor driver control (L298N or similar)  
- 🟢 Simple, stable and beginner-friendly design  

---

## 🧩 Components Used

| Component | Description |
|----------|-------------|
| Arduino Uno / Nano | Main microcontroller |
| HC-SR04 Ultrasonic Sensor | Distance measurement |
| L298N Motor Driver | Controls DC motors |
| DC Motors + Wheels | Movement |
| Battery Pack | Power source |
| Chassis | Robot body |

---

## 📐 How It Works

1. The ultrasonic sensor continuously measures the distance to any object ahead.  
2. If the distance is **safe (greater than X cm)** → the robot moves forward.  
3. If an obstacle is detected →  
   - The robot stops  
   - Moving back
   - Turn Right  
   - Then continues moving forward  
4. This loop runs infinitely, creating autonomous navigation.

---
