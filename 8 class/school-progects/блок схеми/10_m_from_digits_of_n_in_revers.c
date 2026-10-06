#include<stdio.h>
void main()
{
    int n;
    printf("n = ");
    while(scanf("%d",&n)<1)
    {
        printf("invalid input. Please enter a non-negative integer for n.\n");
        printf("n = ");
    }

    int m = 0;
    while (n > 0)
    {
        int digit = n % 10;
        m = m * 10 + digit;
        n /= 10;
    }
    printf("m = %d\n", m);
}