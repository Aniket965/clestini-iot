int triger_pin = 2;
int echo_pin = 4;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  long duration;
  pinMode(triger_pin,OUTPUT);
  
  digitalWrite(triger_pin,LOW);
  delayMicroseconds(2);
  digitalWrite(triger_pin,HIGH);
  delayMicroseconds(10);
  digitalWrite(triger_pin,LOW);
  
  pinMode(echo_pin,INPUT);
  duration = pulseIn(echo_pin,HIGH);

  Serial.print(duration/29/2);

  Serial.println();
  delay(100);
}
