///////////////////////////////////////////////////////////
//  Control.h
//  Implementation of the Class Control
//  Created on:      12-oct.-2014 14:49:39
//  Original author: t.Rizzo / A.Callot / J.Sereau / C.Esteves  
///////////////////////////////////////////////////////////

#if !defined(EA_F8D720E7_3299_45ef_A5BA_DC17616A4D5F__INCLUDED_)
#define EA_F8D720E7_3299_45ef_A5BA_DC17616A4D5F__INCLUDED_

#include "GPS.h"
#include "EnergySensor.h"
#include "IRSensor.h"
#include "Joystick.h"
#include <io.h>
#include <fcntl.h>
#include <Windows.h>

class Control
{

public:
	Control();
	virtual ~Control();
	GPS *m_GPS;
	EnergySensor *m_EnergySensor;
	IRSensor *m_IRSensor;
	Joystick *m_Joystick;
	unsigned char trame[8];
	int fd;

	void RecevoirInstructions(unsigned char,unsigned char,unsigned char);
	void RetourPositionInitiale();
	void Sequenceur();
	void ServeurSocket();
	short Crc16(unsigned char*, unsigned char); 

private:
	/**
	 * Il s'agit du pourcentage actuel de la charge de la Batterie du Wifibot.
	 */
	int energieActuelle;
	/**
	 * Il s'agit du pourcentage initial de la charge de la Batterie du Wifibot au
	 * démarrage du programme.
	 */
	int energieInitiale;
	/**
	 * Il s'agit de la position actuelle du Wifibot.
	 */
	char positionActuelle;
	/**
	 * Il s'agit de la position initiale du Wifibot au démarrage du programme.
	 */
	char positionInitiale;


};
#endif // !defined(EA_F8D720E7_3299_45ef_A5BA_DC17616A4D5F__INCLUDED_)
