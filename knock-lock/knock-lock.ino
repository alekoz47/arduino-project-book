#include <Servo.h>
Servo myServo;

const int piezoPin = A0;
const int switchPin = 11;
const int yellowPin = 8;
const int greenPin = 9;
const int redPin = 10;

int knockVal;
int switchVal;

int lastKnock;

const int quietKnock = 2;
const int loudKnock = 50;
int knockNumber = 0;

boolean locked = false;

void setup() {
  myServo.attach(3);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(switchPin, OUTPUT);
  Serial.begin(2400);
  digitalWrite(greenPin, HIGH);
  myServo.write(0);
  Serial.print("The box is unlocked!\n");
}

void loop() {
  if (locked == false) {
    switchVal = digitalRead(switchPin);
    if (switchVal == HIGH) {
      locked = true;
      digitalWrite(greenPin, LOW);
      digitalWrite(redPin, HIGH);
      myServo.write(90);
      Serial.print("The box is locked\n");
      delay(1000);
    }
  } else {
    knockVal = analogRead(piezoPin);
    if (knockNumber < 3 && knockVal > 0) {
      if (knockNumber == 0) {
        lastKnock = millis();
      }
      if (checkKnock(knockVal)) {
        knockNumber++;
      }
      Serial.print(3 - knockNumber);
      Serial.print(" more knocks to go!\n");
    }
    if (knockNumber == 3) {
      locked = false;
      myServo.write(0);
      delay(20);
      digitalWrite(greenPin, HIGH);
      digitalWrite(redPin, LOW);
      Serial.print("The box is unlocked!\n");
      knockNumber = 0;
    }
  }
}

boolean checkKnock(int value) {
  int timer = millis() - lastKnock;
  if (value > quietKnock && value < loudKnock && timer <= 1000) {
    digitalWrite(yellowPin, HIGH);
    delay(50);
    digitalWrite(yellowPin, LOW);
    Serial.print("Valid knock of value ");
    Serial.print(value);
    Serial.print("\n");
    lastKnock = millis();
    return true;
  } else {
    if (timer > 1000) {
      knockNumber = 0;
    }
    Serial.print("Bad knock value ");
    Serial.print(value);
    Serial.print("\n");
    Serial.print("Or, bad timing ");
    Serial.print(millis() - lastKnock);
    Serial.print("\n");
    return false;
  }
}

