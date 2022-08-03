#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(9, 10);
const byte address[6] = "00001";
char d ;

void setup() {
  Serial.begin(9600);
 radio.begin();
 radio.openWritingPipe(address);  //00001
 radio.setPALevel(RF24_PA_MIN);
 
 radio.stopListening();
 Serial.print("1.A  2.B  3.C  4.D  5.E  6.O");
 Serial.print('\n');
}

void loop() {
  d = Serial.read();
  if (d == '1'){
  const char t[] = "A";
  radio.write(&t, sizeof(t));
  delay(1000);}

  else if (d == '2'){
    const char t1[] = "B";
  radio.write(&t1, sizeof(t1));
  delay(1000);}
  
  else if (d == '3'){
    const char t2[] = "C";
  radio.write(&t2, sizeof(t2));
  delay(1000);}

  else if (d == '4'){
    const char t3[] = "D";
  radio.write(&t3, sizeof(t3));
  delay(1000);}
  
  else if (d == '5'){
    const char t5[] = "E";
  radio.write(&t5, sizeof(t5));
  delay(1000);}
  
  else if (d == '6'){
    const char t4[] = "O";
  radio.write(&t4, sizeof(t4));
  delay(1000);}}
