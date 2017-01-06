const int greenLEDPin = 9;
const int redLEDPin = 11;
const int blueLEDPin = 10;

const int redSensorPin = A0;
const int greenSensorPin = A1;
const int blueSensorPin = A2;

int red = 0;
int green = 0;
int blue = 0;

int redSensor = 0;
int greenSensor = 0;
int blueSensor = 0;

void setup() {
  
  Serial.begin(2400);
  
  pinMode(greenLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
  
}

void loop() {
  
  redSensor = analogRead(redSensorPin);
  delay(5);
  greenSensor = analogRead(greenSensorPin);
  delay(5);
  blueSensor = analogRead(blueSensorPin);
  delay(5);
  
  red = redSensor / 4;
  green = greenSensor / 4;
  blue = blueSensor / 4;
  
  Serial.print("Raw Sensor Values: ");
  Serial.print("\n");
  Serial.print("Red: ");
  Serial.print(red);
  Serial.print(" Green: ");
  Serial.print(green);
  Serial.print(" Blue: ");
  Serial.print(blue);
  Serial.print("\n");
  Serial.print("\n");
  
  analogWrite(redLEDPin, red);
  analogWrite(greenLEDPin, green);
  analogWrite(blueLEDPin, blue);
  
}

