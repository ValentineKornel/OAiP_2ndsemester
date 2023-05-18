#include <iostream>
#include <vector>

using namespace std;
int m = 1;
int n;
int needed_number;
bool flag = false;
void printPermutations(vector<int> numbers, int index) {
    if (index == numbers.size()) {
        cout << m++ << ")  ";
        if (m == 27) flag = true;
        for (int i = 0; i < numbers.size(); i++) {
            cout << numbers[i] << " ";
            if (flag == true and m == 27)
                needed_number = numbers[i];
        }
        cout << endl;
    }
    else {
        for (int i = index; i < numbers.size(); i++) {
            swap(numbers[index], numbers[i]);
            printPermutations(numbers, index + 1);
            swap(numbers[index], numbers[i]);
        }
    }
}

int main() {
    cout << "Input n: ";
    cin >> n;
    vector<int> numbers;
    for (int i = 0; i < n; i++) {
        int temp_number;
        cin >> temp_number;
        numbers.push_back(temp_number);
    }

    cout << "Here are all the possible replaces: " << endl;
    printPermutations(numbers, 0);

    cout << "The " << n << "th simbol is " << needed_number;

    return 0;
}


/*� ������ ���� ������� print_permutations(numbers, index) ������� �� ����� ���
��������� ������������ ����� � ������� numbers ������� � ������� index. �������
���������� ��������: ���� ������ ����� ������� ������� numbers, �� ������� ������������
��������� �� �����, � ��������� ������ ��� ������� i �� index �� ������� �������
���������� ������� print_permutations � �������� numbers � �������� index + 1, �����
���� ���������� ����� ��������� � ��������� index � i.*/