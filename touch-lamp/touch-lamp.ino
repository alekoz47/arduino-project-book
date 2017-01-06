#include <CapacitiveSensor.h>
CapacitiveSensor capSensor = CapacitiveSensor(4, 2);

const int ledPin = 11;
int ledValue;

void setup() {
  Serial.begin(1200);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  long sensorValue = capSensor.capacitiveSensor(30);
  Serial.println(sensorValue);
  Serial.println(" - ");
  ledValue = map(sensorValue, 0, 2300, 0, 255);
  Serial.println(ledValue);
  Serial.println("\n");

  analogWrite(ledPin, ledValue);
  
  delay(10);
}

