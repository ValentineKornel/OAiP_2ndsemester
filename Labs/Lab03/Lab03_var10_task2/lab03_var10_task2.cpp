#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
/*Ввести с клавиатуры строку символов, состоящую из слов, разделенных пробелами, и записать ее в
файл. Прочитать из файла данные и вывести все слова, которые содержат букву «р»*/


void fileOut(string input_str) {
    ofstream file_to_write("fileA.txt");
    file_to_write << input_str;
    file_to_write.close();
}

void fileIn() {
    FILE* F1;
    errno_t err;

    err = fopen_s(&F1, "fileA.txt", "r");
    char c = 'p';
    char S[255];
    fgets(S, 255, F1);
    istringstream ist(S);
    string tmp;
    int i;
    while (ist >> tmp) {
        i = 0;
        while (tmp[i]) {
            if (tmp[i] == c) {
                cout << tmp << endl;
                break;
            }
            i++;
        }

    }

}

void main()
{
    

    int counter_of_words = 1;
    int position_of_word = 0;
    string input_str;
    getline(cin, input_str);
    
    int line_length = input_str.length();


    fileOut(input_str);

    fileIn();
    

}
