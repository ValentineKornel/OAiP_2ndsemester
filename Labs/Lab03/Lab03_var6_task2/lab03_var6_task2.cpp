#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
/*2. Ввести с клавиатуры строку символов, состоящую из групп цифр и нулей,
и записать ее в файл. Прочитать из файла данные и вывести на экран группы
с четным количеством символов.*/


string fileOut(string* pointer_on_StrOut){
	ofstream fileA("fileA.txt");
	fileA << *pointer_on_StrOut;
	fileA.close();
	return *pointer_on_StrOut;
}

string fileIn(string* pointer_on_StrIn){
	string StrIn;
	ifstream fileB("fileA.txt");
	while (fileB){
		fileB >> StrIn;
		if (StrIn.length() % 2 == 0)
			cout << StrIn << ' ';
		StrIn = "0";
	}
	fileB.close();
	return StrIn;
}

int main(){

	string strOut, strIn;
	string* pointer_on_StrOut = &strOut, * pointer_on_StrIn = &strIn;
	cout << "Enter the line of groups of numbers devided by 'space': ";
	getline(cin, strOut);
	fileOut(pointer_on_StrOut);
	fileIn(pointer_on_StrIn);
}