#include <Ultrasonic.h>


void Turn_Right()
{
  ForwardA();
  BackwardB();

}


void Turn_Left()
{
  BackwardA();
  ForwardB();

}


void TotalForward()
{
  ForwardA();
  ForwardB();

}


void ForwardA()
{
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
  analogWrite(10, 200);

}

void ForwardB()
{
  digitalWrite(12, HIGH);
  digitalWrite(13, LOW);
  analogWrite(11, 200);

}


void TotalBackward()
{
  BackwardA();
  BackwardB();

}


void BackwardA()
{
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  analogWrite(10, 200);

}


void BackwardB()
{
  digitalWrite(12, LOW);
  digitalWrite(13, HIGH);
  analogWrite(11, 200);

}

Ultrasonic ultrasonic_10(11, 10);
Ultrasonic ultrasonic_0(0, 0);
void setup()
{
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}


void loop()
{
  TotalForward();
  if (ultrasonic_10.distanceRead() == 30) {
    Turn_Left();
    delay(1000);
    if (ultrasonic_0.distanceRead() >= 30) {
      TotalForward();

    }
    Turn_Right();
    delay(2000);
    if (ultrasonic_0.distanceRead() >= 30) {
      TotalForward();

    }
    Turn_Right();
    delay(2000);

  }
  if (ultrasonic_10.distanceRead() <= 10) {
    Turn_Left();
    delay(500);
    TotalBackward();
    delay(1000);
    TotalForward();

  }

}
