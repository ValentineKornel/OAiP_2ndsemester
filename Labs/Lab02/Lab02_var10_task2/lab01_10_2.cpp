#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;


void main()
{
    char string[100];
    int amount_of_strings = 1;
    bool flag = false;

    FILE* file_to_read;
    errno_t err1;
    FILE* file_to_write;
    errno_t err2;


    err1 = fopen_s(&file_to_read, "test.txt", "r");
    while (!feof(file_to_read))    //feof defines the end of the file(EOF)
    {
        if (fgetc(file_to_read) == '\n')  //fgets  gets next character and move pointer plus one
            amount_of_strings++;
    }
    fseek(file_to_read, 0, SEEK_SET);

    err2 = fopen_s(&file_to_write, "test1.txt.", "w");

    for (int i = 0; i < amount_of_strings; i++) {
        if (NULL != fgets(string, 100, file_to_read))
        {
            int j = 0;
            flag = false;
            while (string[j] != EOF && string[j] != '\0') {
                if (string[j] >= '0' && string[j] <= '9')
                    flag = true;
                j++;
            }
            if (flag == true)
                continue;
            printf("%s", string);
            fputs(string, file_to_write);
        }
    }


    fclose(file_to_write);
    fclose(file_to_read);
}