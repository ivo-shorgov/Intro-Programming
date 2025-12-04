#include<stdio.h>
int main()
{
    int n;
    printf("n = ");
    int j = scanf("%d",&n);
    while(j<1)
    {
        printf("invalid input. Please enter an integer for n: ");
        printf("n = ");
    }

    int a;
    printf("a = ");
    scanf("%d",&a);

    int i = 0;

    while (n > 0)
    {
        int digit = n % 10;
        if (digit == a)
        {
            i++;
        }
        n /= 10;
    }
    printf("i = %d\n", i );
    return 0;
}