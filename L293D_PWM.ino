/**
   09/2017
   Test DC-Motor Speed Control with L293D
*/

int enablePin = 5;
int in1Pin = 6;
int in2Pin = 7;


int speed = 0;
int inc = 8;
boolean reverse = false;

void setup()
{
  pinMode(enablePin, OUTPUT);
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
}

void loop()
{
  setMotor(speed, reverse);
  speed += inc;
  delay(500);
  if (  speed < 0) {
    speed = 0;
    inc = -inc;
    reverse = !reverse;
  }
  if (  speed > 255) {
    speed = 255;
    inc = -inc;
  }
}

void setMotor(int speed, boolean reverse)
{
  analogWrite(enablePin, speed);
  digitalWrite(in1Pin, !reverse);
  digitalWrite(in2Pin, reverse);
}

