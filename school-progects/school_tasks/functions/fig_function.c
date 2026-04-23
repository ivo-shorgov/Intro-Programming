#include <stdio.h>
void fig(int n, char c)
{
    int i, k;
    for (i = 1; i <= n; i++)
    {
        for (k = 1; k <= i; k++)
            printf("%-2c", c);
        printf("\n");
    }
}

int main()
{
    int n;
    char c;
    printf("n =");
    scanf("%d", &n);
    getchar();

    c = getchar();
    
    fig(n, c);
    return 0;
}
