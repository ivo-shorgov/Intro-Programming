#include <stdio.h>
int fact(int number)
{
    int P = 1;
    for (int i = 1; i <= number; i++)
    {
        P = P * i;
    }
    return P;
}
int factr(int number)
{
    if (number == 0)
        return 1;
    else
        return number * factr(number - 1);
}

int main()
{
    int number;
    do
    {
        printf("Emter a number for number! ");
        scanf("%d", &number);
    } while (number < 1);

    printf("%d! = %d\n", number, fact(number));

    printf("%d! = %d", number, factr(number));
    return 0;
}