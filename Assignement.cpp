#include "assignement.h"

Assignement :: Assignement(int n){  // class constructor given a "n" matrix dimension
  this->n = n;
  this->cost = new Cost(n);
}
Cost* Assignement :: getCost(){ // get the cost matrix
  return this->cost;
}
Assignement :: ~Assignement(){  // class destructor
  delete cost;
}
Cost *Assignement :: getMatrix(){ // get the cost matrix
  return this->cost;
}
/*greedyCost: Calculates the minimun cost using greedy algorithm
I: proccesor(i), job(j)
O: the minimal cost (integer)*/
int Assignement :: greedyCost(int proc, int job){
  int greedy = 0;
  for(int i = proc + 1; i < n; i++){
    int minor = -1;
    for(int j = 0; j < n; j++){
      if(j == job){
        continue;
      }
      else if(minor == -1 || minor > cost->getMatrix()[i][j]){
        minor = cost->getMatrix()[i][j];
      }
    }
    greedy+=minor;
  }
  return greedy + cost->getMatrix()[proc][job];
}
/*
Auxiliar Function create an array with -1 from 0 to n
I: n: array size
O: *array of ints*/
int* createArray(int n){
  int *arr = new int[n];
  for(int i = 0; i < n; i++){
    arr[i] = -1;
  }
  return arr;
}
/*return the low childs/branches/nodes given a father and processor/x/CPU
I: Node*(father), int Father
O: Container(Heap)*/
Container* Assignement :: getLowBranches(Node* prev, int processor){
  Container* tempHeap = new Container(n);
  Container* h = new Container(n);  // every row have a heap
  for(int i = 0; i < n; i++){
    if(prev->getAssigned()[i] == -1){ // cut nodes
      Node *child = new Node(processor,i,cost->getMatrix()[processor][i]+prev->getCost(),greedyCost(processor,i),prev,nullptr);
      h->insert(child);
    }
  }
  int minCost = h->peek()->getCost();
  int i = 0;
  while(!h->isEmpty() && h->peek()->getCost() == minCost){  // obtains all the minimun cost childs
    Node *children = h->pull();
    int j = children->getJob();
    int *newArr = new int[n];
    for(int k = 0;k < n;k++){
      newArr[k] = prev->getAssigned()[k];
    }
    newArr[j] = 0;
    children->setAssigned(newArr);   
    tempHeap->insert(children);
  }
  return tempHeap;
}
/*returns the optimal cost from nxn matrix
I: n: dimensions of the matrix(columns and rows)
O: Container(Heap)*/
int Assignement :: solve(){
  Node *root= new Node(-1,-1,0,0,nullptr,createArray(n));  // first node
  Container *mainHeap = new Container(n*n); // 2**n  2**n*n
  mainHeap->insert(root);
  int proc = 0;
  while(proc<n){
    Container *childs = getLowBranches(mainHeap->pull(),proc);
    int cont = 0;
    while(!childs->isEmpty()){
      mainHeap->insert(childs->pull());
      cont++;
    }
    if(cont > 1){ // if exists two or more equal childs
      mainHeap->pull();  // take the second one
    }
    proc++;
  }
  return mainHeap->peek()->getCost();
}