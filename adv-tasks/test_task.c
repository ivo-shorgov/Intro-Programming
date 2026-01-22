// Да се състави програма, която въвежда последователност от символи,
// завършваща с Enter (нов ред) и проверява дали тази последователност се състои само от цифри.

#include <stdio.h>

int main()
{
    char ch;
    int all_digits = 1;
    printf("Enter Symbols : ");
    while ((ch = getchar()) != '\n')
    {
        if (ch < '0' || ch > '9')
        {
            all_digits = 0;
        }
    }

    if ( all_digits)
    {
        printf("The string contains only digits.\n");
    }
    else
    {
        printf("The string contains non-digit characters.\n");
    }

    return 0;
}