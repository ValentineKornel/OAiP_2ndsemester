#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void writeNumbersRecursively(string prefix, int A, int digits_left, ofstream& output_file) {
    if (digits_left == 0) {
        if(prefix >= to_string((int)pow(10, A - 1)))
        output_file << prefix << endl;
    }
    else {
        for (int i = 0; i <= A; i++) {
            writeNumbersRecursively(prefix + to_string(i), A, digits_left - 1, output_file);
        }
    }
}

int main() {
    int A;
    bool flag;
    do {
        flag = false;
        string temp;
        char temp1[10];
        cout << "Input A" << endl;
        cin >> temp;
        for (int i = 0; i < temp.length(); i++) {
            if (temp[i] == '.')
                flag = true;
        }
        if (temp[0] == '-')
            flag = true;
        if (temp > "9" or temp < "0")
            flag = true;
        if (flag == false) {
            for (int i = 0; i < temp.length(); i++) {
                temp1[i] = temp[i];
            }
            A = atoi(temp1);
        }

        else {
            cout << "Incorrect input" << endl;
        }
    } while (flag);

    ofstream output_file("numbers.txt");

    writeNumbersRecursively("", A, A, output_file);
    output_file.close();

    cout << "Numbers have been written to the file 'numbers.txt'" << endl;
    return 0;
}

/*В данном коде функция write_numbers_recursively(number, A, digits_left, output_file) записывает в 
файл все возможные числа, состоящие из цифр, не превышающих или равных A и имеющие количество цифр, 
равное A. Функция использует рекурсию: если количество оставшихся цифр равно 0, то число записывается 
в файл, в противном случае для каждой цифры от 0 до A вызывается функция write_numbers_recursively 
с числом, равным текущему числу плюс текущей цифре.*/