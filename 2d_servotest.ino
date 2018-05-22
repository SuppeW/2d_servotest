#include <Servo.h>

Servo servo1;
Servo servo2;

int Xpos = 90, Ypos = 90, XposLast = 90, YposLast = 90;

const int servoX_pin = 1;
const int servoY_pin = 2;
const int JoyX_pin = 3;
const int JoyY_pin = 4;
const int laser_pin = 5;
const int button_pin = 6;
const int led_pin = 13;

int button;
int oldBtn = 0;
int switchState = 0;



void setup() {
  servo1.attach(servoX_pin);
  servo2.attach(servoY_pin);
}

void loop() {
  if(analogRead(JoyX_pin < 500) || analogRead(JoyX_pin > 520)||analogRead(JoyY_pin < 500) || analogRead(JoyY_pin > 520)){
    Xpos = analogRead(JoyX_pin);
    Ypos = analogRead(JoyY_pin);
    Xpos = map(Xpos,0,1023,0,180);
    Ypos = map(Ypos,0,1023,0,180);
    Xpos = (90-Xpos)/10;
    Ypos = (90-Ypos)/10;
    XposLast = Xpos;
    YposLast = Ypos;
    
    if(XposLast<0){
      XposLast = 0;
    }else if(XposLast>180){
      XposLast = 180;
    }else if(YposLast<0){
      YposLast = 0;
    }else if(YposLast>180){
      YposLast = 180;
    }
  }
  
  servo1.write(XposLast);
  servo2.write(YposLast);

  digitalRead(button_pin);
  if(button && !button){
    if(switchState == 0){
      digitalWrite(laser_pin, HIGH);
      digitalWrite(led_pin, HIGH);
      switchState = 1;
    }else{
      digitalWrite(laser_pin, HIGH);
      digitalWrite(led_pin, HIGH);
      switchState = 0;
    }
    oldBtn = 1;
  }else if(button && !button){
    oldBtn = 0;
  }
  
  delay(50);
}
