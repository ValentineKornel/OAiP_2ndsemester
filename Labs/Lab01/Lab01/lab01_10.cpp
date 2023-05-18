#include <iostream>
#include <math.h>

#include "lab01_var10_task1.h"
#include "lab01_var10_task2.h"
#include "lab01_var1_task1.h"
#include "lab01_var1_task2.h"
#include "lab01_var4_task1.h"
#include "lab01_var4_task2.h"
#include "lab01_var6_task1.h"
#include "lab01_var6_task2.h"

using namespace std;

double e = 0.001;

void main() {
	int choise = 5;
	do {
		cout << "\n\nChoose task number " << endl;
		cout << "1 = variant 10 task 1," << " 2 = variant 10 task 2" << endl;
		cout << "3 = variant 1 task 1," << " 4 = variant 1 task 2" << endl;
		cout << "5 = variant 4 task 1," << " 6 = variant 4 task 2" << endl;
		cout << "7 = variant 6 task 1" << endl;
		cout << "8 = variant 6 task 2, " << " 9 - exit" << endl;
		cin >> choise;
		switch (choise) {

		case 1: {
			doVariant10Task1();
			break;
		}
		case 2: {
			doVariant10Task2();
			break;
		}
		case 3: {
			doVariant1Task1();
			break;
		}
		case 4: {
			doVariant1Task2();
			break;
		}
		case 5: {
			doVariant4Task1();
			break;
		}
		case 6: {
			doVariant4Task2();
			break;
		}
		case 7: {
			doVariant6Task1();
			break;
		}
		case 8: {
			doVariant6Task2();
		}
		}

	} while (choise != 9);
}