//до 100лв - 5% стандартна отстъпка
//над 100лв - 5% стандартна отстъпка +допъл 2% за сумата над 100 лв
#include<stdio.h>
int main()
{
    float sum;
    printf("Enter the total sum for which you have bought things from a shop : ");
    scanf("%f",&sum);
    while (sum < 1)
    {
        printf("Invalide input for the sum");
        printf("Please enter the total sum again : ");
        scanf("%f",&sum);
    }
    float main_discount=5.00/100,aditional_discount=2.00/100;
    float discount;
    if(sum < 101)discount = discount5*sum;
    else 
    {
        discount = discount5*100;
        discount+=discount2*(sum-100);
    }
    printf("Your discount is %.2f lv",discount);
}