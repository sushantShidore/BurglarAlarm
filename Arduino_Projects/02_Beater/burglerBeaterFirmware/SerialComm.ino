
#define HC05_EN_PIN     9   //Used to enter the HC05 in AT Mode for configuration
#define HC05_STATE_PIN 10   //Used to know whether the HC05 has got connected or not

void setupSerialComm(){
  
  pinMode(HC05_STATE_PIN, INPUT);
  
  // Open serial communications:
  Serial.begin(UNIVERSAL_BAUD_RATE);    
  gBTSerial.begin(UNIVERSAL_BAUD_RATE);
}


void loopSerialComm() {

  //Check if HC05 master on the other side has got connected to this
  if(digitalRead(HC05_STATE_PIN) == HIGH) {
    
    // Read device output if available.
    if (gBTSerial.available()) {
      while(gBTSerial.available()) { // While there is more to be read, keep reading.
        gCommand += (char)gBTSerial.read();
      }
      
      Serial.println(gCommand);
      gCommand = ""; // No repeats
    }

    //Enable block below to configure the HC05module in AT mode
    /*
    // Read user input if available.
    if (Serial.available()){
      delay(10); // The delay is necessary to get this working!
      gBTSerial.write(Serial.read());
    }
    */
  }

}

void sendData(unsigned char data){
  if(digitalRead(HC05_STATE_PIN) == HIGH) {
    gBTSerial.write(data);
  }
}

