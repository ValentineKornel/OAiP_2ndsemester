#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <fstream>
using namespace std;
/*. Скопировать из файла FILE1 в файл FILE2 все строки, в которых нет слов, совпадающих с первым
словом. Определить количество согласных букв в первой строке файла FILE2.*/


void main()
{
    int counter_of_consonant = 0;
    char temporary_str[100];
    char str[100];
    int amount_of_strings = 1;
    bool first_line = false;


    bool flag = false;

    FILE* file_to_read;
    errno_t err1;
    FILE* file_to_write;
    errno_t err2;

    string first_word;
    ifstream file_to_read1("fileA.txt");
    file_to_read1 >> first_word;
    file_to_read1.close();


    err1 = fopen_s(&file_to_read, "fileA.txt", "r");
    while (!feof(file_to_read))    //feof defines the end of the file(EOF)
    {
        if (fgetc(file_to_read) == '\n')  //fgets  gets next character and move pointer plus one
            amount_of_strings++;
    }
    fseek(file_to_read, 0, SEEK_SET);

    err2 = fopen_s(&file_to_write, "fileB.txt.", "w");

    for (int i = 0; i < amount_of_strings; i++) {
        if (NULL != fgets(temporary_str, 100, file_to_read)) {
            for (int i = 0; i < 100; i++)
                str[i] = temporary_str[i];
            int j = 0;
            while (temporary_str[j] != '\n') {                  //the string is devided each word apart
                if (temporary_str[j] == ' ') {
                    temporary_str[j] = '\n';
                }
                j++;
            }


            int m = 0;      //counter for character of str
            int g = 0;      //counter for first word
            int count_flag = 0;
            flag = false;
            while (temporary_str[m] != 0) {
                if (temporary_str[m] == '\n') {
                    g = 0;
                    if (count_flag == first_word.length())
                        flag = true;
                    count_flag = 0;
                }
                else if (temporary_str[m] == first_word[g]) {
                    count_flag++;
                    g++;
                }
                m++;
            }
            if (flag == false) {              //if needed to write in the first string as well, then just need to add condition (or i == 0)
                fputs(str, file_to_write);
                cout << str;
            }
            if (flag == false and first_line == false) {
                first_line = true;
                string consonant_list = "bcdfghjklmnpqrstvwxyz";

                for (int k = 0; k < 100; k++) {
                    for (int y = 0; y < 21; y++) {
                        if (tolower(str[k]) == consonant_list[y])
                            counter_of_consonant++;

                    }
                }
            }
        }
    }
    cout << endl << "Amount of consonant letters in the first line = " << counter_of_consonant;

    fclose(file_to_write);
    fclose(file_to_read);

}