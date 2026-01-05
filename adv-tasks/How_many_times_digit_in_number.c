// in inputed positive number and digit find the numberof times the digit is in the number
#include <stdio.h>
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
    int digit;
    printf("Enter a digit : ");
    scanf("%d", &digit);
    while (digit < 1)
    {
        printf("Invalide input\n");
        printf("Please enter a digit again : ");
        scanf("%d", &digit);
    }
    int counter, x;
    while (number > 0)
    {
        x = number % 10;
        if (x == digit)
            counter++;
        number /= 10;
    }
    printf("The digit is in the number %d times", counter)
}