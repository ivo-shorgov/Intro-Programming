// Да се състави програма, която проверява дали последователност от символи,
// завършваща с Enter (нов ред) може да се преобразува в цяло число
// (цялото число може да започва със знак + или знак - или да е без знак,
// след което следва последователност от цифри.

#include <stdio.h>

int main()
{
    char c;
    int all_digits = 0, first_digit = 1, isValid = 0;

    printf("Enter Symbols : ");
    while ((c = getchar()) != '\n')
    {
        if (first_digit)
        {
            if ((c == '+' || c == '-') || (c >= '0' && c <= '9'))
            {
                isValid = 1;
                first_digit = 0;
            }
        }
        else
        {
            if (c < '0' || c > '9')
            {
                all_digits = 1;
            }
            else
            {
                isValid = 0;
                break;
            }
        }
    }

    if (isValid && all_digits)
    {
        printf("The string can become a number.\n");
    }
    else
    {
        printf("The string cant becom a number.\n");
    }
    return 0;
}