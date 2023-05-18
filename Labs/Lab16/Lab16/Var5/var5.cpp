#include <iostream>
#include <time.h>
#include <ctime>
#include <Windows.h>
using namespace std;

void display_array(int* arr, int N, int i = 0);
void sortBubble(int*, int);  // n^2
void sortSelection(int* arr, int N); // n^2

void main() {

	int sizeC = 0, sizeA, sizeB;
	clock_t start, end;
	double sorting_time;

	cout << "Enter size of array A: "; cin >> sizeA;
	int* A = new int[sizeA];
	for (int i = 0, num; i < sizeA; i++) {
		num = rand() % 200 + 1;
		A[i] = num;
		if (i % 2 == 0 and i != 0)
			sizeC++;
	}

	cout << "Enter size of array B: "; cin >> sizeB;
	int* B = new int[sizeB];
	srand(time(NULL));
	for (int i = 0, num; i < sizeB; i++) {
		num = rand() % 200 + 1;
		B[i] = num;
		if (i % 2 != 0 and i != 0)
			sizeC++;
	}

	int c_counter = 0;
	int* C = new int[sizeC];
	for (int i = 0; i < sizeA; i++) {
		if (i % 2 == 0 and i != 0)
			C[c_counter++] = A[i];
	}
	for (int i = 0; i < sizeB; i++) {
		if (i % 2 != 0 and i != 0)
			C[c_counter++] = B[i];
	}

	cout << "\narray A: ";
	display_array(A, sizeA);
	cout << "\narray B: ";
	display_array(B, sizeB);
	cout << "\narray C: ";
	display_array(C, sizeC);
	cout << "\n\narray C sorted by the bubble sort: ";
	start = clock();
	sortBubble(C, sizeC);
	end = clock();
	display_array(C, sizeC);
	sorting_time = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "\033[1m\033[31m" << "\nsoarting time: " << sorting_time << endl;

	c_counter = 0;
	for (int i = 0; i < sizeA; i++) {
		if (i % 2 == 0 and i != 0)
			C[c_counter++] = A[i];
	}
	for (int i = 0; i < sizeB; i++) {
		if (i % 2 != 0 and i != 0)
			C[c_counter++] = B[i];
	}
	cout << "\033[1m\033[32m" << "\n\narray C: ";
	display_array(C, sizeC);

	cout << "\n\narray C sorted by the selection sort: ";
	start = clock();
	sortSelection(C, sizeC);
	end = clock();
	display_array(C, sizeC);
	sorting_time = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "\033[1m\033[31m" << "\nsoarting time: " << sorting_time << endl;
	cout << "\033[1m\033[32m" << endl;


	delete A;
	delete B;
	delete C;
}

void display_array(int* arr, int N, int i) {
	if (i == N)
		return;
	cout << arr[i++] << " ";
	display_array(arr, N, i);
}

/*
void sortBubble(int* arr, int N)  from min to max
{
	int buff = 0;

	for (int i = 0; i < N - 1; i++)
	{
		for (int j = N - 1; j > i; j--)
		{
			if (arr[j] < arr[j - 1])
			{
				buff = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = buff;
			}
		}
	}
}
*/

void sortBubble(int* arr, int N)  // from mam to min
{
	int buff = 0;

	for (int i = 0; i < N - 1; i++)
	{
		for (int j = N - 1; j > i; j--)
		{
			if (arr[j] > arr[j - 1])
			{
				buff = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = buff;
			}
		}
	}
}

void sortSelection(int* arr, int N)
{
	int min = 0;
	int buf = 0;
	for (int i = 0; i < N; i++)
	{
		min = i;  // запомним номер текущей €чейки, как €чейки с минимальным значением
		for (int j = i + 1; j < N; j++)  // в цикле найдем реальный номер €чейки с минимальным значением
			min = (arr[j] > arr[min]) ? j : min;
		if (i != min)
		{
			buf = arr[i];
			arr[i] = arr[min];
			arr[min] = buf;
		}
	}
}
