#include<stdio.h>
void main()
{
    int n;
    printf("n = ");
    while (scanf("%d",&n), n<0)
    {
        printf("invalid input n again\n ");
        printf("n = ");
    }

    int max = 0;

    while (n > 0)
    {
        int digit = n % 10;
        if (digit >max)
        {
            max = digit;
        }
        n /= 10;
    }

    printf("max = %d\n", max);
}