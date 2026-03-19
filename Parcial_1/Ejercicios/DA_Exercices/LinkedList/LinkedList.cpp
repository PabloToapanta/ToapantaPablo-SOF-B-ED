#include "LinkedList.h"
#include <iostream>
using namespace std;
void LinkedList::print(){
	Node* curr = head; // Empezamos en el primer nodo
    
    if (curr == 0) {
        cout << "La lista esta vacia." << endl;
        return;
    }

    cout << "Lista: ";
    while (curr != 0) {
        cout << curr->val << " -> ";
        curr = curr->next; // Saltamos al siguiente nodo
    }
    cout << "NULL" << endl;
	
}
void LinkedList::search(double target){
	Node* curr = head;
	bool encontrado=false;
	int count =0;
	while(curr !=0 && !encontrado){
		if((curr->val)==target){
			cout<<"Valor " <<target <<" econtrado en indice "<< count << endl;
			encontrado=true;
		}
		curr=curr->next;
		count++;
	}
}
