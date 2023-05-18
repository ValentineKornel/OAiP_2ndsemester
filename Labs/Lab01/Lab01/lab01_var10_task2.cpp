#include "lab01_var10_task2.h"


char str1[30000]; 


int points[15000]; //Array of position numbers from which words begin

int number; // amount of word entered

int sort(char str[], int point[]) {
    int j;
    int i, temp;
    i = j = 0;
    for (j = number - 1; j > 0; j--)
        for (i = 0; i < j; i++)
            if (strcmp(&str[point[i]], &str[point[i + 1]]) > 0)
            {
                temp = point[i];
                point[i] = point[i + 1];    // bubble sort
                point[i + 1] = temp;
            }
    return 0;
}
int Work(char str[]) { 
    int flag = 1;
    int i = 0;
    for (number = 0, flag = 1, i = 0; str1[i]; i++)
    {
        // Replace all spaces with line end
        if (str[i] == ' ')
        {
            str[i] = 0;
            flag = 1;
        }
        // Positions of the first after the space characters are written in an array
        else if (flag)
        {
            points[number++] = i;
            flag = 0;
        }
    }
    return 0;
}

int FindTheLowestLetter(string s,...)
{
    for (int k = 0; k < s.length(); k++) {
        str1[k] = s[k];
    }
    int i;
    
    Work(str1);
    sort(str1, points);
    
    for (i = 0; i < number; i++)
        printf("%s ", &str1[points[i]]);
    return 0;
}

void doVariant10Task2() {

    FindTheLowestLetter("you are so pretty");

}
