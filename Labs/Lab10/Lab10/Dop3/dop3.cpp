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


/*В данном коде функция print_permutations(numbers, index) выводит на экран все
возможные перестановки чисел в массиве numbers начиная с индекса index. Функция
использует рекурсию: если индекс равен размеру массива numbers, то текущая перестановка
выводится на экран, в противном случае для каждого i от index до размера массива
вызывается функция print_permutations с массивом numbers и индексом index + 1, после
чего происходит обмен элементов с индексами index и i.*/