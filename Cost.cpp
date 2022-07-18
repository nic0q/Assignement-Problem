#include "cost.h"
#include "vector"

// Constructor requires the size of the square matrix
Cost::Cost(int N) {
  this->N = N;
  srand(time(NULL));
  cost=nullptr;
  generateCost();
}
// Must delete the matrix
Cost::~Cost() {
  delete[] cost;
}
void Cost::setCost(int i, int j, int value) {
  cost[i][j] = value;
}
int Cost::getCost(int i, int j) {
  return cost[i][j];
}
// getter for the size of the matrix
int Cost::getN() {
  return N;
}
/* Generate a random cost matrix with values between 1 and N
   with no repetition by row.
*/
void Cost::generateCost() {
  // this allows this method to be reentrant
  if (cost != nullptr) {
    delete[] cost;
  }
  cost = new int*[N];
  jobs = new bool[N];
  for (int i = 0; i < N; i++) {
    jobs[i] = false;
    cost[i] = new int[N];
  }
  // generating a random cost matrix with 1/5 of possible repetition by column
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cost[i][j] = 1+rand() % (N+N/5+1);
      while (isNotNewCost(i, j)) {
        cost[i][j] = 1+rand() % (N+N/5+1);
      }
    }
  }
  // overrriding 1/5 of the matrix by the number N/5 without repetition by row
  int k = 0;
  while(k<N/5) {
    int i = rand() % N;
    int j = rand() % N;
    int backup=cost[i][j];
    cost[i][j]=N/5;
    if (!isNotNewCost(i, j)) {
      //cout << i << " " << j << endl;
      k++;
    } else {
      cost[i][j]=backup;
    }
  }
}
void Cost::print() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << cost[i][j] << " ";
    }
    cout << endl;
  }
}
/*
* Check if the cost is already in the matrix row from the left of j
*/
int Cost::isNotNewCost(int i, int j) {
  for (int k = 0; k < j; k++) {
    if (cost[i][j] == cost[i][k]) {
      return 1;
    }
  }
  return 0;
}

void Cost :: findMinCost(int **cost){
  Container heap(N*N);
  vector<bool>assigned;
}
int** Cost :: getMatrix(){
  return cost;
}