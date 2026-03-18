#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;
class Node
{
	public:
		Node* next;
		Node* previous;
		int val;
		
		Node(int num_){
			this->next=0;
			this->previous=0;
			this->val=num_;
		}
		
		void printNode(){
			cout<<previous<<" <- [ "<<val<<" "<<"( "<<this<<" )"<<"] -> "<<next<<" | ";
		}
};     

#endif
