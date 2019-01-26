

SoftwareSerial gBTSerial(10, 11); // RX | TX
String command = ""; // Stores response of the HC-05 Bluetooth device

#define UNIVERSAL_BAUD_RATE   (38400)
#define HC05_EN_PIN     9   //Used to enter the HC05 in AT Mode for configuration
#define HC05_STATE_PIN  12   //Used to know whether the HC05 has got connected or not

char rxChar = BURGLAR_SENSED;

void setupSerialComm(){
  
#ifdef AT_MODE_ACTIVE  
  pinMode(HC05_EN_PIN, OUTPUT);   // this pin will pull the HC-05 pin 34 (key pin) HIGH to switch module to AT mode
#endif
  
  pinMode(HC05_STATE_PIN, INPUT);
  // Open serial communications:
  gBTSerial.begin(UNIVERSAL_BAUD_RATE);

  Serial.begin(UNIVERSAL_BAUD_RATE);  

#ifdef AT_MODE_ACTIVE
  Serial.println("Enter AT commands:");
#endif
}

void loopSerialComm() {

  //Check if HC05 slave on the other side has got connected to this
  if(digitalRead(HC05_STATE_PIN) == HIGH) {
    
    // Read device output if available.
    if (gBTSerial.available()) {

#ifdef AT_MODE_ACTIVE 
      while(gBTSerial.available()) { // While there is more to be read, keep reading.
        gCommand += (char)gBTSerial.read();
      }
      
      Serial.println(gCommand);
      gCommand = ""; // No repeats
#else
      if(gBTSerial.available() > 0) {
        rxChar = (char)gBTSerial.read();
      }
#endif
      
    }

#ifdef AT_MODE_ACTIVE    
    //Enable block below to configure the HC05 module in AT mode
    // Read user input if available.
    if (Serial.available()){
      delay(10); // The delay is necessary to get this working!
      gBTSerial.write(Serial.read());
    }
#endif
  }
  else {
    rxChar = COMM_FAIL;
  }

  Serial.println(rxChar);
  
}

char getRxChar()
{
  return rxChar;
}

