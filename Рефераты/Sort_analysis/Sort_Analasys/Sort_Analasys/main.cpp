#include <iostream>
#include <time.h>
#include <ctime>
#include <Windows.h>
#include <string>
#include <cstdlib>
using namespace std;

void display_array(int* arr, int N, int i = 0);
void display_array(double* arr, int N, int i = 0);
void display_array(string* arr, int N, int i = 0);
void sortBubble(int*, int);  // n^2
void sortBubble(string*, int);
void sortBubble(double*, int);
void sortInsert(int*, int);  // n^2
void sortInsert(double*, int);
void sortInsert(string*, int);
void sortSelection(int*, int); // n^2
void sortSelection(double*, int);
void sortSelection(string*, int);
void merge(int* arr, int left, int mid, int right);
void mergeSort(int* arr, int left, int right);
void merge(double* arr, int left, int mid, int right);
void mergeSort(double* arr, int left, int right);
void merge(string* arr, int left, int mid, int right);
void mergeSort(string* arr, int left, int right);
void heapify(int arr[], int n, int i);
void heapSort(int arr[], int n);
void heapify(double arr[], int n, int i);
void heapSort(double arr[], int n);
void heapify(string* arr, int n, int i);
void heapSort(string* arr, int n);
void sortQuick(int* arr, int first, int last); // n * log n
void sortQuick(double* arr, int first, int last);
void sortQuick(string* arr, int first, int last); // n * log n

void main() {

	int max_B_element = -999;
	int sizeA, sizeS, sizeD;
	clock_t start, end;
	double soarting_tme;

	
	/*
	cout << "Enter size of array D: "; cin >> sizeD;

	double* D = new double[sizeD];
	std::srand(static_cast<unsigned int>(std::time(nullptr)));  // Seed the random number generator

	for (int i = 0; i < sizeD; i++) {
		double num = static_cast<double>(std::rand()) / RAND_MAX * 1000.0;  // Generate a random double between 0 and 1000
		D[i] = num;
	}

	cout << "\narray D:" << std::endl;
	display_array(D, sizeD);

	cout << "\n\n sorted array D: \n\n";
	start = clock();
	sortBubble(D, sizeD);
	//sortInsert(D, sizeD);
	//sortSelection(D, sizeD);
	//mergeSort(D, 0, sizeD - 1);
	//heapSort(D, sizeD);
	//sortQuick(D, 0, sizeD - 1);
	end = clock();

	display_array(D, sizeD);
	soarting_tme = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "\nsoarting time: " << soarting_tme << endl;
	*/


	/*
	cout << "Enter size of array S: "; cin >> sizeS;
	string* S = new string[sizeS];
	srand(time(0));

	// «аполнение массива строк случайными значени€ми
	for (int i = 0; i < sizeS; i++)
	{
		int length = rand() % 10 + 1;  // —лучайна€ длина строки от 1 до 10 символов
		string randomString;
		for (int j = 0; j < length; j++)
		{
			char randomChar = 'A' + rand() % 26;  // —лучайна€ буква в верхнем регистре
			randomString += randomChar;
		}
		S[i] = randomString;
	}
	//cout << "\narray S: " << endl;
	//display_array(S, sizeS);

	//cout << "\n\n sorted array S: \n";
	start = clock();
	//sortBubble(S, sizeS);
	//sortInsert(S, sizeS);
	//sortSelection(S, sizeS);
	//mergeSort(S, 0, sizeS - 1);
	//heapSort(S, sizeS);
	sortQuick(S, 0, sizeS - 1);
	end = clock();

	//display_array(S, sizeS);
	soarting_tme = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "\nsoarting time: " << soarting_tme << endl;
	*/
	

	
	cout << "Enter size of array A: "; cin >> sizeA;
	int* A = new int[sizeA];
	for (int i = 0, num; i < sizeA; i++) {
		num = rand() % 1000 + 1;
		A[i] = num;
	}

	cout << "\narray A: " << endl;
	display_array(A, sizeA);

	cout << "\n\sorted srray A: " << endl;
	start = clock();
	//sortBubble(A, sizeA);
	//sortInsert(A, sizeA);
	//sortSelection(A, sizeA);
	//mergeSort(A, 0, sizeA - 1);
	//heapSort(A, sizeA);
	sortQuick(A, 0, sizeA - 1);
	end = clock();

	display_array(A, sizeA);
	soarting_tme = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "\nsoarting time: " << soarting_tme << endl;
	

}

void display_array(double* arr, int N, int i) {
	if (i == N)
		return;
	cout << arr[i++] << " ";
	display_array(arr, N, i);
}

void display_array(int* arr, int N, int i) {
	if (i == N)
		return;
	cout << arr[i++] << " ";
	display_array(arr, N, i);
}

void display_array(string* arr, int N, int i) {
	if (i == N)
		return;
	cout << arr[i++] << " ";
	display_array(arr, N, i);
}


void sortBubble(int* arr, int N)
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

void sortBubble(double* arr, int N)
{
	double buff = 0;

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

void sortBubble(string* arr, int N)
{
	string temp;

	for (int i = 0; i < N - 1; i++)
	{
		for (int j = N - 1; j > i; j--)
		{
			if (arr[j] < arr[j - 1])  // —равниваем строки в лексикографическом пор€дке
			{
				temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void sortInsert(int* arr, int N)
{
	int num;
	for (int i = 1; i < N; i++)
		for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) {//запомним обрабатываемый элемент arr[j]
			num = arr[j - 1];                               // и начнем перемещение элементов слева от него
			// пока запомненный не окажетс€ меньше чем перемещаемый
			arr[j - 1] = arr[j];
			arr[j] = num;
		}
}
void sortInsert(double* arr, int N)
{
	double num;
	for (int i = 1; i < N; i++)
		for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) {//запомним обрабатываемый элемент arr[j]
			num = arr[j - 1];                               // и начнем перемещение элементов слева от него
			// пока запомненный не окажетс€ меньше чем перемещаемый
			arr[j - 1] = arr[j];
			arr[j] = num;
		}
}
void sortInsert(string* arr, int N)
{
	string temp;

	for (int i = 1; i < N; i++)
	{
		for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--)
		{
			temp = arr[j - 1];
			arr[j - 1] = arr[j];
			arr[j] = temp;
		}
	}
}

void sortSelection(int* arr, int N)
{
	int min = 0;
	int buf = 0;
	for (int i = 0; i < N; i++)
	{
		min = i;
		for (int j = i + 1; j < N; j++)
			min = (arr[j] < arr[min]) ? j : min;
		if (i != min)
		{
			buf = arr[i];
			arr[i] = arr[min];
			arr[min] = buf;
		}
	}
}
void sortSelection(double* arr, int N)
{
	int min = 0;
	double buf = 0;
	for (int i = 0; i < N; i++)
	{
		min = i;  // запомним номер текущей €чейки, как €чейки с минимальным значением
		for (int j = i + 1; j < N; j++)  // в цикле найдем реальный номер €чейки с минимальным значением
			min = (arr[j] < arr[min]) ? j : min;
		if (i != min)
		{
			buf = arr[i];
			arr[i] = arr[min];
			arr[min] = buf;
		}
	}
}
void sortSelection(string* arr, int N)
{
	int minIndex = 0;
	string temp;

	for (int i = 0; i < N; i++)
	{
		minIndex = i;

		for (int j = i + 1; j < N; j++)
		{
			if (arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
		}

		if (i != minIndex)
		{
			temp = arr[i];
			arr[i] = arr[minIndex];
			arr[minIndex] = temp;
		}
	}
}


void merge(int* arr, int left, int mid, int right) {
	int n1 = mid - left + 1;
	int n2 = right - mid;

	int* L = new int[n1];
	int* R = new int[n2];

	for (int i = 0; i < n1; i++)
		L[i] = arr[left + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[mid + 1 + j];

	int i = 0;
	int j = 0;
	int k = left;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}

	delete[] L;
	delete[] R;
}
void mergeSort(int* arr, int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;

		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);

		merge(arr, left, mid, right);
	}
}
void merge(double* arr, int left, int mid, int right) {
	int n1 = mid - left + 1;
	int n2 = right - mid;

	double* L = new double[n1];
	double* R = new double[n2];

	for (int i = 0; i < n1; i++)
		L[i] = arr[left + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[mid + 1 + j];

	int i = 0;
	int j = 0;
	int k = left;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}

	delete[] L;
	delete[] R;
}
void mergeSort(double* arr, int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;

		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);

		merge(arr, left, mid, right);
	}
}

void merge(string* arr, int left, int mid, int right) {
	int n1 = mid - left + 1;
	int n2 = right - mid;

	string* L = new string[n1];
	string* R = new string[n2];

	for (int i = 0; i < n1; i++)
		L[i] = arr[left + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[mid + 1 + j];

	int i = 0;
	int j = 0;
	int k = left;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}

	delete[] L;
	delete[] R;
}

void mergeSort(string* arr, int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;

		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);

		merge(arr, left, mid, right);
	}
}


void heapify(int arr[], int n, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && arr[left] > arr[largest])
		largest = left;

	if (right < n && arr[right] > arr[largest])
		largest = right;

	if (largest != i) {
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}
void heapSort(int arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	for (int i = n - 1; i >= 0; i--) {
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}
void heapify(double arr[], int n, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && arr[left] > arr[largest])
		largest = left;

	if (right < n && arr[right] > arr[largest])
		largest = right;

	if (largest != i) {
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}
void heapSort(double arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	for (int i = n - 1; i >= 0; i--) {
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}

void heapify(string* arr, int n, int i) {
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && arr[left] > arr[largest])
		largest = left;

	if (right < n && arr[right] > arr[largest])
		largest = right;

	if (largest != i) {
		std::swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}

void heapSort(string* arr, int n) {
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	for (int i = n - 1; i >= 0; i--) {
		std::swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}

void sortQuick(int* arr, int first, int last)
{
	int mid, count;
	int f = first, l = last;
	mid = arr[(f + l) / 2];
	do
	{
		while (arr[f] < mid)
			f++;
		while (arr[l] > mid)
			l--;
		if (f <= l)
		{
			count = arr[f];
			arr[f] = arr[l];
			arr[l] = count;
			f++;
			l--;
		}
	} while (f < l);
	if (first < l) sortQuick(arr, first, l);
	if (f < last) sortQuick(arr, f, last);
}
void sortQuick(double* arr, int first, int last)
{
	double mid, count;
	int f = first, l = last;
	mid = arr[(f + l) / 2];
	do
	{
		while (arr[f] < mid)
			f++;
		while (arr[l] > mid)
			l--;
		if (f <= l)
		{
			count = arr[f];
			arr[f] = arr[l];
			arr[l] = count;
			f++;
			l--;
		}
	} while (f < l);
	if (first < l) sortQuick(arr, first, l);
	if (f < last) sortQuick(arr, f, last);
}

void sortQuick(std::string* arr, int first, int last) {
	int mid, count;
	int f = first, l = last;
	mid = (f + l) / 2;
	std::string pivot = arr[mid];
	do {
		while (arr[f].compare(pivot) < 0)
			f++;
		while (arr[l].compare(pivot) > 0)
			l--;
		if (f <= l) {
			std::swap(arr[f], arr[l]);
			f++;
			l--;
		}
	} while (f <= l);
	if (first < l)
		sortQuick(arr, first, l);
	if (f < last)
		sortQuick(arr, f, last);
}



