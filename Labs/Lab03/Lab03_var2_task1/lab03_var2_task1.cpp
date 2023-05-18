#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
/*1. Скопировать в файл FILE2 только те строки из FILE1,  которые
начинаются с буквы «А». Подсчитать количество слов в FILE2.*/

int main(){

	int k, num = 0, counter = 0;
	string str;
	ifstream fileA("fileA.txt");
	ofstream fileB("fileB.txt");
	while (getline(fileA, str)){
		if (str[0] == 'a' || str[0] == 'A'){
			cout << str << endl;
			fileB << str << '\n';
			counter++;
			for (int i = 0; i < str.length(); i++){
				if (str[i] == ' '){
					counter++;
				}
			}
		}
	}
	cout << "Amount of words: " << counter;
}