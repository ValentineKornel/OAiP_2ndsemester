#include <iostream>
#include <algorithm> // для использования std::sort

int main() {
    const int size = 10;
    int arr[size];

    // Ввод элементов массива с клавиатуры
    std::cout << "Input " << size << " array elements:\n";
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    // Сортировка первых 4 элементов по возрастанию
    std::sort(arr, arr + 4);

    // Сортировка последних 4 элементов по убыванию
    std::sort(arr + 6, arr + 10, std::greater<int>());

    // Вывод отсортированного массива на экран
    std::cout << "Sorted array:\n";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;

    return 0;
}
