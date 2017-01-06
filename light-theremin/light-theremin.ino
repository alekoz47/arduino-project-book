int sensor;
int sensorLow = 1023;
int sensorHigh = 0;

const int ledPin = 13;

void setup() {
  
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);

  while (millis() < 5000) {

    sensor = analogRead(A0);
    
    if (sensor > sensorHigh) {
      sensorHigh = sensor;
    } else if (sensor < sensorLow) {
      sensorLow = sensor;
    }
    
  }
  
  digitalWrite(ledPin, LOW);
  
}

void loop() {
  
  sensor = analogRead(A0);
  int pitch = map(sensor, sensorLow, sensorHigh, 50, 1000);
  tone(8, pitch, 10000);
  
  delay(10);
  
}

