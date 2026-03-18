#include <iostream>
using namespace std;
#include <iomanip>
//-------------------------------
//       EJERCICIO 3.1 
//-------------------------------
void ejercicio31(){
	cout<<"EJERCICIO 3.1 "<<endl;
	//Declaracion de variable x tipo int
	int x;
	//Declaracion de variable y tipo char
	char y;
	
	//CASO A
	cout<<"PRIMER CASO(ENTRADA 5 c)"<<endl;
	cout<<"INGRESE 5 c: ";
	cin >> x >> y;
	cout<<"\nRESULTADO: ";
	cout<<"x: "<<x<<" y: "<<y<<endl;
	cout<<"CODIGO ASCCI DE y : "<<int(y)<<endl;
	cout<<"----------------------\n";
	
	//CASO B
	cout<<"SEGUNDO CASO (ENTRADA 5C)"<<endl;
	cout<<"INGRESE 5C: ";
	cin >> x >> y;
	cout<<"\nRESULTADO: ";
	cout<<"x: "<<x<<" y: "<<y<<endl;
	cout<<"CODIGO ASCCI DE y : "<<int(y)<<endl;
	
}
/*
----------------------------
            EJRCICIO 3.8
---------------------------
*/
void ejercicio38(){
	
	double longitud;
	double anchura;
	cout<<"EJERICICO 3.8 LONGITUD Y ANCHURA \n";
	cout<<"INGRESE LA LONGITUD: ";
	cin>>longitud;
	cout<<"\nINGRESE LA ANCHURA: ";
	cin >> anchura;
	double resultado = longitud*anchura;	
	resultado=int(resultado*10000)/10000.0;
	cout<<fixed<<setprecision(4);
	cout<<"EL AREA (CON 4 DECIMALES) ES: "<<resultado<<endl;
	
	
}
int main(){
	//EJERCICIO 3.1
	//ejercicio31();
	
	//EJERCICIO 3.8
	ejercicio38();
}
