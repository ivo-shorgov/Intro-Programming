#include<stdio.h>
void main()
{
    int n,i,max;
    printf("n = ");
    while (scanf("%d",&n), n<1)
    {
        printf("invalid input n again\n");
        printf("n = ");
    }

    i=1;
    max=0;

    while (i<=n)
    {
        int num;
        printf("num = ");
        scanf("%d",&num);
        if (num>max)
            max=num;
        i=i+1;
    }

    printf("max=%d\n", max);
}