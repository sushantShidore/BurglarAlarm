#define BUZZER_OUTPUT         A5

void setupBuzzerControl() {
  pinMode(BUZZER_OUTPUT, OUTPUT);
}

void keepBuzzing()
{
    //Tone 1
    for (int i = 0; i <80; i++) 
    {
      digitalWrite (BUZZER_OUTPUT, HIGH) ;// send voice
      delay (1) ;// Delay 1ms
      digitalWrite (BUZZER_OUTPUT, LOW) ;// do not send voice
      delay (1) ;// delay ms
    }

    //Tone 2
    for (int i = 0; i <100; i++) 
    {
      digitalWrite (BUZZER_OUTPUT, HIGH) ;// send voice
      delay (3) ;// delay 2ms
      digitalWrite (BUZZER_OUTPUT, LOW) ;// do not send voice
      delay (3) ;// delay 2ms
    }

    /*
     * //Tone 3
    for (int i = 0; i <150; i++) 
    {
      digitalWrite (BUZZER_OUTPUT, HIGH) ;// send voice
      delay (2) ;// delay 2ms
      digitalWrite (BUZZER_OUTPUT, LOW) ;// do not send voice
      delay (2) ;// delay 2ms
    }*/
}

void stopBuzzing()
{
  digitalWrite (BUZZER_OUTPUT, LOW) ;
}

