#include <ESP32Servo.h>
#include <Arduino.h>
#include <esp_now.h>
#include <WiFi.h>
#include <function.h>



// 接收端
// MAC Address -> 8C:CE:4E:A6:AF:F8

/*
Servo        ESP32
GND(棕)  ->   GND
VCC(紅)  ->   5V  
PWD(橘)  ->   P13
*/

Servo myservo;
Motor m;


int servoPin = 13;


void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&j, incomingData, sizeof(j));
  Serial.print("X = ");Serial.print(j.x); Serial.print(" | Y = "); Serial.print(j.y); Serial.print(" | Button = "); Serial.println(j.button);
  myservo.write(j.y);
  if (j.x >70 && j.x<100){
    m.stop();
  }else if(j.x<82){
    m.forward();
  }else if(j.x>86){
    m.backwards();
  }
 
}



 
void setup() {
  Serial.begin(9600);
  WiFi.mode(WIFI_STA);

  myservo.setPeriodHertz(50); 
  myservo.attach(servoPin);

  pinMode(m.motor1Pin1, OUTPUT);
  pinMode(m.motor1Pin2, OUTPUT);
  pinMode(m.enable1Pin, OUTPUT);
  ledcSetup(m.pwmChannel, m.freq, m.resolution);
  ledcAttachPin(m.enable1Pin, m.pwmChannel);

  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  esp_now_register_recv_cb(OnDataRecv);
}
void loop(){
  // myservo.write(0);
  // delay(1000);
  // myservo.write(45);
  // delay(1000);
  // myservo.write(90);
  // delay(1000);
}






