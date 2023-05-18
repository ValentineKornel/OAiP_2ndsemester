#include <iostream>
#include <cmath>

using namespace std;

double F(int n, float x) {
    if (n == 1) {
        return cos(x);
    }
    else {
        return cos(x*n) + F(n - 1, x);
    }
}

int main() {
    double x;
    int n;
    cout << "Input x: ";
    cin >> x;
    cout << "Input n: ";
    cin >> n;
    double result = F(n, x);
    cout << "y = " << result << endl;
    return 0;
}