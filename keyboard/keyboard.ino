int notes[] = {262, 294, 330, 349};

void setup() {
  
  Serial.begin(2400);
  
}

void loop() {
  
  int key = analogRead(A0);
  Serial.println(key);
  Serial.println("\n");
  
  if (key >= 1010) {
    tone(8, notes[0]);
  } else if (key >= 990) {
    tone(8, notes[1]);
  } else if (key >= 505) {
    tone(8, notes[2]);
  } else if (key >= 5) {
    tone(8, notes[3]);
  } else {
    noTone(8);
  }
  
}

