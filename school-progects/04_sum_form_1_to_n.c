#include<stdio.h>
void main() 
{
    int n;
    printf("n = ");
    while (scanf("%d",&n), n < 1)
    {
        printf("invalid input n again\n");
        printf("n = ");
    }

    int sum = 0;

    for (int i = 1; i <= n; i++) 
    {
        sum += i;
    }

    printf("sum = %d\n", sum);
}