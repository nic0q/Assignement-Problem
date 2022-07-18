#include "node.h"

Node::Node() {
  this->job = 0;
  this->cpu = 0;
  this->downCost = 0;
  this->upCost = 0;
}
Node::Node(int cpu, int job, int upCost, int downCost, Node *parent, int* assigned) {
  this->job = job;
  this->cpu = cpu;
  this->upCost = upCost;
  this->downCost = downCost;
  this->parent = parent;
  this->assigned = assigned;
}
Node::~Node (){
}
int Node::getCPU(){
  return this->cpu;
}
void Node::setCPU(int cpu){
  this->cpu = cpu;
}
int Node::getJob(){
  return this->job;
}
void Node:: setJob(int job){
  this->job = job;
}
Node* Node::getParent(){
  return this->parent;
}
void Node::setParent(Node*parent) {
  this->parent = parent;
}
int Node::getCost(){
  return this->upCost;
}
int* Node::getAssigned(){
  return this->assigned;
}
void Node :: setAssigned(int *arr){
  this->assigned = arr;
}
void Node::print() {
  cout << "(" << this->cpu << "," << this->job<< ")["<< this->upCost <<"-"<< this->downCost << "]" <<"->"<< "["<< this->parent->cpu << "," << this->parent->job << "]"<< "<-" << endl;
}
string Node :: getSolve(){
  string s="("+to_string(this->cpu)+","+to_string(this->job)+")";
  if (this->parent != NULL) {
    s = s + this->parent->getSolve();
  }
  return s; 
}
