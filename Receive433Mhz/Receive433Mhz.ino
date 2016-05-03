/*
   Simple program to test 433Mhz Reception
  
  http://code.google.com/p/rc-switch/
  https://www.evernote.com/shard/s15/nl/1608382/8ca21b41-15f3-452e-8c71-0b5cb1dda1fd
  
*/

#include <RCSwitch.h>

#define  PRESENCE_ESCALIER_CAVE  851292
#define  PRESENCE_SALON          1310800
#define  PORTE_BUANDERIE         13841744
#define  XXX                     5534032
#define  ABCDEF                  29008

RCSwitch mySwitch = RCSwitch();
int compteur = 0;


void setup() {
  Serial.begin(115200);
  mySwitch.enableReceive(0);  // Receiver on interrupt 0 => that is pin #2 on an Arduino Uno
}

void loop() {
  if (mySwitch.available()) {
    
    int value = mySwitch.getReceivedValue();

    switch (value) {
        case PRESENCE_ESCALIER_CAVE:
            Serial.println("Presence en bas de l'escalier.");
            break;

        case PRESENCE_SALON:
            Serial.println("Presence dans le salon.");
            break;
        
        case PORTE_BUANDERIE:
            Serial.println("Presence porte buanderie.");
            break;
            
        default:
            Serial.print("Dispositif inconnu: ");
            Serial.print("Received ");
            Serial.print( mySwitch.getReceivedValue() );
            Serial.print(" / ");
            Serial.print( mySwitch.getReceivedBitlength() );
            Serial.print("bit ");
            Serial.print("Protocol: ");
            Serial.println( mySwitch.getReceivedProtocol() );
            Serial.println(value);
            break;
    }

    Serial.print("Counter ");
    Serial.print( compteur );
    compteur = compteur +1;
    mySwitch.resetAvailable();
  }
}
