#include <stdio.h>

void removeDigits(char *str)
{
    int writeIndex = 0;
    for (int readIndex = 0; str[readIndex] != '\0'; ++readIndex)
    {
        if (str[readIndex] < '0' || str[readIndex] > '9')
        {
            str[writeIndex] = str[readIndex];
            writeIndex++;
        }
    }
    str[writeIndex] = '\0'; 
}

int main()
{
    char str[100];
    printf("Enter string :");
    fgets(str,100,stdin);
    printf("Преди: %s\n", str);
    removeDigits(str);
    printf("След: %s\n", str);
    return 0;
}