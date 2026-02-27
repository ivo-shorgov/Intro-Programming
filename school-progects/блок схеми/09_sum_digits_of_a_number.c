#include<stdio.h>
int main()
{
    int n;
    printf("n = ");
    while (scanf("%d",&n), n<0)
    {
        printf("invalid input n again\n ");
        printf("n = ");
    }

    int sum = 0;

    while (n>0)
    {
        sum = sum + n % 10;
        n = n / 10;
    }
    printf("sum of digits = %d\n", sum);
    return 0;

}