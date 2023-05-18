#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    string s;
    cout << "Enter the line: ";
    getline(cin, s); // ������ ������ � ���������

    unordered_map<char, int> charCount;

    // ��������� ���-�������
    for (char c : s) {
        if (c == ' ') continue; // ���������� �������
        charCount[c]++;
    }

    // ������� ���-�������
    cout << "Here is hash-table:\n";
    for (auto p : charCount) {
        cout << p.first << ": " << p.second << endl;
    }

    // ����� ����� � ���-�������
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
