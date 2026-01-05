#include<stdio.h>
//input numbers , stop if input munber is 0, solve avr of the numbers
int main()
{
    int counter=0;
    double sum=0, number;
    do
    {
        printf("Enter a number : " );
        scanf("%lf",&number);
        while (number < 0)
        {
            printf("invalid input\n ");
            printf(" Enter anumber again : ");
            scanf("%lf",&number);
        }
        sum = sum + number;
        counter++;
       
    }
    while (number != 0);
    counter = counter - 1;
    double avr = sum/counter;
    printf("The average of the entered numbers is %lf",avr);
}