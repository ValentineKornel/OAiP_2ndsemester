#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <algorithm>

class Heap
{
public:
    Heap(const std::vector<int>& arr)
    {
        capacity = size = arr.size();
        storage = new int[capacity];
        for (int i = 0; i < size; i++) {
            storage[i] = arr[i];
        }

        buildHeap();
    }

    ~Heap()
    {
        delete[] storage;
    }

    void print()
    {
        int probel = 20;
        if (size == 0)
            std::cout << "The heap is empty" << std::endl;
        for (int j = 0; j < size; j++) {
            std::cout << storage[j] << " ";
        }
        std::cout << std::endl;
        for (int u = 0, y = 0; u < size; u++)
        {
            std::cout << std::setw(probel + 10) << std::setfill(' ');
            std::cout << storage[u];
            if (u == y)
            {
                std::cout << '\n';
                if (y == 0)
                    y = 2;
                else
                    y += y * 2;
            }
            probel /= 2;
        }
        std::cout << '\n';

    }

private:
    int* storage;
    int size;
    int capacity;

    void heapify(int i)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < size && storage[left] > storage[largest]) {
            largest = left;
        }

        if (right < size && storage[right] > storage[largest]) {
            largest = right;
        }

        if (largest != i) {
            std::swap(storage[i], storage[largest]);
            heapify(largest);
        }
    }

    void buildHeap()
    {
        for (int i = size / 2 - 1; i >= 0; i--) {
            heapify(i);
        }
    }
};

using namespace std;

int main()
{
    int choice;
    int current_arr = 1;
    std::set<int> arr1;
    std::set<int> arr2;
    std::set<int> arr3;

    Heap heap1(std::vector<int>(arr1.begin(), arr1.end()));
    Heap heap2(std::vector<int>(arr2.begin(), arr2.end()));
    Heap heap3(std::vector<int>(arr3.begin(), arr3.end()));

    for (;;) {
        std::system("cls");
        if (current_arr == 1) {
            Heap temp_heap(std::vector<int>(arr1.begin(), arr1.end()));
            heap1 = temp_heap;
            cout << "------The first heap------" << endl;
            heap1.print();
        }
        if (current_arr == 2) {
            Heap temp_heap(std::vector<int>(arr2.begin(), arr2.end()));
            heap2 = temp_heap;
            cout << "------The second heap------" << endl;
            heap2.print();
        }
        if (current_arr == 3) {
            Heap temp_heap(std::vector<int>(arr3.begin(), arr3.end()));
            heap3 = temp_heap;
            cout << "------The third heap------" << endl;
            heap3.print();
        }
        cout << endl;
        cout << "1 - to add element" << endl;
        cout << "2 - delet slmallest element" << endl;
        cout << "3 - delete biggest element" << endl;
        cout << "4 - to delete neede element" << endl;
        cout << "5 - to merge first and second heaps into the third one" << endl;
        cout << "6 - to switch heap" << endl;
        cout << "0 to exit" << endl;
        cout << "Your choice? ";
        cin >> choice;
        switch (choice) {
        case 0: exit(0);
        case 1:
        {
            int number;
            cout << "Enter the element" << endl;
            cin >> number;
            if(current_arr == 1)
                arr1.insert(number);
            if (current_arr == 2)
                arr2.insert(number);
            if (current_arr == 3)
                arr3.insert(number);
            break;
        }
        case 2: {
            if (current_arr == 1) {
                auto min_element_it = std::min_element(arr1.begin(), arr1.end());
                int min_element = *min_element_it;
                arr1.erase(min_element);
            }
            if (current_arr == 2) {
                auto min_element_it = std::min_element(arr2.begin(), arr2.end());
                int min_element = *min_element_it;
                arr2.erase(min_element);
            }
            if (current_arr == 3) {
                auto min_element_it = std::min_element(arr3.begin(), arr3.end());
                int min_element = *min_element_it;
                arr3.erase(min_element);
            }
            break;
        }
        case 3: {
            if (current_arr == 1) {
                auto max_element_it = std::max_element(arr1.begin(), arr1.end());
                int max_element = *max_element_it;
                arr1.erase(max_element);
            }
            if (current_arr == 2) {
                auto max_element_it = std::max_element(arr2.begin(), arr2.end());
                int max_element = *max_element_it;
                arr2.erase(max_element);
            }
            if (current_arr == 3) {
                auto max_element_it = std::max_element(arr3.begin(), arr3.end());
                int max_element = *max_element_it;
                arr3.erase(max_element);
            }
            break;
        }
        case 4:
        {
            int element_to_delete;
            cout << "Enter the element to delete ";
            cin >> element_to_delete;
            if (current_arr == 1)
                arr1.erase(element_to_delete);
            if (current_arr == 2)
                arr2.erase(element_to_delete);
            if (current_arr == 3)
                arr3.erase(element_to_delete);
            break;
        }
        case 5: {
            arr3.insert(arr1.begin(), arr1.end());
            arr3.insert(arr2.begin(), arr2.end());
            cout << "heaps has just been merged. Chek third heap to see the resul" << endl;
            break;
        }
        case 6:
        {
            do {
                cout << "Enter the number of heap to swith (1, 2 or 3) ";
                cin >> current_arr;
                if (current_arr < 1 or current_arr > 3)
                    cout << "Incorrect input" << endl;
            } while (current_arr < 1 or current_arr > 3);
            break;
        }
        default: break;
        }
        std::system("pause");
    }

    return 0;
}
