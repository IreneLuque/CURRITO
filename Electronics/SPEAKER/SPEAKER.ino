void setup(){
pinMode(8, OUTPUT); // Definimos el pin 8 como salida.
}
void loop(){
tone(8,440,500);
delay(250);
noTone(8);
tone(8,440,500);
delay(250);
noTone(8);
tone(8,440,500);
delay(250);
tone(8,349,175);
delay(175);
tone(8,523,75);
delay(75);
tone(8,440,250);
delay(250);
tone(8,349,175);
delay(175);
tone(8,523,75);
delay(75);
tone(8,440,440);
delay(400);
noTone(8);
delay(2000);
/*melodia star wars 
tone(8,392,500);noTone(8);delay(100);
tone(8,392,500);noTone(8);delay(100);
tone(8,392,500);noTone(8);delay(100);
tone(8,311,500);noTone(8);delay(1);
tone(8,466,125);noTone(8);delay(25);
tone(8,392,500);noTone(8);delay(100);
tone(8,311,500);noTone(8);delay(1);
tone(8,466,125);noTone(8);delay(25);
tone(8,392,500);
noTone(8);delay(2000);
*/

}
