#include <stdio.h>
int main()
{
    //inputs the hight of the Christmas tree
    int n;
    printf("Enter the height of the Christmas tree: ");
    scanf("%d", &n);

    //validates the input
    while (n < 1)
    {
        printf("invalid integer for n: \n ");
        printf("n = ");
        scanf("%d", &n);
    }

    //defines the height of the base and crown of the Christmas tree
    int base_height = 1;
    int crown_height = n - base_height;

    //prints the upper part of the Christmas tree
    for (int i = 0; i < crown_height; i++)
    {
        for (int k = 0; k < crown_height - i - 1; k++)
        {
            printf(" ");
        }
        for (int j = 0; j < i + 1; j++)
        {
            printf("* ");
        }
        printf("\n");
    }

    //prints the base of the Christmas tree
    for (int m = 0; m < base_height ; m++)
    {
        for (int l = 0; l < crown_height - 2; l++)
        {
            printf(" ");
        }
        printf("| |");
        printf("\n");
    }

    return 0;
}