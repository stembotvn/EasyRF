#include <EasyRF.h>
RF24 Radio (9,10);
EasyRF RF = EasyRF(Radio);
int address  = 100;
void setup(){
RF.init(address);
}
///
void loop(){

}