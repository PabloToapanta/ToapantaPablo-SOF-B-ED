#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*
---------------------------------------
	EJERCICIO 3..2 TRIANGULO DE PASCAL
---------------------------------------
*/
void ejercicio32(){
	int filas;
	cout<<"Ingresa e, numero de filas: ";
	cin>>filas;
	int arreglo[100]={0};
	arreglo[0]=1;
	for(int i = 0;i<filas;i++){
		
		//Centralizar
		for(int s=0;s<filas-i-1;s++){
			cout<<"  ";
		}
		//Actualizar el arreglo de derecha a isquierda
		
		for(int j=i;j>=1;j--){//Notese que solo se da la condicion hasta 1 dado que en el cuerpo se utiliza
								//n-1, entonces es un pare para que no coja un indice que no exista.
			arreglo[j]=arreglo[j]+arreglo[j-1];
		}
		
		//Imprimir valores actuales
		
		for(int j=0;j<=i;j++){
			cout<<arreglo[j]<<"   ";
		}
		cout<<endl;
		
		
	}
}
int main(int argc, char** argv) {
	ejercicio32();
	
	return 0;
}
