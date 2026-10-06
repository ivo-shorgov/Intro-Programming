#include <stdio.h>

void printBinary(unsigned int n)
{
    if (n > 1)
        printBinary(n / 2);
    printf("%u", n % 2);
}
int Binary(int n)
{
    int i, number = n;
    for (i = 0; i >= 0; i++)
    {
        if (n == 0)
            break;
        else
            n = n / 2;
    }
    int binary_arr[i];
    for (int k = 0; k < i; k++)
    {
        binary_arr[k] = number % 2;
        number = number / 2;
    }
    int number_revers = 0;
    for (int k = i - 1; k >= 0; k--)
    {
        number_revers = number_revers * 10 + binary_arr[k];
    }
    return number_revers;
}

int main()
{
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    while (number < 0)
    {
        printf("invalid input\n");
        printf("Enter a number again: ");
        scanf("%d", &number);
    }

    printf("The number %d in binary is  ", number);
    if (number == 0)
    {
        printf("0");
    }
    else
    {
        printf("%d", Binary(number));
    }
    printf("\n");

    return 0;
}