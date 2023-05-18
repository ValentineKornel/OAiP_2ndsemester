#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
/* 2. Ввести с клавиатуры строку символов, состоящую из слов,
разделенных пробелами, и записать ее в файл. Прочитать из файла данные
и вывести на экран порядковый номер слова минимальной длины. Посчитать
количество символов в слове. */


string fileOut(string* pointer_on_StrOut){
	ofstream fileA("fileA.txt");
	fileA << *pointer_on_StrOut;
	fileA.close();
	return *pointer_on_StrOut;
}

string fileIn(string* pointer_on_StrIn){
	string StrIn, min = "0000000";
	int counter = 1, SequenceNum, amount_of_letters;
	ifstream fileB("fileA.txt");
	while (fileB){
		fileB >> StrIn;
		if (StrIn.length() < min.length()){
			amount_of_letters = StrIn.length();
			min = StrIn;
			SequenceNum = counter;
		}
		counter++;
	}
	cout << "The number of the shortest word: " << SequenceNum << endl;
	cout << "Amount of letters: " << amount_of_letters << endl;
	fileB.close();
	return StrIn;
}

int main(){

	string strOut, strIn;
	string* pointer_on_StrOut = &strOut, * pointer_on_StrIn = &strIn;
	cout << "Enter the line of words divided by 'space': ";
	getline(cin, strOut);
	fileOut(pointer_on_StrOut);
	fileIn(pointer_on_StrIn);
}