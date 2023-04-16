#include <LiquidCrystal.h> // includes the LiquidCrystal Library 
LiquidCrystal lcd(8, 3, 4, 5, 6, 7); // Creates an LCD object. Parameters : (rs, enable, d4, d5, d6, d7) 

// Ultrasonic Sensor testing code. Written by a 13 year old.
 // Imports the NewPing Library.
int ledPin =(13); // Add the onboard LED on pin 13.
int trigPin = (10); // Add the Trig pin on pin 10.
int echoPin = (9); // Add the ECHO pin on pin 9.
int buzzPin = (2);
int duration, distance; // Add types 'duration' and 'distance'.


void setup(){
  lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display } 
  lcd.print("WELCOME TO SRIT");
  lcd.setCursor(2,1); 
  lcd.print("JABALPUR"); 
  pinMode (ledPin, OUTPUT); // The LED must be controlled by Arduino, it means it is an output type.
  pinMode (trigPin, OUTPUT);// Same as above, the TRIG pin will send the ultrasonic wave.
  pinMode (echoPin, INPUT); // The ECHO pin will recieve the rebounded wave, so it must be an input type.
  pinMode(buzzPin, OUTPUT); // buzz pin is output to control buzzering
}
void loop(){
  lcd.setCursor(0, 1);
  

  digitalWrite (ledPin, LOW); // Here, LOW means off and HIGH means on.
  digitalWrite(buzzPin, LOW);
  digitalWrite (trigPin, HIGH);
  delay(50);
  digitalWrite (trigPin, LOW);
  duration=pulseIn(echoPin,HIGH);
  distance=(duration/2)/29.1;
  
  if(distance <=70 && distance >= 0)
  {  // If the sensor detects an obstacle less than 30 cm in distance, the LED will start to blink.
    digitalWrite (ledPin, HIGH);
    digitalWrite(buzzPin, HIGH);
    delay(50);
  }
  else{
    digitalWrite(buzzPin, LOW);
  }
  
  if(distance >=30){// If no obstacle is there within 30 cm, the Led should turn off.
    digitalWrite (ledPin, LOW);
    digitalWrite(buzzPin, LOW);
  }
  else{
   digitalWrite(buzzPin, LOW);
  }
  
  delay(50);
  Serial.print("cm");
  Serial.println(distance);

}

