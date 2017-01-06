const int sensorPin = A0;
const float baselineTemp = 21.0;

void setup() {
  
  Serial.begin(2400);

  for (int pinNumber = 2; pinNumber < 5; pinNumber++) {
    pinMode(pinNumber, OUTPUT);
  }
  
}

void loop() {
  
  int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);
  
  float sensorVoltage = (sensorVal / 1024.0) * 5.0;
  Serial.print(", Volts: ");
  Serial.print(sensorVoltage);

  float temperature = (sensorVoltage - 0.5) * 100;
  Serial.print(", Degrees (C): ");
  Serial.print(temperature);

  Serial.print("\n");

  for (int pinNumber = 2; pinNumber < 5; pinNumber++) {
    digitalWrite(pinNumber, LOW);
  }

  if (temperature > baselineTemp + 1) {
    digitalWrite(2, HIGH);
  }
  if (temperature > baselineTemp + 2) {
    digitalWrite(3, HIGH);
  }
  if (temperature > baselineTemp + 4) {
    digitalWrite(4, HIGH);
  }

  delay(1);
  
}

