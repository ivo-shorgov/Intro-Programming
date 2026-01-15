#include <stdio.h>

int main()
{
    int a, b, lcd;
    printf("Enter number a : ");
    scanf("%d", &a);
    printf("Enter number b : ");
    scanf("%d", &b);
    lcd = a;
    while (lcd % b != 0)
    {
        lcd += a;
    }

    printf("LCD of a and b is %d\n", lcd);
    return 0;
}