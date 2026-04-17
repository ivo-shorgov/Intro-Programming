#include <stdio.h>
#define max_u 30
#define max_p 20
int main()
{
    int students, classes;

    do
    {
        printf("students=? (<=%d): ", max_u);
        scanf("%d", &students);
    } while (students < 1 || students > max_u);
    do
    {
        printf("classses=? (<=%d):", max_p);
        scanf("%d", &classes);
    } while (classes < 1 || classes > max_p);

    float marks[students][classes];

    int i, k;
    for (i = 0; i < students; i++)
    {
        for (k = 0; k < classes; k++)
        {
            do
            {
                printf("mark %d for student %d=", k + 1, i + 1);
                scanf("%f", &marks[i][k]);
            } while (marks[i][k] < 2 || marks[i][k] > 6);
        }
    }

    float avr_student[students];
    float avr_for_students;

    for (int row = 0; row < students; row++)
    {
        float sum_1 = 0;
        for (int col = 0; col < classes; col++)
        {
            sum_1 += marks[row][col];
        }
        avr_student[row] = sum_1 / classes;
        avr_for_students += sum_1;
    }
    avr_for_students /= (students * classes);

    float avr_class[classes];
    for (int col = 0; col < classes; col++)
    {
        float sum_2 = 0;
        for (int row = 0; row < students; row++)
        {
            sum_2 += marks[row][col];
        }
        avr_class[col] = sum_2 / students;
    }

    for (int row = 0; row < students; row++)
    {
        printf("|");
        for (int col = 0; col < classes; col++)
        {
            printf(" %.2f |", marks[row][col]);
        }
        printf(" %.2f |\n", avr_student[row]);
        printf("-");
        for(int i = 0;i<students;i++)
        printf("-------\n");
    }

    for (int i = 0, ok = 1; i < classes; i++)
    {
        if (ok)
        {
            printf("|");
            ok = 0;
        }
        printf(" %.2f |", avr_class[i]);
    }
    printf(" %.2f |", avr_for_students);

    return 0;
}
