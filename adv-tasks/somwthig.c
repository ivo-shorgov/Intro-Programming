#include <stdio.h>
// in inputed positive number find the position of he first 0
int main()
{
    int number;
    printf("Enter a number : ");
    scanf("%d", &number);
    while (number < 1)
    {
        printf("Invalide input\n");
        printf("Please enter a nmber again : ");
        scanf("%d", &number);
    }
    int position = 0, digit = 0, counter = 0;
    while (number > 0)
    {
        digit = number % 10;
        counter++;
        if (digit == 0)
        {
            position = counter;
        }
        number /= 10;
    }
    if (position == 0)
        printf("there is no 0 in this number");
    else
    {
        position = counter - position + 1;
        printf("the position of the first 0 is %d ", position);
    }
}
//