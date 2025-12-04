#include <stdio.h>
void main()
{
    int n ;
    printf("n = ");
    scanf("%d", &n);
    while ( n < 1 )
    {
        printf("invalid input n again\n");
        printf("n = ");
    }

    int i = 1;
    int sum = 0;

    while (i <= n)
    {
        int num;
        printf("num = ");
        scanf("%d", &num);
        while( num < 2 || num > 6 ) {
            printf("invalid input num again\n");
            printf("num = ");
            return;
        }
        sum = sum + num;
        i = i + 1;
    }

    int avg = sum / n;

    printf("avg=%d\n", avg);
}