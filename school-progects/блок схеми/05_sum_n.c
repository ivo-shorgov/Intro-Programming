#include <stdio.h>
void main()
{
    int n, i, sum;
    printf("n = ");
    while (scanf("%d", &n), n < 1)
    {
        printf("invalid input n again\n");
        printf("n = ");
    }

    i = 1;
    sum = 0;

    while (i <= n)
    {
        int num;
        printf("num = ");
        scanf("%d", &num);
        sum = sum + num;
        i = i + 1;
    }

    printf("sum=%d\n", sum);
}