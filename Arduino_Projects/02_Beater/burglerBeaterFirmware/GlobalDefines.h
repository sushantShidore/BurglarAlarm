SoftwareSerial gBTSerial(5, 4); // RX, TX

String gCommand = ""; // Stores response of the HC-06 Bluetooth device

bool burglarSense;

#define UNIVERSAL_BAUD_RATE   (38400)
