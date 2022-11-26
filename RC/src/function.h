
#include <Arduino.h>
#define VRx 33
#define VRy 32
#define SW 26



/*
Joystick     ESP32
GND      ->   GND
5V       ->    5V
VRX      ->    34
VRY      ->    35
SW       ->    26 
 */
struct joystick{
  int x;
  int y;
  int z;
}j;

class Joystick{
    public:
        
        int xPosition = 0;
        int yPosition = 0;
        int SW_state = 0;
        int mapX = 0;
        int mapY = 0;

        int joystickX();
        int joystickY();
        int joystickButton();
};
int Joystick::joystickX(){
    xPosition = analogRead(VRx);
    mapX = map(xPosition, 0, 4095, 0, 180);
    return mapX;
}
int Joystick::joystickY(){
  yPosition = analogRead(VRy);
  mapY = map(yPosition, 0, 4095, 0, 180);
  return mapY;
}
int Joystick::joystickButton(){
  return digitalRead(SW);
}


// int xPosition = 0;
// int yPosition = 0;
// int SW_state = 0;
// int mapX = 0;
// int mapY = 0;

// int joystickX(){
//   xPosition = analogRead(VRx);
//   mapX = map(xPosition, 0, 4095, 0, 180);
//   // Serial.print("X = ");
//   // Serial.println(xPosition);
//   return mapX;
// }

// int joystickY(){
//   yPosition = analogRead(VRy);
//   mapY = map(yPosition, 0, 4095, 0, 180);
//   // Serial.print("Y = ");
//   // Serial.println(yPosition);
//   return mapY;
// }


// int joystickButton(){
//   return digitalRead(SW);
// }
