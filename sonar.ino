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
    Serial.println("STARTING 90 degreee =============");
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
       Serial.print(",");
       Serial.print(get_y_distance(to_radian(angle),distance_cm));
       Serial.println();
      }
      prev_duration = current_duration;                       
  } 
    Serial.println("STARTING 00 degreee =============");  
   for(angle=0; angle <= 90; angle += 1)     
  {                                  
    servo.write(angle);
    current_duration = get_duration();
    distance_cm = current_duration/29/2;

    if(prev_duration > current_duration && distance_cm < MAX_DISTANCE_RANGE ) {
       Serial.print(angle);
       Serial.print(" ,");
       distance_cm = current_duration/29/2;
       Serial.print(distance_cm);
       Serial.print(",");
       Serial.print(get_y_distance(to_radian(90 - angle),distance_cm));
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
  delay(15);
  return duration;
}

float to_radian(int angle) {
  return (PI/180) * angle;
}

/*
 * To find  y cordinate we have do x * tan(angle)
 */
float get_y_distance(float radian,float x_distance) {
  return x_distance*tan(radian);  
} 

/* Sample output angle,x_distance(cm),y_distance (cm)
 *  angle 
 *  where x is vertical distance from the sensor
 *  and y is horizontal distance from the sensor 

STARTING 90 degreee =============
62 ,12.00,22.57
60 ,11.00,19.05
59 ,12.00,19.97
57 ,11.00,16.94
54 ,10.00,13.76
53 ,11.00,14.60
51 ,10.00,12.35
49 ,11.00,12.65
47 ,11.00,11.80
45 ,11.00,11.00
42 ,10.00,9.00
41 ,10.00,8.69
STARTING 00 degreee =============
2 ,31.00,887.72
3 ,30.00,572.43
4 ,30.00,429.02
7 ,30.00,244.33
53 ,10.00,7.54
56 ,10.00,6.75
57 ,9.00,5.84
58 ,9.00,5.62
62 ,8.00,4.25
65 ,9.00,4.20
68 ,9.00,3.64
71 ,10.00,3.44
72 ,10.00,3.25
73 ,10.00,3.06
74 ,9.00,2.58
76 ,10.00,2.49
77 ,9.00,2.08
80 ,10.00,1.76



*/
  
