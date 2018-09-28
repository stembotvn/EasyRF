#include <EasyRF.h>
#define CE_PIN    A2
#define CSN_PIN   A3
RF24 myRadio(CE_PIN,CSN_PIN);
EasyRF Radio(myRadio);
uint16_t myAddress  = 50;
uint16_t yourAddress = 100;
uint8_t buffer[32];
uint8_t len;
bool isReceived = false; 
void setup(){
Radio.init(myAddress);
}
///
void loop(){
while (Radio.RFDataCome())
 {
  isReceived = true;
  len = Radio.RFRead(buffer); 
   }
 if (isReceived) {
     Serial.print("RF data come!"); Serial.println(len);
 for (int i=0;i<len;i++) Serial.print(buffer[i]);
  isReceived = false; 
 }
}