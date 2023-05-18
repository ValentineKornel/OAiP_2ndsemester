#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int main()
{
    int arr[15];
    srand(time(nullptr));

    for (int i = 0; i < 15; i++) {
        arr[i] = rand() % 11 - 5;
    }

    cout << "Original array: ";
    for (int i = 0; i < 15; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    sort(arr, arr + 15);

    int* last = unique(arr, arr + 15);
    int size = last - arr;

    cout << "Sorted array with dublicates deleted: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
