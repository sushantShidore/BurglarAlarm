void setupSerialComm(){
    // Open serial communications:
  Serial.begin(9600);

    // The HC-06 defaults to 9600 according to the datasheet.
  gMySerial.begin(9600);
}


void loopSerialComm() {
  // Read device output if available.
  if (gMySerial.available()) {
    while(gMySerial.available()) { // While there is more to be read, keep reading.
      gCommand += (char)gMySerial.read();
    }
    
    Serial.println(gCommand);
    gCommand = ""; // No repeats
  }
  
  // Read user input if available.
  if (Serial.available()){
    delay(10); // The delay is necessary to get this working!
    gMySerial.write(Serial.read());
  }
}

void sendData(unsigned char data){
  gMySerial.write(data);
}

