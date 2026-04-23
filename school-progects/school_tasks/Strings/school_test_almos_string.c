// 3. Да се състави програма, която преобразува последователност от символи,
// завършваща с Enter (нов ред) в цяло число, ако това е възможно.

#include <stdio.h>

int main()
{
    char ch;
    int number = 0;
    int sign = 1;
    int isValid = 1;
    int hasDigits = 0;
    int isFirstChar = 1;

    printf("Enter a sequence of characters: ");

    while ((ch = getchar()) != '\n')
    {
        if (isFirstChar)
        {
            // First character can be a sign or a digit
            if (ch == '+')
            {
                sign = 1;
                isFirstChar = 0;
            }
            else if (ch == '-')
            {
                sign = -1;
                isFirstChar = 0;
            }
            else if (ch >= '0' && ch <= '9')
            {
                number = number * 10 + (ch - '0');
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
                number = number * 10 + (ch - '0');
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
        number = number * sign;
        printf("Converted integer: %d\n", number);
    }
    else
    {
        printf("Cannot convert to integer.\n");
    }

    return 0;
}