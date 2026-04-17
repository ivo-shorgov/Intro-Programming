#include <stdio.h>

float to_the_power(float a, int n)
{
    if (n == 0)
        return 1;
    else if (n < 0)
        return (a * to_the_power(a, n + 1));
    else if (n > 0)
        return a * to_the_power(a, n - 1); 
}

int main()
{
    float base;
    int power;

    printf("Enter base (a): ");
    scanf("%f", &base);

    printf("Enter exponent (n): ");
    scanf("%d", &power);

    if (power< 0)
        printf("%.2f^%d = 1/%.2f\n", base, power, to_the_power(base, power));
    else if (power > 0)
        return base * to_the_power(base,power - 1);

    return 0;
}
