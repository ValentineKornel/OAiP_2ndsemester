#include "lab01_var1_task1.h"


double equation1(double n) {
	double root = sin(n) + pow(n, 3);
	return root;
}

double equation2(double n) {
	double root = 0.4 + pow(n, 3);
	return root;
}

double getTheRoot(double (*equation)(double), double a, double b) {
	double x = 0;
	double f1, f2;
	while (abs(a - b) > 2 * e) {
		x = (a + b) / 2;
		f1 = equation(x);
		f2 = equation(a);
		if (f1 * f2 <= 0)
			b = x;
		else
			a = x;
	}
	return x;
}

void doVariant1Task1() {
	int a;
	int b;

	cout << "Enter a: ";
	cin >> a;
	cout << "Enter b: ";
	cin >> b;

	cout << getTheRoot(equation1, a, b) << endl;
	cout << getTheRoot(equation2, a, b);
}