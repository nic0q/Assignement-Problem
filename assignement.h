#include <iostream>
#include "cost.h"
using namespace std;
/*
Represents the solution of the job assignement problem reference the matrix (bidimensional array),
the principal method(solve) returns the optimal cost of the matrix, using the methods (greedy costs and get low branches)

Class Constructor:
n: Matrix size
*/
class Assignement{
  public:
    Assignement(int n); // class constructor
    ~Assignement(); // class destructor
    Cost *getMatrix();  // returns the cost matrix
    int *getAssignement(); // returns the assignement array
    int greedyCost(int x, int y);
    int solve(); // returns the optimal solution of cost matrix
    void printArr(int *arr);  // print the array
    Container *getLowBranches(Node*prev, int processor);  // get the low branches given a node and CPUI
    Cost* getCost();  // pointer to cost matrix
  private:
    Cost *cost; // la matriz de costos
    int *assignement;
    Container generateNextLevel(Container *h);
    int n;
};