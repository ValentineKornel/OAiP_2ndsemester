#include <iostream>
#include <time.h>
#include <ctime>
#include <Windows.h>
using namespace std;

void display_array(int* arr, int N, int i  = 0);
void sortBubble(int*, int);  // n^2
void sortInsert(int*, int);  // n^2

void main() {
	
	int max_B_element = -999;
	int sizeC = 0, sizeA, sizeB;
	clock_t start, end;
	double soarting_time;

	cout << "Enter size of array B: "; cin >> sizeB;
	int* B = new int[sizeB];
	srand(time(NULL));
	for (int i = 0, num; i < sizeB; i++) {
		num = rand() % 300 + 1;
		B[i] = num;
		if (num > max_B_element)
			max_B_element = num;
	}
	display_array(B, sizeB);

	cout << "Enter size of array A: "; cin >> sizeA;
	int* A = new int[sizeA];
	for (int i = 0, num; i < sizeA; i++) {
		num = rand() % 1000 + 1;
		A[i] = num;
		if (num > max_B_element)
			sizeC++;
	}
	display_array(A, sizeA);
	int* C = new int[sizeC];
	for (int i = 0, j =0; i < sizeA; i++) {
		if (A[i] > max_B_element)
			C[j++] = A[i];
	}
	
	start = clock();
	sortBubble(C, sizeC);
	end = clock();

	soarting_time = (double)(end - start) / CLOCKS_PER_SEC;
	double bubble = soarting_time;
	cout << "\033[1m\033[31m" << "\nsoarting time: " << soarting_time << endl;

	for (int i = 0, j = 0; i < sizeA; i++) {
		if (A[i] > max_B_element)
			C[j++] = A[i];
	}
	cout << "\n\narray C: " << "\033[1m\033[32m";


	cout << "\033[1m\033[31m" << "\n\narray C sorted by the insert sort: " << "\033[1m\033[32m";
	start = clock();
	sortInsert(C, sizeC);
	end = clock();
	display_array(C, sizeC);

	soarting_time = (double)(end - start) / CLOCKS_PER_SEC;
	double insert = soarting_time;
	cout << "\033[1m\033[31m" << "\nsoarting time: " << soarting_time << endl;
	cout << "Bubble: " << bubble << endl;
	cout << "Insert: " << insert << endl;
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
