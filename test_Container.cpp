#include "container.h"

int main() {
  int* ejemplo = new int[100];
  Node *root = new Node(0,0,-1,-1,nullptr,ejemplo);
  Node *node1 = new Node(1,1,1,69,root,ejemplo);
  Node *node2 = new Node(1,1,1,59,node1,ejemplo);
  Node *node3 = new Node(1,1,1,49,node2,ejemplo);
  Container *heap = new Container(20);
  cout << "Add a node" << endl;
  heap->insert(node1);
  heap->pull()->print();
  cout << "New low cost node" << endl;
  heap->insert(node2);
  heap->pull()->print() ;
  cout << "The node cost is lower than the last one" << endl;
  cout << heap->pull() << endl;
  cout << "The heap size is " << heap->getSize() << endl;
}
