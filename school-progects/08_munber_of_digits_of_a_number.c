#include<stdio.h>
int main()
{
    int n;

    printf("n = ");
   while(scanf("%d",&n)<1)
        {
            printf("invalid input n again\n ");
            printf("n = ");
        }

    while(n<1)
        {
            printf("invalid input n again\n ");
            scanf("%d",&n);
        }  
    
    int i=0;

    while(n>0)
        {
            n=n/10;
            i=i+1;
        }
        
    printf("number of digits = %d\n", i);
    return 0;
}