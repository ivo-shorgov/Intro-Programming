#include<stdio.h>
void main()
{
    int n;

    printf("n= ");
    while(scanf("%d",&n)<1)
    {
        printf("invalid input n again\n ");
        printf("n= ");
    }

    int i=1;
    int max=0;

    while(i<=n)
    {
        int a;

        printf("a= ");
        scanf("%d",&a);

        if(a%3==0)
            {
            if(a>max)
                {
                    max=a;
                }
            }
    i=i+1;  

    }

    printf("max=%d\n", max);

}