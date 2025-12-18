#include <stdio.h>
int main()
{
    int input = 0, counter = 0;

    do
    {
        printf("Enter a number : ");
        scanf("%d", &input);
adv-tasks/the_count_of_prime_number_from_the_entered_numbers.c        if (input % 2 == 0 && input != 0)
        {
            counter++;
        }
    } while (input > 0);
    printf("The count of the prime numbers you have entered is %d", counter);
    return 0;
}