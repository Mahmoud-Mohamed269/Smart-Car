#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(48, 49);
const byte address[6] = "00001";
char  y[32] = "";
char x , z;

#define in1 42
#define in2 43
#define in3 47
#define in4 41
#define ena 44
#define enb 45

void setup() {
Serial.begin(9600);
radio.begin();
radio.openReadingPipe(0,address); //00001
radio.setPALevel(RF24_PA_MIN);
radio.startListening();

pinMode(in1,OUTPUT);
pinMode(in2,OUTPUT);
pinMode(in3,OUTPUT);
pinMode(in4,OUTPUT);
pinMode(ena,OUTPUT);
pinMode(enb,OUTPUT);


}

void loop() {

if (radio.available()){
radio.read(&y, sizeof(y));
x = y[0];
if (x == 'A')
  {z = x; forward(); delay(800); off(); delay(100); right(); delay(580); forward(); delay(430); off();}

else if (x == 'B')
  {z = x; forward(); delay(800); off(); delay(100); right(); delay(500); forward(); delay(900); off();}

else if (x == 'C')
  {z = x; forward(); delay(1570); off(); delay(100); right(); delay(500); forward(); delay(370); off();}

else if (x == 'D')
  {z = x; forward(); delay(1500); off(); delay(100); right(); delay(500); forward(); delay(680); off();}

else if (x == 'E')
  {z = x; forward(); delay(1500); off(); delay(100); right(); delay(500); forward(); delay(1100); off();}

else if (x == 'O'){
switch(z){
  case 'A': z = x; forward(); delay(850); off(); delay(100); left(); delay(900); off(); //delay(100); forward(); delay(); off(); delay(100); right(); delay(); off(); delay(100);
                   //forward(); delay(); off(); delay(100); right(); delay(); off(); delay(100); forward(); delay(); off(); 
                   break;

   case 'B': z = x; backward(); delay(900); off(); delay(100); left(); delay(530); off(); delay(100); backward(); delay(800); off(); break;

  case 'C': z = x; forward(); delay(850); off(); delay(100); right(); delay(530); off(); //delay(100); forward(); delay(450); off(); delay(100); right(); delay(460); off(); delay(100);
                   //forward(); delay(970); off(); delay(200); right(); delay(480); off(); delay(100);// backward(); delay(770); off(); 
                   break;

  case 'D': z = x; forward(); delay(500); off(); delay(100); right(); delay(490); off(); delay(100); forward(); delay(450); off(); delay(100); right(); delay(460); off(); delay(100);
                   forward(); delay(970); off(); delay(200); right(); delay(480); off(); delay(100); backward(); delay(770); off(); break;

  case 'E': z = x; right(); delay(490); off(); delay(100); forward(); delay(450); off(); delay(100); right(); delay(460); off(); delay(100); forward(); delay(970); off(); delay(200);
                   right(); delay(490); off(); delay(200); backward(); delay(770); off(); break;

  default: off();
}}

Serial.println(z);
/*if (x == 'O'){
  if(z == 'H'){
    //Serial.print("z =");
    //Serial.println(z);
    backward();
    delay(2000);
    off();
    delay(100);
    left();
    delay(650);
    backward();
    delay(2000);
    off();}
    
    else if(z == 'S'){
    backward();
    delay(2000);
    off();
    delay(100);
    right();
    delay(650);
    backward();
    delay(2000);
    off();}
    
    else if (z == 'P'){
    backward();
    delay(2000);
    off();
    delay(100);
    left();
    delay(650);
    backward();
    delay(1000);
    off();
    delay(100);
    right();
    delay(650);
    backward();
    delay(2000);
    off();}
    
    else if (z == 'p'){
    forward();
    delay(2000);
    off();}}*/
  }
  } 

void forward(){
digitalWrite(in1,LOW);
digitalWrite(in2,HIGH);
digitalWrite(in3,HIGH);
digitalWrite(in4,LOW);
analogWrite(ena , 200);
analogWrite(enb , 200);
}

void backward(){
digitalWrite(in1,HIGH);
digitalWrite(in2,LOW);
digitalWrite(in3,LOW);
digitalWrite(in4,HIGH);
analogWrite(ena , 200);
analogWrite(enb , 200);}

void right(){
digitalWrite(in1,HIGH);
digitalWrite(in2,LOW);
digitalWrite(in3,HIGH);
digitalWrite(in4,LOW);
analogWrite(ena , 150);
analogWrite(enb , 150);}

void left(){
digitalWrite(in1,LOW);
digitalWrite(in2,HIGH);
digitalWrite(in3,LOW);
digitalWrite(in4,HIGH);
analogWrite(ena , 120);
analogWrite(enb , 120);}

void off(){
digitalWrite(in1,LOW);
digitalWrite(in2,LOW);
digitalWrite(in3,LOW);
digitalWrite(in4,LOW);}
