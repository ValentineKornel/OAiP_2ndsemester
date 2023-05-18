#include "lab01_var4_task2.h"


int fmax(int n, ...) {
	int* p = &n;
	p = p + 2;
	int max_number = 0;
	for (int i = 0; i < n * 2; i += 2) {
		if (*(p + i) > max_number)
			max_number = *(p + i);
	}
	return max_number;
}

void doVariant4Task2() {

	cout << fmax(5, 4, 3, 6, 1, 8) << endl;
	cout << fmax(3, 5, 2, 20) << endl;
	cout << fmax(7, 45, 63, 38, 21, 98, 3, 5);
}