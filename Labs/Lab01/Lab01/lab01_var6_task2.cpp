#include "lab01_var6_task2.h"


int getTheSum(int n, ...) {
	int* p = &n;
	p = p + 2;
	int sum = 0;
	int j = 0;
	for (int i = 0; i < n-1; i ++) {
		
		if (i % 2 == 0)
			sum += (*(p + j)) * (*(p + j + 2));
		else
			sum -= (*(p + j)) * (*(p + j + 2));
		j += 2;
	}
	return sum;
}

void doVariant6Task2() {
	
	cout << endl;
	cout << getTheSum(3, 2, 3, 4) << endl;
	cout << getTheSum(5, 5, 2, 4, 7, 6) << endl;
	cout << getTheSum(7, 45, 63, 38, 21, 98, 3, 5);
}