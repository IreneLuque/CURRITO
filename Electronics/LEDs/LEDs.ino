#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel tira= Adafruit_NeoPixel(24,9,NEO_GRB+NEO_KHZ800);

void setup() {
 tira.begin();
 tira.show();
 tira.setBrightness(70);
 for (int i=0;i<24;i++){
  tira.setPixelColor(i,0,0,255);
  tira.show();
  delay(50);
  tira.setPixelColor(i,0,0,0);
  tira.show();
 }
 for (int i=23;i>=0;i--){
  tira.setPixelColor(i,90,30,0);
  tira.show();
 }
 delay(1000);
 } 
 void loop() {
 //apagamos todos los LEDs
 for (int i=0;i<24;i++){
  tira.setPixelColor(i,0,0,0);
  tira.show();
 }
 delay(1000);
 tira.setBrightness(40);
 //encendemos todos los leds de verde
 for (int i=23;i>=0;i--){
  tira.setPixelColor(i,0,255,0);
  tira.show();
 }
 delay(1000);
 //encendemos todos los leds de rojo
 for (int i=23;i>=0;i--){
  tira.setPixelColor(i,255,0,0);
  tira.show();
 }
 delay(1000);
 //apagamos todos los leds
 for (int i=0;i<24;i++){
  tira.setPixelColor(i,0,0,0);
  tira.show();
 }
 delay(1000);
 //encendemos los leds de la mitad derecha
 for (int i=16;i<24;i++){
  tira.setPixelColor(i,0,0,255);
  tira.show();
 }
 for (int i=0;i<4;i++){
  tira.setPixelColor(i,0,0,255);
  tira.show();
 }
 delay(1000);
 //apagamos todos los leds
 for (int i=0;i<24;i++){
  tira.setPixelColor(i,0,0,0);
  tira.show();
 }
 delay(1000);
 //encendemos los leds de la mitad izquierda
 for (int i=4;i<16;i++){
  tira.setPixelColor(i,0,0,255);
  tira.show();
 }
 delay(1000);
}
