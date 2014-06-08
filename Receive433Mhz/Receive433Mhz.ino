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


/*
// On limite à un évènement par seconde long
#define debounceDelay 1000

// On a 4 détecteurs, donc on a deux timers. Voir http://planet.madeinfr.org/page/16
last_times[4] = {0,0};

bool debounce(int number) {
    if ((last_times[number] == 0) ||
        ((millis() - last_times[number]) > debounceDelay)) {
        last_times[number] = millis();
        return true;
    }
    return false;
}
*/

void setup() {
  Serial.begin(115200);
  mySwitch.enableReceive(0);  // Receiver on inerrupt 0 => that is pin #2
}

void loop() {
  if (mySwitch.available()) {
    
    int value = mySwitch.getReceivedValue();

/*       
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
*/

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
    
        case XXX:
            Serial.println("Presence XXX.");
            break;
            
/*            
        case ABCDEF:
            Serial.println("Presence YYY.");
            break;            
*/
            
        default:
            Serial.print("Dispositif inconnu: ");
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
            Serial.println(value);
            break;
    }

    mySwitch.resetAvailable();
  }
}
