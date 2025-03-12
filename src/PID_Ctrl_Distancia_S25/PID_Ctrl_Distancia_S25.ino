#include <Wire.h>
#include "Adafruit_VL53L0X.h"
Adafruit_VL53L0X lox = Adafruit_VL53L0X();

int set_point = 120;
float pid, salida, h, tk, tk_1, error, u_error, I, D;
float Kp =4, Ki = 0, Kd = 1;

#define motorA1 4
#define motorAD 2

void setup() {
  Serial.begin(9600);
  Wire.begin(12, 14); // Configurar SDA y SCL en el ESP8266
  // wait until serial port opens for native USB devices
  while (!Serial) {
    delay(1);
  }

  Serial.println("Adafruit VL53L0X test");
  if (!lox.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while (1);
  }
  // power
  //Serial.println(F("VL53L0X API Simple Ranging example\n\n"));  // put your setup code here, to run once:
  pinMode(motorA1, OUTPUT);
  pinMode(motorAD, OUTPUT);
}

void loop() {
  VL53L0X_RangingMeasurementData_t measure;

  //Serial.print("Reading a measurement... ");
  lox.rangingTest(&measure, false);  // pass in 'true' to get debug data printout!

  if (measure.RangeStatus != 4) {  // phase failures have incorrect data
    //Serial.println(measure.RangeMilliMeter);
    Serial.println(pid);
  } else {

  }
  tk = millis();
  h = tk - tk_1;
  error = set_point - measure.RangeMilliMeter;
  I = I + (error * h);
  D = (error - u_error) / h;
  pid = (error * Kp) + (I * Ki) + (D * Kd);
  u_error = error;
  tk_1 = tk;

  if (pid > 120) {
    pid = 120;
  }
  else if (pid < -120) {
    pid = -120;
  }

  if (pid < 0) {
    digitalWrite(motorAD, 0);
    salida = map(pid, -200, 0, 255, 0);
    analogWrite(motorA1, pid * -1);  //pa´ atras
  }

  else {
    digitalWrite(motorAD, 1);
    salida = map(pid, 0, 100, 0, 255);
    analogWrite(motorA1, pid);  //pa´ enfrente
  }
}
