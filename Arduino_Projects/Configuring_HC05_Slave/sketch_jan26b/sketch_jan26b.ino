#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11); // RX | TX
String command = ""; // Stores response of the HC-05 Bluetooth device

#define HC05_EN_PIN     9
#define BUZZER_OUTPUT   A5
#define HC05_STATE_PIN  12

void setup()
{
  pinMode(HC05_EN_PIN, OUTPUT);  // this pin will pull the HC-05 pin 34 (key pin) HIGH to switch module to AT mode
  pinMode(BUZZER_OUTPUT, OUTPUT);
  pinMode(HC05_STATE_PIN, INPUT);
  
  digitalWrite(HC05_EN_PIN, HIGH);
  
  Serial.begin(38400);
  Serial.println("Enter AT commands:");
  
  BTSerial.begin(38400);  // HC-05 default speed in AT command more

  //Keep buzzing until connection happens
  keepBuzzing();
}

void loop()
{

  // Keep reading from HC-05 and send to Arduino Serial Monitor
  if (BTSerial.available())
    Serial.write(BTSerial.read());

  // Keep reading from Arduino Serial Monitor and send to HC-05
  if (Serial.available())
    BTSerial.write(Serial.read());

  if(digitalRead(HC05_STATE_PIN) == HIGH)
  {
    digitalWrite (BUZZER_OUTPUT, LOW);

    //BTSerial.write('H');
  }
  else
  {
    keepBuzzing();
  }
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

    //Tone 3
    for (int i = 0; i <150; i++) 
    {
      digitalWrite (BUZZER_OUTPUT, HIGH) ;// send voice
      delay (2) ;// delay 2ms
      digitalWrite (BUZZER_OUTPUT, LOW) ;// do not send voice
      delay (2) ;// delay 2ms
    }

    delay(500);
}

