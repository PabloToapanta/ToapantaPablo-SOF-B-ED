#include <iostream>
#include "Node.h"
using namespace std;
#include <iostream>
#include "DoubleLinkedList.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	//Declarations to show that node is well declared
//	Node *ptr = new Node(45);
	//Second Node
//	Node *ptr2 = new Node(34);
	
	//ptr->printNode();
	//declare ptr head as de pointer of ptr2
	//ptr->next=ptr2;
	//Print that again
//	ptr->printNode();
	
	//DoubleLinkedList objet  creation
	DoubleLinkedList list = DoubleLinkedList();
	list.push_front(4).push_back(5).push_back(6).printList();
	
	cout<<"DESPUES DE HABER MODIFICADO\n";
	
	list.insert(2,1).printList();
	
	

	
	return 0;
}
