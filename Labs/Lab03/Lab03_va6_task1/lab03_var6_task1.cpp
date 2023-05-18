#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
/*1. Скопировать из файла FILE1 в файл FILE2 строки, начиная с N до K.
Подсчитать количество согласных букв в файле FILE2.*/


int main(){

	setlocale(LC_ALL, "ru");
	int n, k, number = 0, counter = 0;
	cout << "Enter N: ";
	cin >> n;
	cout << "Enter K: ";
	cin >> k;
	string str;
	ifstream fileA("fileA.txt");
	ofstream fileB("fileB.txt");
	k--;
	n--;
	while (getline(fileA, str)){
		if (number >= n && number <= k){
			cout << str << endl;
			fileB << str << endl;
			for (int j = 0; j < str.length(); j++) {
				if (str[j] == 'q' || str[j] == 'w' || str[j] == 'r' || str[j] == 't' || str[j] == 'p' || str[j] == 's' || str[j] == 'd' || str[j] == 'f' ||
					str[j] == 'g' || str[j] == 'h' || str[j] == 'j' || str[j] == 'k' || str[j] == 'l' || str[j] == 'z' || str[j] == 'x' || str[j] == 'c' ||
					str[j] == 'v' || str[j] == 'b' || str[j] == 'n' || str[j] == 'm')
					counter++;
			}
		}
		number++;
	}
	cout << "Amount of consonant: " << counter;
}