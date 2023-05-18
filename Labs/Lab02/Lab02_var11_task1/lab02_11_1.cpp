#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int SIZE = 10;

int main() {
	FILE* file;
	errno_t err;
	int array_for_fileA[SIZE];
	int array_for_fileB[SIZE];
	int arrayB_counter = 0;

	cout << "Fill the array with integer numbers" << endl;
	for (int i = 0; i < SIZE; i++) {
		cin >> array_for_fileA[i];
	}

	err = fopen_s(&file, "fileA.bin", "wb");
	if (err != 0) {
		cout << "Error opening";
		return EXIT_FAILURE;
	}
	fwrite(array_for_fileA, sizeof(int), SIZE, file);
	cout << "Numbers are written in the fileA" << endl;
	fclose(file);

	err = fopen_s(&file, "fileA.bin", "rb");
	if (err != 0) {
		cout << "Error opening";
		return EXIT_FAILURE;
	}
	fread(array_for_fileA, sizeof(int), SIZE, file);
	cout << "Numbers read from the fileA: " << endl;
	fclose(file);
	for (int i = 0; i < SIZE; i++) {
		cout << array_for_fileA[i] << ' ';
	}
	cout << endl;

	int k = 0;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < i; j++) {
			if (array_for_fileA[i] == array_for_fileB[j])
				k += 1;
		}

		if (k == 0) {
			array_for_fileB[arrayB_counter] = array_for_fileA[i];
			arrayB_counter += 1;
		}
		k = 0;
	}
	

	err = fopen_s(&file, "fileB.bin", "wb");
	if (err != 0) {
		cout << "Error opening";
		return EXIT_FAILURE;
	}
	fwrite(array_for_fileB, sizeof(int), arrayB_counter, file);
	cout << "Unique numbers are written in the fileB" << endl;
	fclose(file);
	fread(array_for_fileB, sizeof(int), arrayB_counter, file);
	cout << "Numbers read from the fileB: " << endl;
	fclose(file);
	for (int i = 0; i < arrayB_counter; i++) {
		cout << array_for_fileB[i] << ' ';
	}
}