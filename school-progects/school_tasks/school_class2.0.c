#include <stdio.h>
#define max_u 30
#define max_p 20
int main()
{

    int marks[max_u][max_p];
    int students, classes;
    // въвеждане на брой ученици (n) и брой предмети (m)

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

    // въвеждане на оценките
    int i, k;
    for (i = 0; i < students; i++)
    {
        for (k = 0; k < classes; k++)
        {
            do
            {
                printf("mark %d for student %d=", k + 1, i + 1);
                scanf("%d", &marks[i][k]);
            } while (marks[i][k] < 2 || marks[i][k] > 6);
        }
    }
    // изчисляване на средния успех на всеки ученик
    float avr_u[max_u];

    for (i = 0; i < students; i++)
    {
        avr_u[i] = 0;
        for (k = 0; k < classes; k++)
            avr_u[i] = avr_u[i] + marks[i][k];
        avr_u[i] = avr_u[i] / classes;
    }

    // изчисляване на средния успех на класа по всеки предмет
    float avr_p[max_p];

    for (k = 0; k < classes; k++)
    {
        avr_p[k] = 0;
        for (i = 0; i < students; i++)
            avr_p[k] = avr_p[k] + marks[i][k];
        avr_p[k] = avr_p[k] / students;
    }

    // изчисляване на средния успех на класа
    float avr = 0;

    for (i = 0; i < students; i++)
        for (k = 0; k < classes; k++)
            avr = avr + marks[i][k];
    avr = avr / (students * classes);

    for (i = 0; i < students; i++)
    {
        for (k = 0; k < classes; k++)
            printf("%-5d", marks[i][k]);
        printf("%-5.2f\n", avr_u[i]);
    }
    for (i = 0; i < classes; i++)
        printf("%-5.2f", avr_p[i]);
    printf("%-5.2f", avr);

    return 0;
}
