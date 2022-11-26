#include <Arduino.h>

struct recevice_joystick {
    int x;
    int y;
    int button;
}j;

class Motor{
    public:
        int motor1Pin1 = 27; 
        int motor1Pin2 = 26; 
        int enable1Pin = 14; 

        // Setting PWM properties
        const int freq = 30000;
        const int pwmChannel = 2;
        const int resolution = 8;
        int dutyCycle = 255;
        bool run = false;
        void forward();
        void backwards();
        void stop();
};

void Motor::forward(){
    digitalWrite(motor1Pin1, HIGH);
    digitalWrite(motor1Pin2, LOW); 
}

void Motor::backwards(){
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, HIGH); 
}
void Motor::stop(){
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, LOW); 
}




