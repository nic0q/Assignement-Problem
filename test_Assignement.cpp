#include "assignement.h"
#include <time.h>
#include <cmath>

int main(){
	int n, nM, dif_t, cost;
  unsigned t0,t1;
	double time;
	double tp = 0;
  cout << "Tamanio de la Matriz: ";
  cin >> nM;
  Assignement *a = new Assignement(nM);  
  a->getCost()->generateCost();
	a->getCost()->print();
	t0 = clock();
	cost = a->solve();
	cout << cost << endl;
	t1 = clock();
	time = double(t1-t0) / CLOCKS_PER_SEC;
	tp = double(time + tp);
	cout <<"Tiempo: "<< tp << "[s]" << endl;
}