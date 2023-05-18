#include <iostream>
#include <vector>

using namespace std;
int m = 1;
void printPermutations(vector<int> numbers, int index) {
    if (index == numbers.size()) {
        cout << m++ << ")  ";
        for (int i = 0; i < numbers.size(); i++) {
            cout << numbers[i] << " ";
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
    vector<int> numbers = { 1, 2, 3, 4, 5};

    cout << "Here are all the possible replaces: " << endl;
    printPermutations(numbers, 0);

    return 0;
}

