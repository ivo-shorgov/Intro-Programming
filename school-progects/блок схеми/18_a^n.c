#include <stdio.h>
int main()
{

    int n;
    printf("n = ");
    scanf("%d", &n);
    int m;

    if (n > 0)
    {
        m = n;
    }
    else
    {
        m = -n;
    }

    int a;
    printf("a = ");
    scanf("%d", &a);
    while (a <= 0)
    {
        printf("invalid a\n");
        printf("a = ");
        scanf("%d", &a);
    }
   int p =1;
   int i =1;
    while (i <= m)
    {
         p = p * a;
         i++;
    }
    if(n 0)
    {
       p = 1 / p;
    }
    printf("p = %d\n", p);
}