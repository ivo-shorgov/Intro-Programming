#include <stdio.h>

int main()
{
    char ch;
    int all_digits = 0;
    printf("Enter Symbols : ");
    while ((ch = getchar()) != '\n')
    {
        if (ch < '0' || ch > '9')
        {
            all_digits +=1;
        }
    }

    if ( all_digits !=0)
    {
        printf("The string contains non-digit characters.\n");
    }
    else
    {
        printf("The string contains only digits.\n");
    }

    return 0;
}