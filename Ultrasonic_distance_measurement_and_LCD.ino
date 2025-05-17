// C++ code
// Using LCD DIsplay with Arduino

#include <LiquidCrystal.h>	// Loading the Liquid Crystal library

LiquidCrystal LCD(10, 9, 5, 4, 3, 2);	// Creating the liquid crystal object named LCD

// Initializing Pins and variables for Ultrasonic Sensor
int trigPin = 13, echoPin = 11;	
float pingTime, targetDistance;

float speedOfSound = 776.5;	// Speed of sound in miles per hour

void setup()
{
  
  Serial.begin(9600);	// Turning on the Serial Monitor
  
  // Setting the pins of the Sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Setting the LCD Display
  LCD.begin(16,2);	
  LCD.setCursor(0,0);	
  LCD.print("Target Distance: ");	// Printing our first line
  
}

void loop()
{
  
  // Operating the trigger pin of the sensor
  digitalWrite(trigPin, LOW);	
  delayMicroseconds(2000);		
  digitalWrite(trigPin, HIGH);	
  delayMicroseconds(15);		
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);		
  
  pingTime = pulseIn(echoPin, HIGH)/(3600 * 1000000.);	// Measuring ping time in hours using echo pin of the sensor
  
  targetDistance = ((speedOfSound * pingTime)/2) * 63360;	// Measuring distance from the echo pin to target in inches
  
  // Displaying the distance in the LCD monitor
  LCD.setCursor(0,1);	
  LCD.print("                ");	// Clears row two after each operation
  LCD.setCursor(0,1);				
  
  if (targetDistance <= 132) {
    
  	LCD.print(targetDistance);	
  	LCD.print(" inches");		
    
  } else {
  
    LCD.print("Seems safe...");	// Message for out of range
    
  }
  delay(250);	// Pausing not to make the display jittery
  
}