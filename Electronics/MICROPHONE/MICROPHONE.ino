#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel tira= Adafruit_NeoPixel(24,9,NEO_GRB + NEO_KHZ800);
int MICRO=0;
int VALOR;
void setup() {
tira.begin();
tira.show();
pinMode(MICRO, INPUT);
tira.setBrightness(70);
for (int i=0;i<24;i++){
tira.setPixelColor(i,0,0,255);
tira.show();
delay(40);
tira.setPixelColor(i,0,0,0);
tira.show();
}
for (int i=23;i>=0;i--){
tira.setPixelColor(i,0,255,0);
tira.show();
delay(70);
}
}
void loop() {
VALOR=digitalRead(MICRO);
if(VALOR==HIGH){
for (int i=23;i>=0;i--){
 tira.setPixelColor(i,255,0,0);
 tira.show();
 delay(100);
}
}
else{
 for (int i=23;i>=0;i--){
 tira.setPixelColor(i,0,255,0);
 tira.show();
 delay(100);
}
}
}
