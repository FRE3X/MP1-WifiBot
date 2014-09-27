#include "WifiBot_Motor.h"


WifiBot_Motor::WifiBot_Motor(void)
{
	
}

WifiBot_Motor::WifiBot_Motor(unsigned char speed1,unsigned char speed2,unsigned char SpeedFlag)
{
	trame[0] = 255;
	trame[1] = 0x07; 
	trame[2] = speed1; 
	trame[3] = (speed1 >> 8) ;
	trame[4] = speed2 ; 
	trame[5] = (speed2 >> 8); 
	trame[6] = SpeedFlag+1; 

}

WifiBot_Motor::~WifiBot_Motor(void)
{
}

short WifiBot_Motor::Crc16(unsigned char *Adresse , unsigned char taille_max){
	unsigned int Crc = 0xFFFF;
	unsigned int Polynome = 0xA001;
	unsigned int CptOctet = 0;
	unsigned int CptBit = 0;
	unsigned int Parity= 0;
	
	Crc = 0xFFFF;
	Polynome = 0xA001;
	
	for ( CptOctet= 0 ; CptOctet < taille_max ; CptOctet++)
	{
		Crc ^= *( Adresse + CptOctet);
		for ( CptBit = 0; CptBit <= 7 ; CptBit++)
		{
			Parity= Crc;
			Crc >>= 1;
			if (Parity%2 == true) Crc ^= Polynome;
		}
	}
	return(Crc);

}