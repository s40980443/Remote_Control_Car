#include <Arduino.h>
#include <esp_now.h>
#include "WiFi.h"
#include "function.h"




// 發送端
// MAC Address -> B8:D6:1A:81:8E:5C


Joystick J1;

// Receive MAC address
uint8_t broadcastAddress[] = {0x8C, 0xCE, 0x4E, 0xA6, 0xAF, 0xF8};

//增加一個PEER到名單列
esp_now_peer_info_t peerInfo;

void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  Serial.print("\r\nLast Packet Send Status:\t");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}

void setup() {
  Serial.begin(9600); 
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP); 
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  //Get Status
  esp_now_register_send_cb(OnDataSent);

  // Register peer
  memcpy(peerInfo.peer_addr, broadcastAddress, 6);
  peerInfo.channel = 0;  
  peerInfo.encrypt = false;
  
  // Add peer        
  if (esp_now_add_peer(&peerInfo) != ESP_OK){
    Serial.println("Failed to add peer");
    return;
  }
  
}


void loop() {
  Serial.print("X: ");Serial.print(J1.joystickX());Serial.print(" | Y: ");Serial.print(J1.joystickY());Serial.print(" | Button: ");Serial.println(J1.joystickButton());

  j.x = J1.joystickX();
  j.y = J1.joystickY();
  j.z = J1.joystickButton();

   esp_err_t result = esp_now_send(broadcastAddress, (uint8_t *) &j, sizeof(j));
   
  // if (result == ESP_OK) {
  //   Serial.println("Sent with success");
  // }
  // else {
  //   Serial.println("Error sending the data");
  // }
  delay(10);
  
}



