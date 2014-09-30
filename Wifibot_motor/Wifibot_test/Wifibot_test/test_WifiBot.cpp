#include <iostream>
#include "WifiBot_Motor.h"
using namespace std; 

char port[8];
void main()
{
	unsigned char sp1; 
	unsigned char sp2; 
	unsigned char spf; 

	cout<<"--gestion du SerialPort---"<< endl;
	//cout<<"entrer le port: " ; 
	//cin >> port;
	//cout <<endl ;

	cout<<"Allumage" <<endl; 
	sp1 = 60; 
	sp2 = 55; 
	spf = 22; 
	
	

	WifiBot_Motor bot("COM1",sp1,sp2,spf); 
	Sleep(100); 
	
	/*hSerial = CreateFile(port,GENERIC_WRITE,0,0,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,0);

	if(hSerial==INVALID_HANDLE_VALUE){
		if(GetLastError()==ERROR_FILE_NOT_FOUND){
			cout<<"Le port spécifier n'éxiste pas" << endl ; 
		}
	}*/
	
	



}