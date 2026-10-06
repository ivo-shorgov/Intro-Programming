#include <stdio.h>

int isValidIdentifier(const char *str)
{
    if (str[0] == '\0')
        return 0;

    // Първият символ НЕ може да е цифра
    if (!((str[0] >= 'a' && str[0] <= 'z') ||
          (str[0] >= 'A' && str[0] <= 'Z') ||
          str[0] == '_'))
    {
        return 0;
    }

    // Проверка на останалите символи
    for (int i = 1; str[i] != '\0'; ++i)
    {
        if (!((str[i] >= 'a' && str[i] <= 'z') ||
              (str[i] >= 'A' && str[i] <= 'Z') ||
              (str[i] >= '0' && str[i] <= '9') ||
              str[i] == '_'))
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    char str[50];
    printf("Въведете идентификатор: ");
    fgets(str,50,stdin);
    if (isValidIdentifier(str))
    {
        printf("Валиден идентификатор.\n");
    }
    else
    {
        printf("НЕВАЛИДЕН идентификатор.\n");
    }
    return 0;
}