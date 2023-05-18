#include <iostream>
#include <time.h>
#include <ctime>
#include <Windows.h>
using namespace std;

#define ifdisplay

void display_array(int* arr, int N, int i = 0);
void sortSelection(int* arr, int N); // n^2
void merge(int* arr, int left, int mid, int right);
void mergeSort(int* arr, int left, int right);
void heapify(int arr[], int n, int i);
void heapSort(int arr[], int n);

void main() {

	int sizeA = 0;
	clock_t start, end;
	double sorting_time;

	cout << "Enter size of array A: "; cin >> sizeA;
	int* A = new int[sizeA];
	for (int i = 0, num; i < sizeA; i++) {
		num = rand() % 10000 + 1;
		A[i] = num;
	}

	cout << "\narray A: ";
#ifdef ifdisplay
	display_array(A, sizeA);
#endif

	cout << "\n\narray A sorted by the selection sort: ";
	start = clock();
	sortSelection(A, sizeA);
	end = clock();
#ifdef ifdisplay
    display_array(A, sizeA);
#endif
	sorting_time = (double)(end - start) / CLOCKS_PER_SEC;
    double selection = sorting_time;
	cout << "\033[1m\033[31m" << "\nsoarting time: " << sorting_time << endl;
	cout << "\033[1m\033[32m" << endl;

    for (int i = 0, num; i < sizeA; i++) {
        num = rand() % 10000 + 1;
        A[i] = num;
    }
    cout << "New generated array A: ";
#ifdef ifdisplay
    display_array(A, sizeA);
#endif

    cout << "\n\narray A sorted by the merge sort: ";
    start = clock();
    mergeSort(A, 0, sizeA - 1);
    end = clock();
#ifdef ifdisplay
    display_array(A, sizeA);
#endif
    sorting_time = (double)(end - start) / CLOCKS_PER_SEC;
    double merge = sorting_time;
    cout << "\033[1m\033[31m" << "\nsoarting time: " << sorting_time << endl;
    cout << "\033[1m\033[32m" << endl;

    for (int i = 0, num; i < sizeA; i++) {
        num = rand() % 10000 + 1;
        A[i] = num;
    }
    cout << "New generated array A: ";
#ifdef ifdisplay
    display_array(A, sizeA);
#endif

    cout << "\n\narray A sorted by the heapify sort: ";
    start = clock();
    heapSort(A, sizeA);
    end = clock();
#ifdef ifdisplay
    display_array(A, sizeA);
#endif
    sorting_time = (double)(end - start) / CLOCKS_PER_SEC;
    double heapify = sorting_time;
    cout << "\033[1m\033[31m" << "\nsoarting time: " << sorting_time << endl;
    cout << "selection: " << selection << endl;
    cout << "merge: " << merge << endl;
    cout << "heapify: " << heapify << endl;
    cout << "\033[1m\033[32m" << endl;


}

void display_array(int* arr, int N, int i) {
	if (i == N)
		return;
	cout << arr[i++] << " ";
	display_array(arr, N, i);
}


void sortSelection(int* arr, int N)
{
	int min = 0;
	int buf = 0;
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
