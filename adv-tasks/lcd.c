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

// НОК на а и в маже да опр като проверим дали в дели а точно
// ако в дели а точно НОК = а
// ако не зеели точно тогава ивеличаваме а със първоначалната стоиност на а
// и пок правим същата проверка
// 2 3       2+2=4     4 3    4+2=6  3 6  Нок is a =6