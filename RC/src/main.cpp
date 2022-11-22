#include <Arduino.h>
#include <SoftwareSerial.h>



//HC-06


SoftwareSerial BTSerial(10, 11); // RX | TX
void setup()
{
  Serial.begin(9600);
  Serial.println("Enter AT commands:");
  BTSerial.begin(9600);  // HC-06 current bound rate (default 9600)
}
void loop()
{
  // Keep reading from HC-06 and send to Arduino Serial Monitor
  if (BTSerial.available())
    Serial.write(BTSerial.read());
  
  // Keep reading from Arduino Serial Monitor and send to HC-06
  if (Serial.available())
    BTSerial.write(Serial.read());
}


//JoyStick
// int VRx = A0;
// int VRy = A1;
// int SW = 2;

// int xPosition = 0;
// int yPosition = 0;
// int SW_state = 0;
// int mapX = 0;
// int mapY = 0;

// void setup() {
//   Serial.begin(9600); 
  
//   pinMode(VRx, INPUT);
//   pinMode(VRy, INPUT);
//   pinMode(SW, INPUT_PULLUP); 
  
// }

// void loop() {
//   xPosition = analogRead(VRx);
//   yPosition = analogRead(VRy);
//   SW_state = digitalRead(SW);
//   mapX = map(xPosition, 0, 1023, -512, 512);
//   mapY = map(yPosition, 0, 1023, -512, 512);
//   Serial.print("X: ");
//   Serial.print(mapX);
//   Serial.print(" | Y: ");
//   Serial.print(mapY);
//   Serial.print(" | Button: ");
//   Serial.println(SW_state);

//   delay(100);
  
// }