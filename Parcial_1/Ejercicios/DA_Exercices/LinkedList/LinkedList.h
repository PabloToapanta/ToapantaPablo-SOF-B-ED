#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
#include <iostream>
using namespace std;
class LinkedList
{
	public:
		Node* head;

		int size;
		
		LinkedList(){
			size=0;
			head=0;

		}
		void incrementarTamanio(){
			this->size++;
		}
		
		//INSERTION FUNCTIONS
		

		LinkedList& push_Front(double num){
			Node* ptr = new Node(num);
			ptr->next=head;
			head=ptr;
			incrementarTamanio();
			return *this;
		}
		
		LinkedList& push_back(double num){
    		Node* ptr = new Node(num);
    
    				if(head == 0){
        			head = ptr;           // Caso lista vacía
    				} else {
       				 Node* curr = head;
      				 	while(curr->next != 0){
           		 curr = curr->next;
       			 		}
        			curr->next = ptr;     // Caso lista no vacía
   		 			}
    
    				incrementarTamanio();
    					return *this;
					}
		
		void print();
		void search(double target);
		
		Node* findNode(int num){
			
			if(num<0 || num>size){
				return 0;
			}
			Node* curr = head;
			for(int i=0;i<num;i++){
				curr=curr->next;
			}
			cout<<"El nodo con valor "<<curr->val<<" y en indice "<< num<<endl;
			return curr;
			
		}
		
		LinkedList& insert(int position, double value){
			Node* anterior = findNode(position);
			if(position==(size-1)){
				push_back(value);
				return *this;
			}
			//Declaracion de nuevo nodo insertado
			if(anterior != 0){
				Node* insertionNode = new Node(value);
			//Asignacion de next del nodo anterior al nodo insertado
			insertionNode->next=anterior->next;
			anterior->next=insertionNode;
			incrementarTamanio();
			return *this;
			
			}else{
				return *this;
			}
			
		}
		//Destructor
	~LinkedList(){
		if(head!=0){
		Node* actual=head;
		Node*siguiente;
		while(actual !=0 ){
			siguiente=actual->next;
			delete actual;
			actual=siguiente;
		}	
		}
		
	}
	
	void eliminar(double target) {
    // Escenario 1: Lista vacía
    if (head == 0) {
        cout << "La lista esta vacia, no hay nada que eliminar." << endl;
        return;
    }

    // Escenario 2: El nodo a eliminar es el head
    if (head->val == target) {
        Node* nodoAEliminar = head;
        head = head->next;     // El nuevo head es el segundo nodo
        delete nodoAEliminar;  // Liberamos la memoria
        size--;
        cout << "Elemento " << target << " eliminado." << endl;
        return;
    }

    // Escenario 3: El nodo a eliminar está en el medio o al final
    Node* curr = head;
    Node* prev = 0;

    // Buscamos el nodo. curr se detendrá en el nodo a eliminar, prev un paso atrás.
    while (curr != 0 && curr->val != target) {
        prev = curr;
        curr = curr->next;
    }

    // Si llegamos al final y no lo encontramos
    if (curr == 0) {
        cout << "El elemento " << target << " no se encuentra en la lista." << endl;
        return;
    }

    // Reasignación de punteros: el 'next' del anterior ahora apunta al 'next' del actual
    prev->next = curr->next;
    
    delete curr; // Destruimos el nodo en memoria
    size--;
    cout << "Elemento " << target << " eliminado." << endl;
}
};

#endif
