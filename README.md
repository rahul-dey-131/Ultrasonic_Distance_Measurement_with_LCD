# Ultrasonic Distance Measurement and Display on LCD Using Arduino

Have a watch on this video about how it works: 

`https://drive.google.com/file/d/1BfmhSSMNpePDKsVFGZWEaUvG7q3xAmtI/view?usp=sharing`

Simulate yourself: `https://www.tinkercad.com/things/699PmX4uuhb-ultrasonic-distance-measurement-and-displaying-on-lcd)`

🎯 Objective:
To design and implement a system that uses an ultrasonic sensor (HC-SR04) to measure the distance of an object and displays the measured distance in inches on a 16x2 LCD using an Arduino Uno.

 ![image](https://github.com/user-attachments/assets/98acfe6d-040b-40b7-9e08-e459ff91e6ca)


🔌 Circuit Description:

![image](https://github.com/user-attachments/assets/d2dd10da-d5bc-4c6c-a2fd-433b226d2bb0)
 ![image](https://github.com/user-attachments/assets/cbf6fa95-2ec0-4248-95d4-efb6545b2598)



The system connects:

	Ultrasonic Sensor (HC-SR04)

	VCC → Arduino 5V

	GND → Arduino GND

	TRIG → Digital Pin 13

	ECHO → Digital Pin 11

LCD Display (16x2) – Interfaced in 4-bit mode

	RS  → Pin 10
	
	E   → Pin 9
	
	DB4 → Pin 5
	
	DB5 → Pin 4
	
	DB6 → Pin 3
	
	DB7 → Pin 2
	
	GND, RW, V0, LED(Black) → GND
	
	VCC, A, LED(Red) → 5V

The .brd file corresponds to a layout where the components are arranged on a PCB for compactness and reliability. Traces in the layout match the connections described above.

⚙️ Working Principle:
Ultrasonic Measurement:

	The HC-SR04 emits an ultrasonic pulse when triggered.

	It listens for the echo to return after bouncing off an object.

	The time between sending and receiving is used to calculate distance.

Distance Calculation:

	The code calculates distance in inches using the formula:
![image](https://github.com/user-attachments/assets/1625c5e3-f3ac-4199-b686-ff4856ae5e27)
	
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
This project demonstrates the practical use of an ultrasonic sensor integrated with an Arduino and LCD to provide real-time distance measurement. It’s simple, affordable, and a foundation for more complex proximity or safety systems.
