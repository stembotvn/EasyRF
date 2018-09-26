#include "EasyRF.h"
#include "RF24.h"


EasyRF::EasyRF(int CE_PIN,int CSN_PIN) {
_CE = CE_PIN;
_CSN = CSN_PIN; 
}
////
void EasyRF::init(uint16_t myaddress){
my_node = myaddress; 
radio.begin();
radio.setChannel(myChannel); 
radio.enableDynamicPayloads();
radio.openReadingPipe(1,convert_address(my_node));
radio.startListening();
}
////
void EasyRF::SetAddress(uint16_t myaddress){
    my_node = myaddress; 
    radio.openReadingPipe(1,convert_address(my_node));
    radio.startListening();

}
////
uint64_t EasyRF::convert_address(uint16_t addr) {
return ((uint64_t)addr | (base_address & ~0xFFFFLL));
}
/////////////
bool EasyRF::RFSend(uint16_t to,const void* buf, uint8_t len){
    bool OK ;
radio.stopListening(); 
 radio.openWritingPipe(convert_address(to));
 OK = radio.write(buf,len); 
 radio.startListening(); 

 return OK; 
}
/////////////
bool EasyRF::RFMulticast(uint16_t to,const void* buf, uint8_t len){
      bool OK ;
 radio.stopListening(); 
radio.enableDynamicAck();
 radio.openWritingPipe(convert_address(to));
 OK = radio.write(buf,len,1); //write multicast, no ack.
 radio.startListening(); 

 return OK;   
}
/////////////////
uint8_t EasyRF::RFRead(void* buf){
 uint8_t len = radio.getDynamicPayloadSize();
 radio.read(buf,len); 
return len; 
 }
////

