///////////////////////////////////////////////////////////
//  Joystick.h
//  Implementation of the Class Joystick
//  Created on:      12-oct.-2014 14:56:12
//  Original author: t.rizzo
///////////////////////////////////////////////////////////

#if !defined(EA_00C3A2F0_2BC4_4fb1_A3D4_FE0002A5D60F__INCLUDED_)
#define EA_00C3A2F0_2BC4_4fb1_A3D4_FE0002A5D60F__INCLUDED_

class Joystick
{

public:
	Joystick();
	virtual ~Joystick();

	void ClientSocket();
	void TransmettreCommandes();

};
#endif // !defined(EA_00C3A2F0_2BC4_4fb1_A3D4_FE0002A5D60F__INCLUDED_)
