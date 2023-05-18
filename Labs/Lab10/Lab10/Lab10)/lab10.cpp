#include <iostream>

using namespace std;

int F(int m, int n) {
    if (m == 0 || n == 0) {
        return n + 1;
    }
    else {
        return F(m - 1, F(m, n - 1));
    }
}

int main() {
    int m, n;
    bool flag;

    do {
        flag = false;
        string temp;
        char temp1[10];
        cout << "Input m" << endl;
        cin >> temp;
        for (int i = 0; i < temp.length(); i++) {
            if (temp[i] == '.')
                flag = true;
        }
        if (temp[0] == '-')
            flag = true;
        if (flag == false) {
            for (int i = 0; i < temp.length(); i++) {
                temp1[i] = temp[i];
            }
            m = atoi(temp1);
        }

        else {
            cout << "Incorrect input" << endl;
        }
    } while (flag);


    do {
        flag = false;
        string temp;
        char temp1[10];
        cout << "Input n" << endl;
        cin >> temp;
        for (int i = 0; i < temp.length(); i++) {
            if (temp[i] == '.')
                flag = true;
        }
        if (temp[0] == '-')
            flag = true;
        if (flag == false) {
            for (int i = 0; i < temp.length(); i++) {
                temp1[i] = temp[i];
            }
            n = atoi(temp1);
        }

        else {
            cout << "Incorrect input" << endl;
        }
    } while (flag);
    int result = F(m, n);
    cout << "F(" << m << ", " << n << ") = " << result << endl;
    return 0;
}