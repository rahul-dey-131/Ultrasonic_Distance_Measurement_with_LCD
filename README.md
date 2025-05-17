# Ultrasonic Distance Measurement and Display on LCD Using Arduino

🎯 Objective:
To design and implement a system that uses an ultrasonic sensor (HC-SR04) to measure the distance of an object and displays the measured distance in inches on a 16x2 LCD using an Arduino Uno.

🧰 Components Used:
Component	Quantity
Arduino Uno	1
HC-SR04 Ultrasonic Sensor	1
16x2 LCD Display	1
Breadboard	1
Jumper Wires	As required
USB Cable	1
Potentiometer (optional, for LCD contrast)	1 (not used in code)

🔌 Circuit Description:
The system connects:

Ultrasonic Sensor (HC-SR04)

VCC → Arduino 5V

GND → Arduino GND

TRIG → Digital Pin 13

ECHO → Digital Pin 11

LCD Display (16x2) – Interfaced in 4-bit mode

RS → Pin 10

EN → Pin 9

D4 → Pin 5

D5 → Pin 4

D6 → Pin 3

D7 → Pin 2

VSS, RW, K → GND

VDD, A → 5V

The .brd file corresponds to a layout where the components are arranged on a PCB for compactness and reliability. Traces in the layout match the connections described above.

⚙️ Working Principle:
Ultrasonic Measurement:

The HC-SR04 emits an ultrasonic pulse when triggered.

It listens for the echo to return after bouncing off an object.

The time between sending and receiving is used to calculate distance.

Distance Calculation:

The code calculates distance in inches using the formula:

Distance (in)
=
(
Speed of Sound
×
Time
2
)
×
63360
Distance (in)=( 
2
Speed of Sound×Time
​
 )×63360
where time is converted into hours for compatibility with miles/hour unit.

LCD Display:

If the object is within 132 inches (11 feet), it shows the distance.

If farther, it displays “Seems safe...” as a default safety message.

📜 Arduino Code Explanation:
The LiquidCrystal library is used to control the 16x2 LCD.

TRIG and ECHO pins are initialized and controlled to measure echo time.

The echo time is converted to distance using the speed of sound.

The measured value is printed on the LCD and cleared/updated every 250 ms.

If no object is detected within the threshold, a default message appears.

💡 Applications:
Obstacle Detection for Robotics.

Parking Assistance Systems.

Industrial Distance Measurement.

Smart Dustbins (measuring fill levels).

Security Systems.

✅ Conclusion:
This project demonstrates the practical use of an ultrasonic sensor integrated with an Arduino and LCD to provide real-time distance measurement. It’s simple and affordable and serves as a foundation for more complex proximity or safety systems.
