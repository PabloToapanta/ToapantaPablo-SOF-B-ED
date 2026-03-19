#include <iostream>
#include "LinkedList.h"
#include "Node.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	LinkedList lista;
    cout<<"Ingrese el numero de elementos en la lista\n";
    int elementos;
    cin >> elementos;
    
    for(int i = 0 ;i<elementos;i++){
    	int valor;
    	cout<<"INGRESE EL VALOR DEL ELEMENTO: "<<(i+1)<<endl;
    	cin>>valor;
    	lista.push_back(valor);
	}
	lista.print();
    return 0;
	
}
