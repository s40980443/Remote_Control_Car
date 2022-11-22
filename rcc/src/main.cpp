#include <Arduino.h>
#include <ESP32Servo.h>
Servo servo;
int servoPin = 13;

bool servoState = false;
// 酷酷的車車
void setup(){
  servo.setPeriodHertz(50);    // standard 50 hz servo
  servo.attach(servoPin);
  servoState = servo.attached(); //是否連接到引腳 return true or false
}
void loop(){
  servo.read();
  // servo.write(0);
  // delay(1000);
  // servo.write(90);
  // delay(1000);
  // servo.write(180);
  // delay(1000);
}

void _servoSetup(){

}

void left(){

}
void right(){

}


// Servo myservo;  // create servo object to control a servo
 
// // Recommended PWM GPIO pins on the ESP32 include 2,4,12-19,21-23,25-27,32-33 
// int servoPin = 13;
 
// void setup() {
//   myservo.setPeriodHertz(50); 
//   myservo.attach(servoPin);
// }
 
// void loop() {
//   myservo.write(0); 
//   delay(2000);
//   myservo.write(180);
//   delay(2000);
// }