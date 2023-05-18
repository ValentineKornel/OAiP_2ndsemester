#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
/*2. Ввести с клавиатуры строку символов, состоящую из групп
цифр и нулей, и записать ее в файл. Прочитать из файла данные
и вывести самую короткую группу. */

string fileOut(string* pointer_on_StrOut){
	ofstream file1("fileA.txt");
	file1 << *pointer_on_StrOut;
	file1.close();
	return *pointer_on_StrOut;
}

string fileIn(string* plinter_on_StrIn){
	string StrIn, min = "0000000";
	ifstream file2("fileA.txt");
	while (file2){
		file2 >> StrIn;
		if (StrIn.length() < min.length())
			min = StrIn;
	}
	cout << "The shourtest group: " << min << endl;
	file2.close();
	return min;
}

int main(){
	string strOut, strIn;
	string* pointer_on_StrOut = &strOut, * pointer_on_StrIn = &strIn;
	cout << "Enter the line of groups of numbers devided by 'space': ";
	getline(cin, strOut);
	fileOut(pointer_on_StrOut);
	fileIn(pointer_on_StrIn);
}