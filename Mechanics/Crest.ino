#include <Servo.h>
Servo servo1;
int PULSOMAX=2500;
int PULSOMIN=500;
void setup() {
servo1.attach(6,PULSOMIN,PULSOMAX);
}
void loop() {
servo1.write(0);
delay(2000);
servo1.write(90);
delay(2000);
servo1.write(180);
delay(2000);
}
