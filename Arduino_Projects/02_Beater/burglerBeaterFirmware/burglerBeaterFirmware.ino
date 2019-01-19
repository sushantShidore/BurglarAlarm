#include <SoftwareSerial.h>

#include "GlobalDefines.h"


void setup() {
  setupSerialComm();
  setupBurglarSensing();
}

void loop() {
  loopSerialComm();
  burglarSense = loopBurglarSensing();

  if(burglarSense == true) {
    sendData('A');
  }
  else {
    sendData('Z');
  }

  delay(500);
}
