// Да се състави програма, която проверява дали последователност от символи,
// завършваща с Enter (нов ред) може да се преобразува в цяло число
// (цялото число може да започва със знак + или знак - или да е без знак, след което следва последователност от цифри.
#include <stdio.h>

int main()
{
    char ch;
    int isValid = 1;
    int hasDigits = 0;
    int isFirstChar = 1;

    printf("Enter a sequence of characters (ending with Enter): ");

    while ((ch = getchar()) != '\n')
    {
        if (isFirstChar)
        {
            // First character can be a sign or a digit
            if ((ch == '+' || ch == '-') || (ch >= '0' && ch <= '9'))
            {
                if (ch >= '0' && ch <= '9')
                    hasDigits = 1;
                isFirstChar = 0;
            }
            else
            {
                isValid = 0;
                break;
            }
        }
        else
        {
            // Subsequent characters must be digits
            if (ch >= '0' && ch <= '9')
            {
                hasDigits = 1;
            }
            else
            {
                isValid = 0;
                break;
            }
        }
    }

    // Valid integer must have at least one digit
    if (isValid && hasDigits)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }

    return 0;
}