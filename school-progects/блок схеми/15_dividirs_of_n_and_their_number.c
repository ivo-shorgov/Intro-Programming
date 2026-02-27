#include<stdio.h>
int main()
{
    int n;
    printf("n = ");
    scanf("%d", &n);
    while(n < 1)
    {
        printf("invalid n\n");
        printf("n = ");
        
    }
    int count = 0;
    int i = 1;

    while(i <= n)
    {
        if(n % i == 0)
        {
            printf("%d ", i);
            count++;
        }
        i++;
    }
    printf("\nNumber of divisors: %d\n", count);
}