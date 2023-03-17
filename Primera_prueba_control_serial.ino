#include <AFMotor.h>
#include <Servo.h>

  AF_DCMotor motor1(1);
  AF_DCMotor motor2(2);
  Servo servo1;
  Servo servo2;
  int val;
  int i;
  int angulo1 = 0;
  int angulo2 = 0;

  
void setup() {
  Serial.begin(115200);
  motor1.setSpeed(250);
  motor2.setSpeed(250);
  servo1.attach(9);
  servo2.attach(10);
}

void MotoresDC()
{
  if (val == 'M')
    {
      motor2.run(FORWARD);
      motor1.run(FORWARD);
    }
    if (val == 'N')
    {
      motor2.run(BACKWARD);
      motor1.run(BACKWARD);
    }
    if (val == 'X')
    {
      motor2.run(RELEASE);
      motor1.run(RELEASE);
    }
    if (val == 'V')
    {
      motor2.run(FORWARD);
      motor1.run(RELEASE);
    }
    if (val == 'Z')
    {
      motor2.run(RELEASE);
      motor1.run(FORWARD);
    }
}

void Servomotores()
{
  if (val == 'D')
  {
    for (i=angulo1; i<=angulo1 + 10; i++)
    {
      servo1.write(i);
    }
    angulo1 = i;
    val = Serial.read();
    Serial.print("Angulo 1: ");
    Serial.print(angulo1);
    Serial.println();
  }
  if (val == 'A')
  {
    for (i = angulo2; i <= angulo2 + 10; i++)
    {
      servo2.write(i);
    }
    angulo2 = i;
    val = Serial.read();
    Serial.print("Angulo 2: ");
    Serial.print(angulo2);
    Serial.println();
  }
  if(val == 'C')
  {
    angulo1 = 0;
    servo1.write(angulo1);
  }
  if (val == 'B')
  {
    angulo2 = 0;
    servo2.write(angulo2);
  }
}


void loop() 
{
  if (Serial.available()) 
  {
    val = Serial.read();
    MotoresDC();
  }
}
