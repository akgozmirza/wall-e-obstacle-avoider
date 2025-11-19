#include "Servo.h"

Servo myServo;
const int echo = 2;
const int trig = 3;
const int redPin = 4;
const int greenPin = 5;
const int servoPin = 6;
const int IN1 = 8;
const int IN2 = 9;
//const int ENA = 10;
//const int ENB = 11;
const int IN3 = 12;
const int IN4 = 13;
//const int speed = 255;
const int servoAngle = 40;
bool obstacle = false;

int duration;
float distance;
float meter;

void turnRight(){
  /*
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
  */
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);
  digitalWrite(greenPin, LOW);
  digitalWrite(redPin, HIGH);
}

void turnLeft() {
  /*
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
  */
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(redPin, HIGH);
}

void goAhead() {
  /*
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
  */
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  digitalWrite(greenPin, HIGH);
  digitalWrite(redPin, LOW);
}

void back() {
  /*
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
  */
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  digitalWrite(greenPin, HIGH);
  digitalWrite(redPin, LOW);
}

void stop() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(redPin, HIGH);
}

void setup() {
  /*
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  */
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  pinMode(echo, INPUT);
  delay(6000);
  Serial.println("Distance: ");
  myServo.attach(servoPin);
  myServo.write(servoAngle);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void leftUltrasonicSensor() {

  for(int i = 40 ; i <= 120 ; i+=10) {

    myServo.write(i);
    delay(100);
  }
  for(int i = 120 ; i >= 40 ; i-=10){

    myServo.write(i); 
    delay(100); 
  } 
}

void rightUltrasonicSensor() {

  for(int i = 40 ; i >= -40 ; i-=10){

    myServo.write(i);
    delay(100);
  }

  for(int i = -40 ; i <= 40 ; i+= 10) {

    myServo.write(i);
    delay(100);
  }

}

void avoidObstacle() {

  back();
  delay(300);

  //sağa dön ve kontrol et
  turnRight();
  delay(300);
  isObstacle();

  if(obstacle) {

    //hala engel varsa 
    turnLeft();
    delay(600);
    back();
  }

}


void isObstacle() {

    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
    duration = pulseIn(echo, HIGH); 
    distance = duration / 58;
    obstacle = (distance <= 10 ) ? true : false;
}

void loop() {

  
  isObstacle();
  if(!obstacle) {
    //Engel Yok
    goAhead();
  }
  else{
    //Engel Var
    avoidObstacle();
  }
  delay(50);
}
  