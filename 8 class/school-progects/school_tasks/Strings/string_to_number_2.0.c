#include <stdio.h>

int stringToInt(const char *str, int *result)
{
    if (str[0] == '\0')
        return 0;

    int i = 0;
    int isNegative = 0;

    // Проверка за знак
    if (str[0] == '-')
    {
        isNegative = 1;
        i++;
    }
    else if (str[0] == '+')
    {
        i++;
    }

    if (str[i] == '\0')
        return 0; // Низ само от '+' или '-'

    long long currentResult = 0; // Защита от препълване (overflow)
    while (str[i] != '\0')
    {
        if (str[i] < '0' || str[i] > '9')
        {
            return 0; // Намерен е невалиден символ
        }
        currentResult = currentResult * 10 + (str[i] - '0');
        i++;
    }
    if (isNegative == 1)
    {
        *result = -currentResult;
    }
    else
    {
        *result = currentResult;
    }
    return 1;
}

int main()
{
    char str[50];
    printf("Въведете низ: ");
    fgets(str, 49, stdin);

    int number;
    if (stringToInt(str, &number))
    {
        printf("Успешно преобразуване! Числото е: %d\n", number);
    }
    else
    {
        printf("Низът не може да бъде преобразуван в цяло число.\n");
    }
    return 0;
}