#include <Servo.h>

#define motorA1 4
#define motorAD 2
Servo myservo;

void setup() {
  myservo.attach(5); //Pin 1
  pinMode(motorA1, OUTPUT);
  pinMode(motorAD, OUTPUT);
  digitalWrite(motorA1, 0);
  digitalWrite(motorAD, 0);
  myservo.write(90);
  delay(2000);
}

void loop() {

  /*int pos = 89;
    while (pos < 130) {
    digitalWrite(motorAD, 0);
    analogWrite(motorA1, 105);
    //myservo.write(pos);
    delay(5);
    pos++;
    }*/

  digitalWrite(motorAD, 1);
  //analogWrite(motorA1, 105);
  myservo.write(130);
  delay(1000);

  analogWrite(motorA1, 0);
  delay(3000);

  digitalWrite(motorAD, 0);
  //analogWrite(motorA1, 105);
  myservo.write(90);
  delay(1000);

  analogWrite(motorA1, 0);
  delay(3000);

  /*
    myservo.write(90);
    delay(2000);

    digitalWrite(motorAD, 0);
    analogWrite(motorA1, 255);
    delay(2000);
    myservo.write(180);
    delay(700);
    myservo.write(0);
    delay(200);
    analogWrite(motorA1, 0);
    delay(2000);*/
}
