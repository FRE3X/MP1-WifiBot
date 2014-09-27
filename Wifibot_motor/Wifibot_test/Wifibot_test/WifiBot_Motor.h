#pragma once
class WifiBot_Motor
{
	unsigned char trame[8];  
public:
	WifiBot_Motor(void);
	WifiBot_Motor(unsigned char,unsigned char,unsigned char); 
	~WifiBot_Motor(void);

	//méthode pour calculée le CRC
	short Crc16(unsigned char *Adresse_tab , unsigned char Taille_max); 
	
};

