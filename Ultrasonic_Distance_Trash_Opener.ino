//URL used below for HC-SR04 (Ultrasound Sensor) Part
//https://create.arduino.cc/projecthub/Isaac100/getting-started-with-the-hc-sr04-ultrasonic-sensor-036380

#include <DHT.h>
#include <DHT_U.h>

#include <Servo.h>

const unsigned int TRIG_PIN=13;
const unsigned int ECHO_PIN=12;
const unsigned int BAUD_RATE=9600;
Servo myservo;


void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.begin(BAUD_RATE);
  myservo.attach(9);
}

void loop() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  

 const unsigned long duration= pulseIn(ECHO_PIN, HIGH);
 int distance= duration/29/2;
 //distance = map(distance, 0, 1023, 0, 180);
 if(duration==0){
   Serial.println("Warning: no pulse from sensor");
   } 
   if(distance < 10){     //Activates Servo Motor when object is within 10 cm
    myservo.write(80);
    Serial.print("distance to nearest object:");
      Serial.println(distance);
      Serial.println(" cm");
   }
  else{                  //Returns Servo Motor Position to close
      Serial.print("distance to nearest object:");
      Serial.println(distance);
      Serial.println(" cm");
      myservo.write(0);       
      
  }
 delay(250);
 
 }
