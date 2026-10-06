#include<stdio.h>
int main()
{
    int n;
    printf("n = ");
    while (scanf("%d", &n), n<1)
    {
        printf("Invalid input. Please enter an integer for n = ");
        printf("n = ");
    }

    int a;
    printf("a = ");
    while (scanf("%d", &a), a<0 || a>9)
    {
        printf("Invalid input. Please enter an integer for a = ");
        printf("a = ");
    }

    while(n > 0)
    {
        if (a == n % 10)
        {
            printf("Yes, %d is in %d\n", a, n);
            return 0;
        }
        n /= 10;
    }

    printf("No, %d is not in the original number.\n", a);
    return 0;
}