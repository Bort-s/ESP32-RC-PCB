#include <Arduino.h>
#include <ps5Controller.h>

//Replace with your MAC address
const char MAC[] = "XX:XX:XX:XX:XX:XX";

// Pins for TBB6612FNG
const int AIN1 = 33;
const int AIN2 = 25;
const int PWMA = 32;
const int BIN1 = 26;
const int BIN2 = 27;
const int PWMB = 14;

const int max_speed = 255;
int valL2 = 0;
int valR2 = 0;
bool L2 = false;     
bool R2 = false;

int xAxis = 0;

 //Joystick's deadzone
const int deadzone = 20;


void setup() 
{
  Serial.begin(115200);
  ps5.begin(MAC);

  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
}

void forward(int speed) 
{
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  analogWrite(PWMA, speed);

  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  analogWrite(PWMB, speed);
}

void backward(int speed) 
{
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  analogWrite(PWMA, speed);

  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
  analogWrite(PWMB, speed);
}

void right(int speed) 
{
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  analogWrite(PWMA, speed);

  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  analogWrite(PWMB, speed);
}

void left(int speed) 
{
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  analogWrite(PWMA, speed);

  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
  analogWrite(PWMB, speed);
}

void stop() 
{
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  analogWrite(PWMA, 0);

  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);
  analogWrite(PWMB, 0);
}

void loop() 
{
  // Check connection status
  if (!ps5.isConnected())
  {
    stop();
    return;
  }

  valL2 = ps5.L2Value();
  valR2 = ps5.R2Value();
  L2 = ps5.L2();
  R2 = ps5.R2();
  xAxis = ps5.data.analog.stick.lx;

  // Drive control
  if (R2 == true && L2 == false)
  {
    forward(valR2);
  } 
  else if (R2 == false && L2 == true) 
  {
    backward(valL2);
  }
  else if (xAxis < -deadzone)
  {
    left(-xAxis);
  }
  else if (xAxis > deadzone)
  {
    right(xAxis);
  }
  else
  {
    stop();
  }
}
