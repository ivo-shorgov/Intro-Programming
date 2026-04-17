#include <stdio.h>
#include <math.h>

void solveQuadratic(double a, double b, double c) {
    double d = b*b - 4*a*c;

    if (d > 0) {
        double x1 = (-b + sqrt(d)) / (2*a);
        double x2 = (-b - sqrt(d)) / (2*a);
        printf("Two real roots: %.2lf and %.2lf\n", x1, x2);
    }
    else if (d == 0) {
        double x = -b / (2*a);
        printf("One real root: %.2lf\n", x);
    }
    else {
        printf("No real roots\n");
    }
}

int main()
{
    double a, b, c;

    printf("Enter a: ");
    scanf("%lf", &a);
    printf("Enter b: ");
    scanf("%lf", &b);
    printf("Enter c: ");
    scanf("%lf", &c);

    solveQuadratic(a, b, c);

    return 0;
}