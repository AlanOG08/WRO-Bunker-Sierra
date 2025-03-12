#include <Servo.h>
#include <Wire.h>
#include "Adafruit_VL53L0X.h"
Adafruit_VL53L0X lox = Adafruit_VL53L0X();

#define motorA1 4
#define motorAD 2
Servo myservo;

void setup() {
  Serial.begin(9600);
  myservo.attach(5); //Pin 1
}

void loop() {


}
