//CUELLO

#include <Servo.h>
Servo servo1;
int PULSOMAX=2500;
int PULSOMIN=500;
void setup() {
servo1.attach(A5,PULSOMIN,PULSOMAX);
}
void loop() {
  
servo1.write(0);
delay(1000);

for(int i=0;i<=20;i++){
 servo1.write(9*i);
 delay(500);
}
delay(1000);
for(int i=20;i>=0;i--){
 servo1.write(9*i);
 delay(500);
}
servo1.write(90);
delay(1000);
servo1.write(0);
delay(1000);
servo1.write(180);
delay(2000);


}

////Giros bruscos
//
//void loop() {
//servo1.write(0);
//delay(2000);
//servo1.write(90);
//delay(2000);
//servo1.write(180);
//delay(2000);
//}
