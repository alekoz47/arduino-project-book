const int switchPin = 8;
unsigned long previousTime = 0;
int switchState = 0;
int previousSwitchState = 0;
int led = 2;
long interval = 1000;

void setup() {
  
  for (int ii = 2; ii < 8; ii++) {
    pinMode(ii, OUTPUT);
  }
  pinMode(switchPin, INPUT);

}

void loop() {
  
  unsigned long currentTime = millis();
  if (currentTime - previousTime > interval) {
    previousTime = currentTime;

    digitalWrite(led, HIGH);
    led++;
    
    if (led == 7) {
      delay(1000);
      for (int ii = 0; ii < 5; ii++) {
        
        for (int jj = 2; jj < 8; jj++) {
          digitalWrite(jj, HIGH);
        }
        delay(200);
        
        for (int jj = 2; jj < 8; jj++) {
          digitalWrite(jj, LOW);
        }
        delay(200);
      }
      delay(800);
      led = 2;
    }
    
  }

  switchState = digitalRead(switchPin);
  if (switchState != previousSwitchState) {
    
    for (int ii = 2; ii < 8; ii++) {
      digitalWrite(ii, LOW);
    }
    
    led = 2;
    previousTime = currentTime;
    
  }
  
  previousSwitchState = switchState;

}

