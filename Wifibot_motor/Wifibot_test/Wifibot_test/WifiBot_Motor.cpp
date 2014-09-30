#include "WifiBot_Motor.h"


WifiBot_Motor::WifiBot_Motor(void)
{
	
}

WifiBot_Motor::WifiBot_Motor(char port[6],unsigned char speed1,unsigned char speed2,unsigned char SpeedFlag)
{
	//creation de la trame
	trame[0] = 255;
	trame[1] = 0x07; 
	trame[2] = speed1; 
	trame[3] = (speed1 >> 8) ;
	trame[4] = speed2 ; 
	trame[5] = (speed2 >> 8);
	trame[6] = SpeedFlag+1; 
	short mycrc = Crc16(trame+1,6); 
	trame[7] = mycrc; 
	trame[8] = (mycrc >> 8 ); 

	//ouverture port
	fd = open(port,O_RDWR); 
	write(fd,trame,10); 
	Sleep(250); 
	close(fd); 
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