#include <iostream>
using namespace std;
#include "Vector3d.h"
#include "Complejo.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	/*
	cout<<"DECLARACION PRIMER VECTOR (3,6,2)"<<endl;
	Vector3d * ptr = new Vector3d(3,6,2);
	cout<<"DECLARACION SEGUNDO VECTOR (3,6,2)"<<endl;
	Vector3d * ptr2 = new Vector3d(3,6,2);
	
	// OJO: no es necesario *ptr para llamar a metodo, de hecho el operador -> se usa para punteros,
	bool t = ptr->igual(*ptr2);
	cout<<"Los valores son iguales? "<<t<<endl;
	cout<<"La norma del vector 1 es : "<<ptr->normaMax()<<endl;
	
	delete ptr;
	delete ptr2;
	return 0;
	*/
	
	
	//COMPLEJO
	
	Complejo * ptr = new Complejo();
	ptr->imprimir();
	
	Complejo * ptr2 = new Complejo();
	
	ptr->establecer(2,-4);
	
	
	ptr2->establecer(8,2);
	ptr2->imprimir();
	
	
	
	cout<<"\nMULTIPLICACION\n";
	ptr->multiplicacionCompleja(*ptr2)->imprimir();
	
	cout<<"Conjugada de PTR1: \n";
	ptr->conjugada()->imprimir();
	
	
	
	
	
	delete ptr2;  // Primero el último creado
	delete ptr;
	
}
