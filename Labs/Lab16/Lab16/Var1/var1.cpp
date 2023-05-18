#include <iostream>
#include <time.h>
#include <ctime>
#include <Windows.h>
using namespace std;

void display_array(int* arr, int N, int i = 0);
void sortBubble(int*, int);  // n^2
void sortInsert(int*, int);  // n^2

void main() {

	int max_B_element = -999;
	int sizeA, sizeB = 0;
	clock_t start, end;
	double soarting_tme;

	cout << "Enter size of array A: "; cin >> sizeA;
	int* A = new int[sizeA];
	for (int i = 0, num; i < sizeA; i++) {
		num = rand() % 200 + 1;
		A[i] = num;
		if (i % 2 == 0 and i != 0)
			sizeB++;
	}

	int* B = new int[sizeB];
	for (int i = 0, j = 0; i < sizeA; i++) {
		if (i % 2 == 0 and i != 0)
			B[j++] = A[i];
	}

	cout << "\narray A: ";
	display_array(A, sizeA);
	cout << "\narray B: ";
	display_array(B, sizeB);

	cout << "\n\narray B sorted by the bubble sort: ";
	start = clock();
	sortBubble(B, sizeB);
	end = clock();
	display_array(B, sizeB);
	soarting_tme = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "\033[1m\033[31m" << "\nsoarting time: " << soarting_tme << endl;

	for (int i = 0, j = 0; i < sizeA; i++) {
		if (i % 2 == 0 and i != 0)
			B[j++] = A[i];
	}
	cout << "\033[1m\033[32m" << "\n\narray B: ";
	display_array(B, sizeB);

	cout << "\n\narray B sorted by the insert sort: ";
	start = clock();
	sortInsert(B, sizeB);
	end = clock();
	display_array(B, sizeB);
	soarting_tme = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "\033[1m\033[31m" << "\nsoarting time: " << soarting_tme << endl;
	cout << "\033[1m\033[32m" << endl;

	delete A;
	delete B;
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

/*
void sortInsert(int* arr, int N) // from min to max
{
	int num;
	for (int i = 1; i < N; i++)
		for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) {//запомним обрабатываемый элемент arr[j]
			num = arr[j - 1];                               // и начнем перемещение элементов слева от него
			// пока запомненный не окажется меньше чем перемещаемый
			arr[j - 1] = arr[j];
			arr[j] = num;
		}
}
*/

void sortInsert(int* arr, int N) // from max to min
{
	int num;
	for (int i = 1; i < N; i++)
		for (int j = i; j > 0 && arr[j - 1] < arr[j]; j--) {
			num = arr[j - 1];
			arr[j - 1] = arr[j];
			arr[j] = num;
		}
}
