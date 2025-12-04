#include <stdio.h>
void main()
{
    int n;
    printf("n = ");
    scanf("%d", &n);
    while (n < 1)
    {
        printf("invalid n\n");
        printf("n = ");
        
    }

    int i = 2;

    while (n % i != 0)
    {
        i++;
    }

    if (i == n)
    {
        printf("n is prime\n");
    }
    else
    {
        printf("n is not prime\n");
    }
}