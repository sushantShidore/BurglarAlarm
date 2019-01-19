int PIR_SENSE_PIN = 8;

void setupBurglarSensing() {
  pinMode(PIR_SENSE_PIN, INPUT);
}

bool loopBurglarSensing() {

  bool result = false;
  
  if(digitalRead(PIR_SENSE_PIN) == HIGH) {
    result = true;
  }

  delay(10);

  return result;
}

