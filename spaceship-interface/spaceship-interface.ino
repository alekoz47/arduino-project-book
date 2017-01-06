int switchState = 0;

void setup() {

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, INPUT);
  
}

void loop() {
  
  switchState = digitalRead(2);
  
  if (switchState == LOW) {

    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    
  } else {

    digitalWrite(LED_BUILTIN, HIGH);
    
    for (int ii = 1; ii < 10; ii++) {
      
      digitalWrite(3, LOW);
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      
      delay(250);

      digitalWrite(4, HIGH);
      digitalWrite(5, LOW);
      
      delay(250);
      
    }
    
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);

    delay(10000);
    
  }
  
}

