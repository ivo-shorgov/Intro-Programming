#include <stdio.h>
#include <string.h>

int main()
{
    char string[30];
    printf("Enter string : ");
    fgets(string, 30, stdin);
    int len = strlen(string);
    for (int i = 0; string[i]; i++)
    {
        if (string[i] == '\n')
        {
            string[i] = '\0';
            len--;
            break;
        }
    }
    char symbol;
    printf("Enter a symbol you want to search : ");
    scanf("%c", &symbol);
    getchar();

    int counter = 0;
    char *ptr = string;
    while ((ptr = strchr(ptr, symbol)) != NULL)
    {
        printf("\n%s", ptr);
        counter++;
        ptr++;
    }

    printf("The symbol is found %d times in string: %s", counter, string);
    return 0;
}