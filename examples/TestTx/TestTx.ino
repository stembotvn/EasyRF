#include <EasyRF.h>
#define CE_PIN    9
#define CSN_PIN   10
RF24 myRadio(CE_PIN,CSN_PIN);
EasyRF Radio(myRadio);
uint16_t myAddress  = 100;
uint16_t yourAddress = 50;
char Message[] = "Hello"; 
void setup(){
Radio.init(myAddress);
}
///
void loop(){
    bool OK = false; 
Serial.println("Sending message..");
OK = Radio.RFSend(yourAddress,Message,sizeof(Message));
if (OK) Serial.println("Sent successfully!");
else Serial.println("Sending Fail!"); 
delay(1000);
}