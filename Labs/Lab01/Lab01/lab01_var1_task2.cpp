#include "lab01_var1_task2.h"


int fmin(int n, ...) {
	int* p = &n;
	p = p + 2;
	int min_number = 99;
	for (int i = 0; i < n*2; i += 2) {
		if (*(p + i) < min_number)
			min_number = *(p + i);
	}
	return min_number;
}

void doVariant1Task2(){

	cout << fmin(5, 4, 3, 6, 1, 8) << endl;
	cout << fmin(3, 5, 2, 20) << endl;
	cout << fmin(7, 45, 63, 38, 21, 98, 34,73);
}