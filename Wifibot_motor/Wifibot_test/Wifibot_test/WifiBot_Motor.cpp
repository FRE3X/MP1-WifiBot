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
