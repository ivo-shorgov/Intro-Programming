#include <stdio.h>

int main()
{
    int years;
    double money, intrest;
    printf("Enter a sum of money : ");
    scanf("%lf", &money);
    while (money < 0)
    {
        printf("invalid input\n ");
        printf(" Enter anumber again : ");
        scanf("%lf", &money);
    }
    printf("Enter the years : ");
    scanf("%d", &years);
    while (years < 0)
    {
        printf("invalid input\n ");
        printf(" Enter anumber again : ");
        scanf("%d", &years);
    }
    printf("Enter the intrest : ");
    scanf("%lf", &intrest);
    while (intrest < 0)
    {
        printf("invalid input\n ");
        printf(" Enter anumber again : ");
        scanf("%lf", &intrest);
    }

    double finalMoney = money;
    for (int i = 0; i < years; i++)
    {
        finalMoney += (5 * finalMoney) / 100;
    }
    
    printf("Your money after %d years is %.2lf lv", years, finalMoney);
    return 0;
}