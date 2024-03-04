#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel tira= Adafruit_NeoPixel(24,A2,NEO_GRB + NEO_KHZ800);
int TRIGGER=2;
int ECHO=1;
int DURACION;
int DISTANCIA;
void setup() {
pinMode(TRIGGER, OUTPUT);
pinMode(ECHO, INPUT);
tira.begin();
//encendemos leds en verde
tira.setBrightness(60);
for (int i=23;i>=0;i--){
tira.setPixelColor(i,0,255,0);
tira.show();
delay(70);
}
}
void loop() {
//calculo la distancia del objeto
digitalWrite(TRIGGER, HIGH);
delay(1);
digitalWrite(TRIGGER, LOW);
DURACION= pulseIn(ECHO, HIGH);
DISTANCIA=DURACION/58.8;
while(DISTANCIA<=20 && DISTANCIA>=0){
//si el objeto esta a menos de 20cm, enciendo los leds de rojo 
for (int i=23;i>=0;i--){
 tira.setPixelColor(i,255,0,0);
 tira.show();
}
//vuevo a calcular la distancia del objeto pra ver si salgo del bucle
digitalWrite(TRIGGER, HIGH);
delay(1);
digitalWrite(TRIGGER, LOW);
DURACION= pulseIn(ECHO, HIGH);
DISTANCIA=DURACION/58.8;
}
//si salgo del bucle vuelvo a poner los leds en verde
for (int i=23;i>=0;i--){
tira.setPixelColor(i,0,255,0);
tira.show();
}
}
