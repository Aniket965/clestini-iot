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

   for(angle= 90; angle >= 1; angle -= 1){                                  
    servo.write(angle);
    current_duration = get_duration();

    distance_cm = current_duration/29/2;

    if(prev_duration < current_duration && distance_cm < MAX_DISTANCE_RANGE) {

       Serial.print(angle_from_vertical(angle));

       Serial.print(" ,");

       Serial.print(distance_cm);

       Serial.print(",");

       Serial.print(get_y_distance(to_radian(angle_from_vertical(angle)),distance_cm));

       Serial.println();

      }

      prev_duration = current_duration;                       

  } 

  delay(1000);

}


/**
 * it returns the duration after hitting the object
 */
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
  delay(15);
  return duration;

}

/**
 * Converts angle into Radian
 */

float to_radian(int angle) {
  return (PI/180) * angle;

}



/*
 * To find  y cordinate we have do x * tan(angle)
 */

float get_y_distance(float radian,float x_distance) {

  return x_distance*tan(radian);  

} 



/*
 * returns the absolute angle from vertical 
 */

long angle_from_vertical(long angle) {
   return abs(angle - 45);
}
