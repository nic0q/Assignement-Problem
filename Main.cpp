#include "assignement.h"
#include <time.h>
#include <cmath>

int main(){
	int n, nM, dif_t, costo;
  unsigned t0,t1;
	double time;
	double tp = 0;
	int acum = 0;
  cout << "Tamanio de la Matriz: ";
  cin >> nM;
	cout << "Cantidad de pruebas: ";
	cin >> n;
  Assignement *a = new Assignement(nM);  
  for(int i = 0; i < n; i++){
    a->getCost()->generateCost();
		t0 = clock();
		costo = a->solve();
		cout << costo << endl;
		t1 = clock();
		time = double(t1-t0) / CLOCKS_PER_SEC;
		tp = double(time + tp);
		acum+=costo;
  }
	cout <<"Promedio: "<< tp / n << "[s]" << endl;
	cout <<"Costo: " << acum / n << endl;
}