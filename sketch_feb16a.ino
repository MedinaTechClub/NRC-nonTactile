//made by red in 2017
void setup(){
  //start serial
  Serial.begin(9600);
  //print lines for future people using this robot
  Serial.println("Maze bot by Red");
  Serial.println("");
  Serial.println("For the source code and documentation, please visit");
  Serial.println("");
  Serial.println("http://redthedragon.tk/portfolio.html");
  Serial.println("");
  //constants
  int echoPin1 = 9;
  int triggerPin1 = 10;
  int echoPin2 = 11;
  int triggerPin2 = 12;
  int echoPin3 = 13;
  int triggerPin3 = 14;
  int motorLF = 15;
  int motorLB = 16;
  int motorRF = 17;
  int motorRB = 18;
  int ledR = 19;
  int ledG = 20;
  int ledB = 21;
  //pinModes
  pinMode(triggerPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(triggerPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(triggerPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  pinMode(motorLF, OUTPUT);
  pinMode(motorLB, OUTPUT);
  pinMode(motorRF, OUTPUT);
  pinMode(motorRB, OUTPUT);
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
  //power on self test
  Serial.println("POS Test");
  Serial.println("");
  Serial.println("LED Test");
  Serial.println("");
  digitalWrite(ledR, HIGH);
  digitalWrite(ledR, LOW);
  digitalWrite(ledG, HIGH);
  digitalWrite(ledG, LOW);
  digitalWrite(ledB, HIGH);
  digitalWrite(ledB, LOW);
  Serial.println("Ultrasonic test");
  Serial.println("");
  Serial.println("Sensor 1");
  Serial.println(""));
  Serial.println(getDistance(triggerPin1, echoPin1);
  Serial.println("");
  Serial.println("Sensor 2");
  Serial.println("");
  Serial.println(getDistance(triggerPin2, echoPin2);
  Serial.println("");
  Serial.println("Sensor 3");
  Serial.println("");
  Serial.println(getDistance(triggerPin3, echoPin3);
  Serial.println("");
  Serial.println("POS Test Complete");
}
void loop(){
  //do loop stuff
  //while the front sensor doesn't sense anything, keep going forward.
  while(getDistance(triggerPin1, echoPin1) > 10){
    digitalWrite(motorRF, HIGH);
    digitalWrite(motorLF, HIGH);
  }
  //stop moving and check other directions. If there isn't anything left, then go left.
  digitalWrite(motorRF, LOW);
  digitalWrite(motorLF, LOW);
  if(getDistance(triggerPin2, echoPin2) > 10){
    digitalWrite(motorRB, HIGH);
    digitalWrite(motorLF, HIGH);
    delay(500);
    digitalWrite(motorRB, LOW);
    digitalWrite(motorLF, LOW);
  }
    //else if there isnt anything right, then go right.
  else if(getDistance(triggerPin3, echoPin3) > 10){
    digitalWrite(motorRF, HIGH);
    digitalWrite(motorLB, HIGH);
    delay(500);
    digitalWrite(motorRF, HIGH);
    digitalWrite(motorLB, HIGH);
  }
  else{
    digitalWrite(motorRB, HIGH);
    digitalWrite(motorLF, HIGH);
    delay(1000);
    digitalWrite(motorRB, LOW);
    digitalWrite(motorLF, LOW);
  }  
}
int getDistance(int trigPin, int echoPin){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5); //Change to 10 if not working correctly
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH);
  
  return microsecondsToCentimeters(duration);
}

long microsecondsToCentimeters(long microseconds){
  return microseconds / 29 / 2;
}

