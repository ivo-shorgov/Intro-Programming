#include <stdio.h>

int main()
{
    int weight = 0, grades = 0;
    double grade = 0, final = 0, avg = 0, sum = 0;

    for (int component = 1; component <= 3; component++)
    {
        printf("Enter the number of the grades of component %d : ", component);
        scanf("%d", &grades);

        while (grades < 1)
        {
            printf("Invalid input\n");
            printf("Enter the number of the grades of the %d component : ",component);
            scanf("%d", &grades);
        }

        for (int i = 0; i < grades; i++)
        {
            printf("Enter a grade : ");
            scanf("%lf", &grade);
            while (grade < 2 || grade > 6)
            {
                printf("Invalid input\n");
                printf("Enter a grade again : ");
                scanf("%lf", &grade);
            }
            sum += grade;
        }

        avg = sum / grades;

        if (component == 1)
        {
            weight = 20;
        }
        else if (component == 2)
        {
            weight = 30;
        }
        else
        {
            weight = 50;
        }

        final += weight / 100.0 * avg;
        sum = 0;
        avg = 0;
    }
    printf("Your final grade is : %.2lf", final);
    return 0;
}