#include <iostream>
using namespace std;
#include "cola.h"

unsigned int afortunado(unsigned int n, unsigned int m) {

	Cola<int> queue;

	for (int i = 1; i <= n; i++)
		queue.pon(i);

	int count=1, value = queue.primero();

	queue.quita();
	while (!queue.esVacia()) {
		if (count != m)
			queue.pon(value);
		value = queue.primero();
		queue.quita();
		count = count % m;
		count++;
	}
	return value;
}


int main() {
	int n, m;
	while ((cin >> n)) {
		cin >> m;
		cout << afortunado(n, m) << endl;
	}
	return 0;
}