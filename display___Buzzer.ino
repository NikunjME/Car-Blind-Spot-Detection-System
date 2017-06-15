#include <LiquidCrystal.h> //Please replace the single quote characters ('') with the parenthesis character (<>)

LiquidCrystal lcd(1, 2, 4, 5, 6, 7); // Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7)

const int trigPin = 9;   // define the HC-SR04 pins
const int echoPin = 10;
const int buzzer = 11;
const int ledPin = 13;
long duration;
int distanceCm,distanceInch;
int safetyDistance;
int distance;


void setup() {
  
lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(buzzer, OUTPUT);
pinMode(ledPin, OUTPUT);
//Serial.begin(9600); // Starts the serial communication
}

void loop() {
// Clears the trigPin  
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
safetyDistance = distance;
distance= duration*0.034/2;
distanceCm= duration*0.034/2;
distanceInch = duration*0.0133/2;

if (safetyDistance <= 50){
  digitalWrite(buzzer, HIGH);
  digitalWrite(ledPin, HIGH);
}
else{
  digitalWrite(buzzer, LOW);
  digitalWrite(ledPin, LOW);
}
Serial.print("Distance: ");
Serial.println(distance);
lcd.setCursor(0,0); // Sets the location at which subsequent text written to the LCD will be displayed
lcd.print("Distance: "); // Prints string "Distance" on the LCD
lcd.print(distanceCm); // Prints the distance value from the sensor
lcd.print("  cm");
delay(10);
lcd.setCursor(0,1);
lcd.print("Distance: ");
lcd.print(distanceInch);
lcd.print("inch");
delay(10);

}

