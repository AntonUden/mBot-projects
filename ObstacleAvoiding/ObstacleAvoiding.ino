#include "MeMCore.h"

MeUltrasonicSensor ultraSensor(PORT_3);
MeDCMotor motor1(M1);
MeDCMotor motor2(M2);

void setup() {
  //Serial.begin(9600);
}
MeRGBLed led(0,30);
int motorSpeed = -140;

int turnSpeed = -180;
int turnDelay = 800;

int backSpeed = -180;
int backDelay = 1000;

void loop() {
  led.setColorAt(1, 0, 255, 0);
  led.show();
  motor1.run(motorSpeed * -1);
  motor2.run(motorSpeed);
  if(ultraSensor.distanceCm() < 10) {
    motor1.run(motorSpeed);
    motor2.run(motorSpeed * -1);
    delay(backDelay);
    motor1.run(turnSpeed);
    motor2.run(turnSpeed);
    delay(turnDelay);
    double dist = ultraSensor.distanceCm();
    motor1.run(turnSpeed * -1);
    motor2.run(turnSpeed * -1);
    delay(turnDelay * 2);
    if(ultraSensor.distanceCm() < dist) {
      motor1.run(turnSpeed);
      motor2.run(turnSpeed);
      delay(turnDelay * 2);
    }
  }
  //Serial.print(ultraSensor.distanceCm() );
}
