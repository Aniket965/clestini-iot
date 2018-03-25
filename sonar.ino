#include <Servo.h>

#define MAX_DISTANCE_RANGE 50

int triger_pin = 2;
int echo_pin = 4;
long prev_duration = 0;
long current_duration = 0;
float distance_cm = 0; 
int angle = 0;

Servo servo;

void setup() {
  Serial.begin(9600);
  servo.attach(9);
}

void loop() {

   for(angle= 90; angle >= 1; angle -= 1)     
  {                                  
    servo.write(angle);
    current_duration = get_duration();
    distance_cm = current_duration/29/2;
//    Serial.print(distance_cm);
    if(prev_duration < current_duration && distance_cm < MAX_DISTANCE_RANGE) {
       Serial.print(angle);
       Serial.print(" ,");
       Serial.print(distance_cm);
       Serial.println();
      }
      prev_duration = current_duration;                       
  } 
  
   for(angle=0; angle <= 90; angle += 1)     
  {                                  
    servo.write(angle);
    current_duration = get_duration();
    distance_cm = current_duration/29/2;
//    Serial.print(distance_cm);
    if(prev_duration > current_duration && distance_cm < MAX_DISTANCE_RANGE ) {
       Serial.print(angle);
       Serial.print(" ,");
       distance_cm = current_duration/29/2;
       Serial.print(distance_cm);
       Serial.println();
      
      }
       prev_duration = current_duration;                       
  } 
  delay(1000);
}

long get_duration() {
  long duration;
  pinMode(triger_pin,OUTPUT);  
  digitalWrite(triger_pin,LOW);
  delayMicroseconds(2);
  digitalWrite(triger_pin,HIGH);
  delayMicroseconds(10);
  digitalWrite(triger_pin,LOW);
  pinMode(echo_pin,INPUT);
  duration = pulseIn(echo_pin,HIGH);
//  Serial.print(duration);
//  Serial.println();
  delay(15);
  return duration;
}
