#include <iostream>
#include <math.h>
#include "node.h"
using namespace std;
/*
Represents the heap is a data structure wich principal function is order the nodes inside
given a condition in this case using the low cost, the principal methos are, return the low node
print the heap and get the size.

Class Constructor:
size: Heap size
*/
class Container {
public:
  Container(int size);
  ~Container();
  int isEmpty();
  void insert(Node *node);
  Node* pull();
  Node* peek();
  int getSize();
  void print();
  bool inHeap(Node e);
  Node *getArr();
private:
  int size;
  int count;
  Node *arr;
  void swap(int i, int j);
  void bubbleUp();
  void bubbleDown();
};
