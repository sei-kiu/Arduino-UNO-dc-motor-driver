#include <Arduino.h>

#define ENA 5
#define IN1 6
#define IN2 7
#define IN3 8
#define IN4 9
#define ENB 10

#define FORWARD 1
#define REVERSE 2
#define LEFT 3
#define RIGHT 4
#define STOP 5

void moveDuration(float seconds);
void move(int direction, int speed);

void setup()
{
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
}

void loop()
{
  // FORWARD at 40% for 2 second
  move(FORWARD, 40 / 100.0 * 255);
  moveDuration(1);

  // Stop moving
  move(STOP, 0);
  moveDuration(1);

  // REVERSE at 40% for 2 second
  move(REVERSE, 40 / 100.0 * 255);
  moveDuration(1);

  // Stop moving
  move(STOP, 0);
  moveDuration(1);

  // LEFT at 40% for 2 second
  move(LEFT, 40 / 100.0 * 255);
  moveDuration(1);

  // Stop moving
  move(STOP, 0);
  moveDuration(1);

  // RIGHT at 40% for 2 second
  move(RIGHT, 40 / 100.0 * 255);
  moveDuration(1);

  // Stop moving
  move(STOP, 0);
  moveDuration(2);

  // FORWARD at 40% for 2 second
  move(FORWARD, 40 / 100.0 * 255);
  moveDuration(1);

  // FORWARD at 100% for 2 second
  move(FORWARD, 100 / 100.0 * 255);
  moveDuration(1);

  // Stop moving
  move(STOP, 0);
  moveDuration(2);
}

void move(int direction, int speed)
{
  if (direction == FORWARD)
  {
    digitalWrite(IN1, 1);
    digitalWrite(IN2, 0);
    digitalWrite(IN3, 0);
    digitalWrite(IN4, 1);

    analogWrite(ENA, speed);
    analogWrite(ENB, speed);
  }
  else if (direction == REVERSE)
  {
    digitalWrite(IN1, 0);
    digitalWrite(IN2, 1);
    digitalWrite(IN3, 1);
    digitalWrite(IN4, 0);

    analogWrite(ENA, speed);
    analogWrite(ENB, speed);
  }
  else if (direction == LEFT)
  {
    digitalWrite(IN1, 1);
    digitalWrite(IN2, 0);
    digitalWrite(IN3, 1);
    digitalWrite(IN4, 0);

    analogWrite(ENA, speed);
    analogWrite(ENB, 0);
  }
  else if (direction == RIGHT)
  {
    digitalWrite(IN1, 0);
    digitalWrite(IN2, 1);
    digitalWrite(IN3, 0);
    digitalWrite(IN4, 1);

    analogWrite(ENA, 0);
    analogWrite(ENB, speed);
  }
  else if (direction == STOP)
  {
    digitalWrite(IN1, 0);
    digitalWrite(IN2, 0);
    digitalWrite(IN3, 0);
    digitalWrite(IN4, 0);

    analogWrite(ENA, speed);
    analogWrite(ENB, speed);
  }
}

void moveDuration(float seconds)
{
  if (seconds < 0.0)
  {
    seconds = 0.0;
  }
  unsigned long endTime = millis() + seconds * 1000;
  while (millis() < endTime)
  {
  }
}