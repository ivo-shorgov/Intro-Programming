#include<stdio.h>
int main()
{
    int n;
    printf("n = ");
    while (scanf("%d",&n), n<1)
    {
        printf("invalid input n again\n ");
        
    }
    int i=1;
    int sum=0; 
    while (i<=n)
    {
        int a;
        printf("a= ");
        scanf("%d",&a);
        int k = 2;
        
        while(a%k!=0)
        {
            k++;

        }
        
        if( k == a)
         {
             sum = sum + a; 
         }
        i=i+1;
        
    }
    printf("sum=%d\n", sum);
    return 0;
} 