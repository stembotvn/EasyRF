#include <EasyRF.h>
EasyRF RF(9,10);
int address  = 100;
void setup(){
RF.init(address);
}
///
void loop(){

}