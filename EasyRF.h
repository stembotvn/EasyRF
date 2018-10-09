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
#ifndef DEBUG
//#define DEBUG
#endif
#define RFCHANNEL 108

#define TEMPLATE_ADDR 0xF0F0F00000LL 
#define DEFAULT_ADDR 0xF1F2F3AADDLL
///
class RF24;
class EasyRF  {
public:
//EasyRF (int CE_PIN,int CSN_PIN): _CE(CE_PIN),_CSN(CSN_PIN) {}
//RF24 radio = RF24((uint16_t)_CE,(uint16_t)_CSN);
EasyRF(RF24& _radio);
RF24& radio; 
void init(uint16_t myaddress);
void SetAddress(uint16_t myaddress);
bool RFSend(uint16_t to,const void* buf, uint8_t len);  //send a point to point Message
bool RFMulticast(uint16_t to,const void* buf, uint8_t len);  //Send a multicast Message
uint8_t RFRead(void* buf);
void RFRead_Multicast(void* buf);
bool RFDataCome();       //check if RF data comming and ready for receive, get the comming data len
bool MulticastDataCome();  // check if RF Multicast Data comming and ready for receive, get the comming data len
//uint8_t getPayload_len();
private:
int _CE;
int _CSN; 
uint64_t convert_address(uint16_t addr); 
uint64_t address; 
uint16_t my_node;
uint16_t to_node; 
uint16_t multi_node; 
uint8_t myChannel = RFCHANNEL; 
uint8_t payload_len; 
uint8_t Mpayload_len;
uint64_t base_address = TEMPLATE_ADDR;
const uint64_t default_address = DEFAULT_ADDR; 
};
#endif