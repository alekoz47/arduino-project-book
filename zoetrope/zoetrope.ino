const int controlPin1 = 2;
const int controlPin2 = 3;
const int enablePin = 9;
const int directionSwitchPin = 4;
const int onoffSwitchPin = 5;
const int potPin = A0;

int onoff = 0;
int previousOnOff = 0;
int directionSwitch = 0;
int previousDirectionSwitch = 0;

int motorEnabled = 0;
int motorSpeed = 0;
int motorDirection = 1;

void setup() {
  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);

  digitalWrite(enablePin, LOW);
}

void loop() {
  onoff = digitalRead(onoffSwitchPin);
  delay(1);
  directionSwitch = digitalRead(directionSwitchPin);
  motorSpeed = analogRead(potPin) / 4;

  if (onoff != previousOnOff) {
    if (onoff == HIGH) {
      motorEnabled = !motorEnabled;
    }
  }

  if (directionSwitch == HIGH) {
    motorDirection = !motorDirection;
  }

  if (motorDirection == 1) {
    digitalWrite(controlPin1, HIGH);
    digitalWrite(controlPin2, LOW);
  } else {
    digitalWrite(controlPin1, LOW);
    digitalWrite(controlPin2, HIGH);
  }

  if (motorEnabled == 1) {
    analogWrite(enablePin, motorSpeed);
  } else {
    analogWrite(enablePin, 0);
  }

  previousDirectionSwitch = directionSwitch;
  previousOnOff = onoff;
}

