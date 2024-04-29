
#include <NewPing.h>
#include <Servo.h>
#define TRIG_PIN A0
#define ECHO_PIN A1 
#define MAX_DISTANCE 200
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);
Servo myservo;
boolean goesForward=false;
int distance = 100;
int speedSet = 0;
//Motor A
const int motorPin1 = 2;//IN4 MOTOR DRIVER
const int motorPin2 = 3;//IN3   "     "
//Motor B
const int motorPin3 = 4;//IN2 MOTOR DRIVER
const int motorPin4 = 5;//IN2    "     "
void setup() { 
 myservo.attach(9); //SERVO MOTOR IS ATTACHED TO PIN NO 9 OF ARDUINO
 myservo.write(90);
 delay(2000);
 distance = readPing();
 delay(100);
 distance = readPing();
 delay(100);
 distance = readPing();
 delay(100);
 distance = readPing();
 delay(100);
}
void loop() {
int distanceR = 0;
int distanceL = 0;
delay(40);
if(distance<=10)//For sensing distance edit here*****
{
 moveStop();
 delay(100);
 moveBackward();
 delay(300);
 moveStop();
 delay(200);
 distanceR = lookRight();
 delay(200);
 distanceL = lookLeft();
 delay(200);
 if(distanceR>=distanceL)
 {
 turnRight();
 moveStop();
 }else
 {
 turnLeft();
 moveStop();
 }
}else
{
 moveForward();
}
distance = readPing();
}
int lookRight()
{
 myservo.write(10);
 delay(200);
 int distance = readPing();
 delay(100);
 myservo.write(90);
 return distance;
}
int lookLeft()
{
 myservo.write(170);
 delay(200);
 int distance = readPing();
 delay(100);
 myservo.write(90);
 return distance;
 delay(100);
}
int readPing() {
 delay(70);
 int cm = sonar.ping_cm();
 if(cm==0)
 {
 cm = 250;
 }
 return cm;
}
void moveStop() {
 analogWrite(motorPin1, 0);
 analogWrite(motorPin2, 0);
 analogWrite(motorPin3, 0);
 analogWrite(motorPin4, 0);  
 }

void moveForward() {
 analogWrite(motorPin1, 180);
 analogWrite(motorPin2, 0);
 analogWrite(motorPin3, 180);
 analogWrite(motorPin4, 0);

}
void moveBackward() {
 
 analogWrite(motorPin1, 0);
 analogWrite(motorPin2, 180);
 analogWrite(motorPin3, 0);
 analogWrite(motorPin4, 180);
 delay(100);//edit here for back movement*****
}
void turnRight() {
analogWrite(motorPin1, 180);
 analogWrite(motorPin2, 0);
 analogWrite(motorPin3, 0);
 analogWrite(motorPin4, 180);
 delay(800);//edit here for right turn movement*********
moveForward();

}
void turnLeft() {
 analogWrite(motorPin1, 0);
 analogWrite(motorPin2, 180);
analogWrite(motorPin3, 180);
 analogWrite(motorPin4, 0);
 delay(800);//edit here for left  turn movement*********
 moveForward();
} 
