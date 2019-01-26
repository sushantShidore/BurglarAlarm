
int buzzer = 7;

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzer, OUTPUT);
}

void loop() {
  
    //Tone 1
    for (int i = 0; i <80; i++) 
    {
      digitalWrite (buzzer, HIGH) ;// send voice
      delay (1) ;// Delay 1ms
      digitalWrite (buzzer, LOW) ;// do not send voice
      delay (1) ;// delay ms
    }

    //Tone 2
    for (int i = 0; i <100; i++) 
    {
      digitalWrite (buzzer, HIGH) ;// send voice
      delay (3) ;// delay 2ms
      digitalWrite (buzzer, LOW) ;// do not send voice
      delay (3) ;// delay 2ms
    }

    //Tone 3
    for (int i = 0; i <150; i++) 
    {
      digitalWrite (buzzer, HIGH) ;// send voice
      delay (2) ;// delay 2ms
      digitalWrite (buzzer, LOW) ;// do not send voice
      delay (2) ;// delay 2ms
    }

    //Delay between irritating sounds
    delay(1000);
}
