///////////////////////////////////////////////////////////
//  Control.cpp
//  Implementation of the Class Control
//  Created on:      12-oct.-2014 14:49:39
//  Original author: t.rizzo
///////////////////////////////////////////////////////////

#include "Control.h"

Control::Control(){

}

Control::~Control(){

}
/**
 * Il s'agit de la m�thode qui permet de recevoir les instructions que le client
 * joystick envoie via des sockets. Une trame est ensuite constituer pour faire rouler le wifibot  
 */
void Control::RecevoirInstructions(unsigned char speed1,unsigned char speed2,unsigned char SpeedFlag){
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
	fd = open("COM1",O_RDWR); 
	write(fd,trame,10); 
	Sleep(250); 
	close(fd); 
}

/**
 * Il s'agit de la m�thode permet de retourner au � la position initiale du
 * Wifibot au d�marrage du programme.
 */
void Control::RetourPositionInitiale(){

}

/**
 * La m�thode "Sequenceur" permet de d�marrer le S�quenceur du WifiBot
 */
void Control::Sequenceur(){

}

/**
 * Il s'agit de la m�thode permettant d'h�berger la connexion qu'initialisera le
 * client joystick via des sockets.
 */
void Control::ServeurSocket(){

}

/**
 * Il s'agit d'une methode permetant le calcule du CRC16
 */
short Control::Crc16(unsigned char *Adress,unsigned char taille_max){
	unsigned int Crc = 0xFFFF;
	unsigned int Polynome = 0xA001;
	unsigned int CptOctet = 0;
	unsigned int CptBit = 0;
	unsigned int Parity= 0;
	
	Crc = 0xFFFF;
	Polynome = 0xA001;
	
	for ( CptOctet= 0 ; CptOctet < taille_max ; CptOctet++)
	{
		Crc ^= *( Adress + CptOctet);
		for ( CptBit = 0; CptBit <= 7 ; CptBit++)
		{
			Parity= Crc;
			Crc >>= 1;
			if (Parity%2 == true) Crc ^= Polynome;
		}
	}
	return(Crc);


}