#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel tiraLED= Adafruit_NeoPixel(24,A2,NEO_GRB + NEO_KHZ800);
int TRIGGER=2;
int ECHO=1;
int DURACION;
int DISTANCIA;
int cont1;
int cont2;
int cont3;
int posicionado1=0;
int distLED;

void setup() {
 pinMode(TRIGGER, OUTPUT);
 pinMode(ECHO, INPUT);
 tiraLED.begin();
 tiraLED.setBrightness(60);
 for (int i=0;i<24;i++){
   tiraLED.setPixelColor(i,0,0,100); 
   tiraLED.show();
   delay(50);
   tiraLED.setPixelColor(i,0,0,0);
   tiraLED.show();
 }
}
void loop() {
  /*while para que se aleje*/
 
  int pos1=17; //posicion1 de prueba
  /*while para que se coloque en la primera posicion*/
    while(posicionado1==0){
     /*for (int i=0;i<24;i++){
        if(i!=pos1){
          tiraLED.setPixelColor(i,0,0,0); //apaga todos excepto pos1
          tiraLED.show();
        }
      }*/
      /*lectura distancia*/
     digitalWrite(TRIGGER, HIGH);
     delay(1);
     digitalWrite(TRIGGER, LOW);
     DURACION= pulseIn(ECHO, HIGH);
     DISTANCIA=DURACION/58.8;
     distLED=(DISTANCIA/1-10); //division entera, sin decimales distancia real cm/24
     if (distLED>24){distLED=24;}
     if (distLED<1){distLED=0;}
     if (distLED==pos1){cont1++;}else{cont1=0;}
     for (int i=0;i<=23;i++){
       if (i==pos1){
        if (distLED==pos1){
          tiraLED.setPixelColor(i,0,255,0); 
          tiraLED.show();
          }
        else{
         tiraLED.setPixelColor(i,255,0,0); 
         tiraLED.show();
        }
        
       }
       if (i<=distLED && i!=pos1){
         tiraLED.setPixelColor(i,0,0,255); //enciende todos excepto pos1
         tiraLED.show();
       }
       if(i>distLED && i!=pos1){
         tiraLED.setPixelColor(i,0,0,0); //enciende todos excepto pos1
         tiraLED.show();
       }
     
     }
     if (cont1==100){
       cont1=0;
       cont2++;
       pos1=random(4,24);
       if (cont2==3){
         for (int i=0;i<24;i++){
           tiraLED.setPixelColor(i,255,255,255); 
           tiraLED.show();
         }
         delay(3000);
         for (int i=24;i>=0;i--){
           tiraLED.setPixelColor(i,0,0,0); 
           tiraLED.show();
           delay(100);
         }
         //posicionado1=1; con esta linea terminaria el juego
         cont2=0;
       }
      }
     }
}
  
