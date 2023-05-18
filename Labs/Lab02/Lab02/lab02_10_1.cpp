#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int SIZE = 10;

int main() {
	FILE* file;
	errno_t err;
	int array_to_write[SIZE];
	int array_to_read[SIZE];

	cout << "Fill the array with integer numbers" << endl;
	for (int i = 0; i < SIZE; i++) {
		cin >> array_to_write[i];
	}

	err = fopen_s(&file, "numbers.bin", "wb");
	if (err != 0) {
		cout << "Error opening";
		return EXIT_FAILURE;
	}
	fwrite(array_to_write, sizeof(int), SIZE, file);
	cout << "Numbers are written in the file" << endl;
	fclose(file);

	err = fopen_s(&file, "numbers.bin", "rb");
	if (err != 0) {
		cout << "Error opening";
		return EXIT_FAILURE;
	}
	fread(array_to_read, sizeof(int), SIZE, file);
	cout << "Numbers is read from the file: " << endl;
	fclose(file);
	for (int i = 0; i < SIZE; i++) {
		cout << array_to_read[i];
	}
	cout << endl;

	float closiest_average = 999.0;
	float average;
	float subtract;
	int x;
	int a, b;
	cout << "Enter x: ";
	cin >> x;
	for (int i = 0; i < SIZE; i++) {
		for (int j = i + 1; j < SIZE; j++) {
			average =  (float(array_to_read[i]) + array_to_read[j]) / 2;
			if (average > x)
				subtract = average - x;
			else
				subtract = x - average;
			if (subtract < closiest_average) {
				closiest_average = subtract;
				a = array_to_read[i];
				b = array_to_read[j];
			}
		}
	}
	cout << endl;
	cout << "Closiest average: " << closiest_average << endl;
	cout << "Numbers: " << a << ", " << b;
}
