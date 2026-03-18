#ifndef NODE_H
#define NODE_H

class Node
{
	public:
	double val;
	Node* next;
	
	Node(double val){
		this->val=val;
		this->next=0;
	}
};

#endif
