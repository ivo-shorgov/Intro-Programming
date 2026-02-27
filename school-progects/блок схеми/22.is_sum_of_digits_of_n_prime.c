#include<stdio.h>
int main()
{
    int n,sum=0,i=1;
    printf("Enter a value for n: ");
    scanf("%d",&n);
    while(n<1)
    {
        printf("Please enter a positive integer: ");
        scanf("%d",&n);
    }
    while(i<=n)
    {
    int x=n%10;
    sum=sum+x;
    i++;
    n/=10;
    }
    int k=2;
    while (sum%k!=0)
    {
        k++;
    }
    if(k==sum)
    {
        printf("The sum of the digits is a prime number.\n");
    }
    else
    {
        printf("The sum of the digits is not a prime number.\n");
    }
    return 0;
}