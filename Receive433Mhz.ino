/*
   Simple program to test 433Mhz Reception
  
  http://code.google.com/p/rc-switch/
  https://www.evernote.com/shard/s15/nl/1608382/8ca21b41-15f3-452e-8c71-0b5cb1dda1fd
  
*/

#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();
int compteur = 0;

void setup() {
  Serial.begin(9600);
  mySwitch.enableReceive(0);  // Receiver on inerrupt 0 => that is pin #2
}

void loop() {
  if (mySwitch.available()) {
    
    int value = mySwitch.getReceivedValue();
       
    if (value == 0) {
      Serial.print("Unknown encoding");
    } else {
      Serial.print("Counter ");
      Serial.print( compteur );
      compteur = compteur +1;
      Serial.print("Received ");
      Serial.print( mySwitch.getReceivedValue() );
      Serial.print(" / ");
      Serial.print( mySwitch.getReceivedBitlength() );
      Serial.print("bit ");
      Serial.print("Protocol: ");
      Serial.println( mySwitch.getReceivedProtocol() );
    }

    mySwitch.resetAvailable();
  }
}
