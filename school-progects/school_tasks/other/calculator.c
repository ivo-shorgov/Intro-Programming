#include <stdio.h>

int main()
{
    float number, sum;
    char math_symbol;
    scanf("%c", &math_symbol);
    printf("Enter the first number : \n");
    scanf("%d", &number);
    int i = 0;
    if (i % 2 == 0)
    {

        printf("Enter a math symbol : \n");
        scanf("&c", &math_symbol);
    }
    else
    {
        printf("Enter a ongoing number : \n");
        scanf("%f", &number);
    }
    switch (math_symbol)
    {
    case '+':
        sum = number + number;
        break;
    case '-':
        sum = number - number;
        break;
    case '*':
        sum = number * number;
        break;
    case '/':
        sum = number / number;
        break;
    default:
        sum = sum;
        break;
    }
    printf("%.2f", sum);
    return 0;
}