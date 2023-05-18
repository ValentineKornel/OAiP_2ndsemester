#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;


void main()
{
    char string[100];
    int amount_of_strings = 1;
    int number;
    bool flag = false;

    FILE* file_to_read;
    errno_t err1;
    FILE* file_to_write;
    errno_t err2;

    cout << "Enter the number";
    cin >> number;

    err1 = fopen_s(&file_to_read, "fileA.txt", "r");
    while (!feof(file_to_read))    //feof defines the end of the file(EOF)
    {
        if (fgetc(file_to_read) == '\n')  //fgets  gets next character and move pointer plus one
            amount_of_strings++;
    }
    fseek(file_to_read, 0, SEEK_SET);

    err2 = fopen_s(&file_to_write, "fileB.txt.", "w");

    for (int i = 0; i < amount_of_strings; i++) {
        if (NULL != fgets(string, 100, file_to_read)){
            flag = false;
            if (strlen(string) < number)
                flag = true;
            
        }
            if (flag == true)
                continue;
            printf("%s", string);
            fputs(string, file_to_write);
        
    }


    fclose(file_to_write);
    fclose(file_to_read);
}