#define in1 42
#define in2 43
#define in3 47
#define in4 41
#define ena 44
#define enb 45
#include <NewPing.h>

int trig1 = 12;    
int echo1 = 11; 
int trig2 = 3;    
int echo2 = 4;  
long duration1, cm1 , duration2, cm2;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
pinMode(in1,OUTPUT);
pinMode(in2,OUTPUT);
pinMode(in3,OUTPUT);
pinMode(in4,OUTPUT);
pinMode(ena,OUTPUT);
pinMode(enb,OUTPUT);
pinMode(trig1, OUTPUT);
pinMode(echo1, INPUT);
pinMode(trig2, OUTPUT);
pinMode(echo2, INPUT);
}
void loop() {
  analogWrite(trig1, LOW);
  delayMicroseconds(2);   
  analogWrite(trig1, HIGH);     // send waves for 10 us
  delayMicroseconds(10);
  duration1 = pulseIn(echo1, HIGH); // receive reflected waves
  cm1 = duration1 / 58.2;   // convert to distance
  delay(10);
    // If you dont get proper movements of your robot then alter the pin numbers
  if (cm1 > 19)            
  {Serial.println("yes");
    digitalWrite(in1,LOW);
digitalWrite(in2,HIGH);
digitalWrite(in3,HIGH);
digitalWrite(in4,LOW);
analogWrite(ena , 200);
analogWrite(enb , 200);                                                 
  }

  if (cm1 < 18)
  {Serial.println("No");
    digitalWrite(in1,LOW);
digitalWrite(in2,LOW);
digitalWrite(in3,LOW);
digitalWrite(in4,LOW);
    delay(1500);
    digitalWrite(in1,HIGH);
digitalWrite(in2,HIGH);
digitalWrite(in3,HIGH);
digitalWrite(in4,HIGH);
  }

}
