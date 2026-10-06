#include <stdio.h>
void main()
{
    int n;
    printf("n = ");
    scanf("%d", &n);
    while (n < 1)
    {
        printf("invalid input n again\n");
        printf("n = ");
    }

    int i = 1;
    int sum = 0;

    while (i <= n)
    {
        int grade;
        printf("grade = ");
        scanf("%d", &grade);
        while (grade < 2 || grade > 6)
        {
            printf("invalid input grade again\n");
            printf("grade = ");
            return;
        }
        sum = sum + grade;
        i = i + 1;
    }

    float avg;
    avg = (float)sum / n;

    printf("avg=%d\n", avg);
}