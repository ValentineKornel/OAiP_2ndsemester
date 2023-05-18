#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int size;
    vector<float> elements_to_check;
    cout << "Input array size: ";
    cin >> size;

    float max_val = 0;
    int max_idx = 0; // начальный индекс максимального элемента
    float min_val = 0;

    float* arr = new float[size];
    for (int i = 0; i < size; i++) {
        bool is_correct = false;
        do {
            cout << "Input " << i + 1 << " element: ";
            cin >> arr[i];
            int counter = count(elements_to_check.begin(), elements_to_check.end(), arr[i]);
            if (counter == 0) {
                elements_to_check.push_back(arr[i]);
                is_correct = true;
            }
            else
                cout << "Incorrect input! this element has already been written down." << endl;
        } while (!is_correct);
        

        // проверка на максимальный и минимальный элементы
        if (arr[i] > max_val) {
            max_val = arr[i];
            max_idx = i;
        }
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
    }

    std::cout << "Max element: " << max_val << ", its position: " << max_idx + 1 << std::endl;
    std::cout << "Min element: " << min_val << std::endl;

    return 0;
}
