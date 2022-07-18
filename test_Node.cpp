#include "node.h"

int main(){
	int* ejemplo = new int[100];
  	Node *node1 = new Node(1,1,69,0,nullptr,ejemplo);
		node1->print();
  	Node *node2 = new Node(1,1,59,4,nullptr,ejemplo);
		node2->print();
  	Node *node3 = new Node(1,1,49,2,nullptr,ejemplo);
		node3->print();
}