#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
/* 1. Скопировать из файла FILE1 в файл FILE2 все строки, начинающиеся
на букву «С», расположенные между строками с номерами N1 и N2. Определить
количество слов в первой строке файла FILE2.1-3*/
//

int main(){

	int n1, n2, number = 0, counter = 0;
	string str;
	cout << "Enter N1: ";
	cin >> n1;
	cout << "Enter N2: ";
	cin >> n2;
	ifstream file1("fileA.txt");
	ofstream file2("fileB.txt");
	n1--;
	n2--;
	bool flag = false;
	while (getline(file1, str)){
		if (number >= n1 && number <= n2){
			if (str[0] == 'C' || str[0] == 'c'){
				file2 << str << endl;
				cout << str << endl;
				if (flag == false){
					flag = true;
					for (int i = 0; i < str.length(); i++) {
						if (str[i] == ' ') {
							counter++;
						}
					}
				}
			}
		}
		number++;
	}
	cout << "Amount of words in the first line of the fileB: " << counter + 1;
}