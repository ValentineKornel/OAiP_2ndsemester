#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int SIZE = 10;

int main() {
	FILE* file;
	errno_t err;
	int array_for_f[SIZE];
	int array_for_g[SIZE];
	int array_g_counter = 0;
	int number;

	cout << "Fill the array with integer numbers" << endl;
	for (int i = 0; i < SIZE; i++) {
		cin >> array_for_f[i];
	}

	err = fopen_s(&file, "f.bin", "wb");
	if (err != 0) {
		cout << "Error opening";
		return EXIT_FAILURE;
	}
	fwrite(array_for_f, sizeof(int), SIZE, file);
	cout << "Numbers are written in the f" << endl;
	fclose(file);

	err = fopen_s(&file, "f.bin", "rb");
	if (err != 0) {
		cout << "Error opening";
		return EXIT_FAILURE;
	}
	fread(array_for_f, sizeof(int), SIZE, file);
	cout << "Numbers read from the f: " << endl;
	fclose(file);
	for (int i = 0; i < SIZE; i++) {
		cout << array_for_f[i] << ' ';
	}
	cout << endl;

	cout << "Enter the number: ";
	cin >> number;
	for (int i = 0; i < SIZE; i++) {
		if (number < array_for_f[i])
			array_for_g[array_g_counter++] = array_for_f[i];
	}

	err = fopen_s(&file, "g.bin", "wb");
	if (err != 0) {
		cout << "Error opening";
		return EXIT_FAILURE;
	}
	fwrite(array_for_g, sizeof(int), array_g_counter, file);
	cout << "Numbers greater then " << number << " are written in the g" << endl;
	fclose(file);
	fread(array_for_g, sizeof(int), array_g_counter, file);
	cout << "Numbers read from the g: " << endl;
	fclose(file);
	for (int i = 0; i < array_g_counter; i++) {
		cout << array_for_g[i] << ' ';
	}
}