#include <stdio.h>
int main()
{
    int input;
    printf("Enter a number : ");
    scanf("%d", &input);
    while (input < 0)
    {
        printf("invalid input\n ");
        printf(" Enter anumber again : ");
        scanf("%d", &input);
    }
    int number = input;
    unsigned long long binaryReverse = 1;

    while (number > 0)
    {
        binaryReverse *= 10;
        binaryReverse += number % 2;
        number /= 2;
    }
    unsigned long long binary = 0;
    while (binaryReverse > 1)
    {
        binary *= 10;
        binary += binaryReverse % 10;
        binaryReverse /= 10;
    }
    printf(" The number %d in binery is %llu ", input, binary);
}