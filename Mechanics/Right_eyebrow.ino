#include <Servo.h>
Servo servo1;
int PULSOMAX=1800;
int PULSOMIN=1000;
void setup() {
servo1.attach(A1,PULSOMIN,PULSOMAX);
}
void loop() {
servo1.write(0);
delay(2000);
servo1.write(90);
delay(2000);
servo1.write(180);
delay(2000);
}
