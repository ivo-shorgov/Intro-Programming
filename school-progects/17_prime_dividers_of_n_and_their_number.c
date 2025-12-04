#include <stdio.h>
void main()
{
    int n;
    printf("n = ");
    scanf("%d", &n);
    while (n < 1)
    {
        printf("invalid n\n");
        printf("n = ");
    }

    int count = 0;
    int i = 2;

    while (i <= n)
    {
        if (n % i == 0)
        {
            int j = 2;
            while ( i%j != 0)
            {
                j++;
            }
            if (j == i)
            {
                printf("%d ", i);
                count++;
            }
        }
        i++;
    }
    printf("\nNumber of prime divisors: %d\n", count);

}