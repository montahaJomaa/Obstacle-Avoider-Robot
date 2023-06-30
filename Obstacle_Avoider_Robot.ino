#include <Servo.h>
#include <NewPing.h>

int LeftSideForward = 9;
int LeftSideBackward = 8;
int RightSideForward = 10;
int RightSideBackward = 11;
int SpeedRight = 5;
int SpeedLeft = 6;

int trigPin = A2;
int echoPin = A1;
long duration, cm, inches;
int maximumcm = 250;

NewPing sonar(trigPin, echoPin, maximumcm);
Servo servo_motor;


void setup(){

  pinMode(RightSideForward, OUTPUT);
  pinMode(LeftSideForward, OUTPUT);
  pinMode(LeftSideBackward, OUTPUT);
  pinMode(RightSideBackward, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  servo_motor.attach(7); //our servo pin
  servo_motor.write(115);
  delay(2000);
  cm = readPing();
  delay(100);
  cm = readPing();
  delay(100);
  cm = readPing();
  delay(100);
  cm = readPing();
  delay(100);
  Serial.begin(9600);
}




void loop(){
  
  cm = readPing();
  int cmRight = 0;
  int cmLeft = 0;
  delay(50);

  if (cm < 50){
    Serial.println(cm);
    Stop();
    delay(300);
    Backward();
    delay(550);
    Stop();
    delay(300);
    cmRight = lookRight();
    Serial.println(cmRight);
    delay(300);
    cmLeft = lookLeft();
    Serial.println(cmLeft);
    delay(300);
    Stop();
    delay(300);
 

     if (cmLeft < 20 && cmRight < 20)
     {
      Serial.println(cm);
      Stop();
      delay(300);
      Backward();
      delay(1300);
      Stop();
      delay(300);
      cmRight = lookRight();
      Serial.println(cmRight);
      delay(300);
      cmLeft = lookLeft();
      Serial.println(cmLeft);
      delay(300);
      Stop();
      delay(300);
      
     }
     else if (cmLeft > cmRight){
      Right();
     delay(520);
     Stop();
     }
      else if (cmRight > cmLeft)
   {
     Left();
     delay(510);
     Stop();
   }
  }

    else
    {
     Forward();
    }

cm = readPing;
}

//FUNCTIONS

int lookRight(){  
  servo_motor.write(0);
  delay(500);
  int cm = readPing();
  delay(300);
  servo_motor.write(90);
  return cm;
  delay(150);
}

int lookLeft(){
  servo_motor.write(180);
  delay(500);
  int cm = readPing();
  delay(300);
  servo_motor.write(90);
  return cm;
  delay(150);
}

int readPing(){
  delay(70);
  int cm = sonar.ping_cm();
  if (cm==0){
    cm=250;
  }
  return cm;
  delay(150);
}

void Stop(){
  
  digitalWrite(LeftSideForward, LOW);
  digitalWrite(LeftSideBackward, LOW);
  digitalWrite(RightSideForward, LOW);
  digitalWrite(RightSideBackward, LOW);
}

void Forward()
{
    Serial.println("Backward");
    digitalWrite(LeftSideForward, HIGH);
    digitalWrite(LeftSideBackward, LOW);
    digitalWrite(RightSideForward, HIGH);
    digitalWrite(RightSideBackward, LOW);
    analogWrite(SpeedRight, 100);
    analogWrite(SpeedLeft, 100);
}

void Backward()
{
    Serial.println("Forward");
    digitalWrite(LeftSideForward, LOW);
    digitalWrite(LeftSideBackward, HIGH);
    digitalWrite(RightSideForward, LOW);
    digitalWrite(RightSideBackward, HIGH);
    analogWrite(SpeedRight, 70);
    analogWrite(SpeedLeft, 70);
}

void Left()
{
    Serial.println("Left");
    digitalWrite(LeftSideForward, HIGH);
    digitalWrite(LeftSideBackward, LOW);
    digitalWrite(RightSideForward, LOW);
    digitalWrite(RightSideBackward, HIGH);
    analogWrite(SpeedRight, 100);
    analogWrite(SpeedLeft, 100);
}

void Right()
{
    Serial.println("Right");
    digitalWrite(LeftSideForward, LOW);
    digitalWrite(LeftSideBackward, HIGH);
    digitalWrite(RightSideForward, HIGH);
    digitalWrite(RightSideBackward, LOW);
    analogWrite(SpeedRight, 100);
    analogWrite(SpeedLeft, 100);
}
