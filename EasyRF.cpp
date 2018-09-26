#include "EasyRF.h"
#include "RF24.h"


EasyRF::EasyRF(int CE_PIN,int CSN_PIN) {
_CE = CE_PIN;
_CSN = CSN_PIN; 
}
////
void EasyRF::EasyRF_init(){

}
////
uint64_t EasyRF::convert_address(uint16_t addr) {
    
}