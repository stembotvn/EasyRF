#ifndef EasyRF_H
#define EasyRF_H
/*
Library for RF24 application easy deployment for beginners. 
Source: Base on RF24 from Tmrh20 library
Author: Hien Phan
Company: Negendo
Date: Sep26,2018
*/
#include "RF24.h"
#include "RF24_config.h"


class RF24;
///
class EasyRF  {
public:
EasyRF (int CE_PIN,int CSN_PIN);
RF24 radio = RF24(_CE,_CSN);

void EasyRF_init();

private:
int _CE;
int _CSN; 
uint64_t convert_address(uint16_t addr); 

};
#endif