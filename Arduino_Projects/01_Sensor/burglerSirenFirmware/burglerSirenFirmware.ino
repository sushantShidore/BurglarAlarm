#include <SoftwareSerial.h>
#include "GlobalDefines.h"

char rxData = NO_INIT;

void setup()
{
  setupSerialComm();
  setupBuzzerControl();
}

void loop()
{
  loopSerialComm();

  rxData = getRxChar();
  
  if(rxData == BURGLAR_SENSED)
  {
    keepBuzzing();
  }
  else if(rxData == COMM_FAIL)
  {
    //TODO
  }
  else if(rxData == NO_INIT)
  {
    //TODO
  }
  else
  {
    stopBuzzing();
  }

  delay(500);
}

