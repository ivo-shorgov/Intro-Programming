#include <stdio.h>
int main()
{
    int input = 0, counter = 0;

    do
    {
        printf("Enter a number : ");
        scanf("%d", &input);
        if (input % 2 == 0 && input != 0)
        {
            counter++;
        }
    } while (input > 0);
    printf("The count of the prime numbers you have entered is %d", counter);
    return 0;
}