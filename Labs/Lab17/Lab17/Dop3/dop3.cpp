#include <iostream>
#include <algorithm> // ��� ������������� std::sort

int main() {
    const int size = 10;
    int arr[size];

    // ���� ��������� ������� � ����������
    std::cout << "Input " << size << " array elements:\n";
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    // ���������� ������ 4 ��������� �� �����������
    std::sort(arr, arr + 4);

    // ���������� ��������� 4 ��������� �� ��������
    std::sort(arr + 6, arr + 10, std::greater<int>());

    // ����� ���������������� ������� �� �����
    std::cout << "Sorted array:\n";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;

    return 0;
}
