#include "Control.h"
#include <iostream>
using namespace std; 
void main(){
	Control wifibot; 
	unsigned char sp1; 
	unsigned char sp2; 
	unsigned char spf; 

	while (true)
	{

		cout<<"--gestion du SerialPort---"<< endl;
		
		cout << "entrer speed 1 (valeur 0 a 255)" << endl; 
		scanf("%u",&sp1);  
	
		cout << "entrer speed 2 (valeur 0 a 255)" << endl ;
		scanf("%u",&sp2); 

		cout << "entrer speedflag (valeur 0 a 255)" << endl; 
		scanf("%u",&spf);  	
	
		wifibot.RecevoirInstructions(sp1,sp2,spf); 
		
		Sleep(100); 
	}

}