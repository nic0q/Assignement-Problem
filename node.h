#include <iostream>
using namespace std;
/*
Represent the node of the tree with job assigned and cpu,an array with nodes locked
or alredy visited, and the connection to his father with *previous pointer.
Class constructor:
  CPU: y coordinate
  Job: x coordinate
  upCost: cost stimation
  downCost: matrix cost
  parent: previus node
  assigned: assignement array
*/
class Node {
public:
  Node();
  ~Node();
  Node(int cpu,int job,int cost,int ncost, Node *previous, int *assigned);
  int getJob();
  void setJob(int cpu);
  int getCPU();
  void setCPU(int cpu);
  int getCost();
  void setCost(int cost);
  int* getAssigned();
  void setAssigned(int* arr);
  Node* getParent();
  void setParent(Node *previous);
  void print();
  string getSolve();
  bool isAssigned();
private:  
  int job;
  int cpu; 
  int upCost;
  int downCost;
  int size;
  int *assigned;
  Node *parent; // the previous node in the path
};
  