#include <Windows.h>
#include <iostream>
using namespace std; 

char port[10];
void main()
{

	cout<<"--gestion du SerialPort---"<< endl;
	cout<<"entrer le port: " ; 
	cin >> port;
	cout <<endl ; 

	HANDLE hSerial; 
	hSerial = CreateFile(port,GENERIC_WRITE,0,0,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,0);

	if(hSerial==INVALID_HANDLE_VALUE){
		if(GetLastError()==ERROR_FILE_NOT_FOUND){
			cout<<"Le port spécifier n'éxiste pas" << endl ; 
		}
	}


}