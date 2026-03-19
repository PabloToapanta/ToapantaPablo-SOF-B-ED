#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
#include "Node.h"
#include <iostream>
using namespace std;

class DoubleLinkedList
{
	public:
	Node* head;
	int size;
	
	DoubleLinkedList(){
		this->head=0;
		size=0;
	}
	void increaseSize(){
		this->size=size+1;
	}
	
	DoubleLinkedList& printList(){
		//Si la lista esta vacia, mandamos una alerta
		if(head != 0){
			Node* curr = head;
			while(curr !=0){
				curr->printNode();
				curr=curr->next;
			}
		}else{
			cout<<"La lista esta vacia\n";
		}
		
		return *this;
	}
	
	DoubleLinkedList& push_front(int val_){
		Node *ptr = new Node(val_);
		//Si la lista esta vacia, solo head apunta a nodo, y el nodo apunta tanto a null en 
		//previuos y next
		if(head==0){
			head=ptr;
		}else{//Si la lista no esta vacia, entonces head apunta al nodo siguiente
		//Por ello simplemente asignamos el next de node a donde apuntaba head
		//Se asigna como next del nodo a lo que apuntaba head
		ptr->next=head;
		//Se accede al puntero previous de lo que apuntaba head y cambiamos hacia nuestro nodo
		head->previous=ptr;
		//Actualizamos el nodo head para que ahora apunte al nodo que queremos aniadir.
		head=ptr;
		}
		increaseSize();
		return *this;
	}
	
	DoubleLinkedList& push_back(int val){
		Node *ptr = new Node(val);
		//Si la lista esta vacia, entonces definimos head a nuestro nodo
		if(head==0){
			head=ptr;
		}else{
			Node *curr = head;
			while (curr->next != 0){
				curr=curr->next;
			}
			curr->next=ptr;
			ptr->previous=curr;
		}
		increaseSize();
		return *this;
	}
	
	DoubleLinkedList& insert(int position,int val_){
		//Si la posicion es igual a 1, es decir que va a la posicion 0, simplemente hacer un
		//push_front
		if(position==1){
			push_front(val_);
		}
		if(position <= 0){
			return *this;
		}
		Node* ptr = new Node(val_);
		Node* curr = head;
		//En otro caso, recorrer hasta position - 1 valores
		for(int i =0;i<position-2 && i>=0;i++){
			curr = curr->next;
		}
		ptr->next=curr->next;
		ptr->previous=curr;
		
		curr->next=ptr;
		
		if(position != size){
			ptr->next->previous=ptr;
		}
		increaseSize();
		return *this;
	}
};

#endif
