#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    string s;
    cout << "Enter the line: ";
    getline(cin, s); // вводим строку с пробелами

    unordered_map<char, int> charCount;

    // заполняем хеш-таблицу
    for (char c : s) {
        if (c == ' ') continue; // пропускаем пробелы
        charCount[c]++;
    }

    // выводим хеш-таблицу
    cout << "Here is hash-table:\n";
    for (auto p : charCount) {
        cout << p.first << ": " << p.second << endl;
    }

    // поиск буквы в хеш-таблице
    char c;
    cout << "Enter the letter to search: ";
    cin >> c;

    auto it = charCount.find(c);
    if (it != charCount.end()) {
        cout << "number of letter '" << c << "' in line is " << it->second << endl;
    }
    else {
        cout << "letter '" << c << "' wasn't founded." << endl;
    }

    return 0;
}
