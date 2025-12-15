#include <stdio.h>

void printBorder(int len);

int main()
{
    // inputs the weight on Earth
    int earth_weight;
    printf("Enter your weight on Earth (in kg): ");
    scanf("%d", &earth_weight);

    // validates the input
    while (earth_weight < 1)
    {
        printf("Invalid weight. Please enter a positive integer for your weight on Earth: ");
        scanf("%d", &earth_weight);
    }

    // calculates the weight on the Moon
    int moon_weight = (earth_weight / 9.81) * 1.622;

    // how many digits has the moon_weight

    int br = 0;
    int moon_weight_copy = moon_weight;
    while (moon_weight_copy != 0)
    {
        br++;
        moon_weight_copy = moon_weight_copy / 10;
    }

    // makes the  upper frame

    printf("+-");

    for (int i = 0; i < br; i++)
    {
        printf("-");
    }

    printf("-+\n");

    // middle frame with moon_weight
    printf("| %d |\n", moon_weight);

    // bottom frame
    printf("+-");

    for (int i = 0; i < br; i++)
    {
        printf("-");
    }

    printf("-+\n");
    return 0;
}