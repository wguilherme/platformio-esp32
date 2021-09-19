#include <Arduino.h>

#define led25 25
#define led26 26
#define led27 27
int velocity = 150;

void setup()
{
  pinMode(led25, OUTPUT);
  pinMode(led26, OUTPUT);
  pinMode(led27, OUTPUT);
  delay(250);

  Serial.begin(115200);
}

void loop()
{
  // put your setup code here, to run once:
  Serial.println("log response");
  delay(1 * velocity);
  digitalWrite(led25, LOW);
  delay(2 * velocity);
  digitalWrite(led26, LOW);
  delay(3 * velocity);
  digitalWrite(led27, LOW);

  delay(1 * velocity);

  digitalWrite(led25, HIGH);
  delay(2 * velocity);
  digitalWrite(led26, HIGH);
  delay(3 * velocity);
  digitalWrite(led27, HIGH);

  velocity -= 20;
  if (velocity < 20)
    velocity = 19;
}