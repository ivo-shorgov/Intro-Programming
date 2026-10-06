// 1 зад. Да се въведат оценките на учениците от един клас (брой ученици<=30). Оценките са цели числа между 2 и 6.
// Да се изчисли средният успех на класа;
// Да се изведат номерата на учениците, които имат успех по-голям или равен на средния;
// Да се намери най-ниската и най-високата оценка в класа;
// Да се изведат номерата на учениците, които имат оценка, равна на най-високата оценка;
// Да се изведат номерата на учениците, които имат оценка, равна на най-ниската оценка;

#include <stdio.h>
#define max_br 30
int main()
{
    float grades[max_br];
    float s = 0, avr = 0;
    int n = 0, i = 0;

    // 1 - validateing the number of students
    do
    {
        printf("n=?(n<=%d):", max_br);
        scanf("%d", &n);
        if (n < 0 || n > max_br)
        {
            printf("Invalid number of students. n=?(n<=%d):", max_br);
        }
    } while (n < 1 || n > max_br);

    // 2 - entering their grades
    for (i = 0; i < n; i++)
    {
        printf("student grade %d = ", i + 1);
        scanf("%f", &grades[i]);
        while (grades[i] < 2 || grades[i] > 6)
        {
            printf("Invalid garde for student  %d = ", i + 1);
            printf("Enter again : ");
            scanf("%f", &grades[i]);
        }
    }

    // 3 - finding average grade
    for (i = 0; i < n; i++)
        s += grades[i];

    avr = s / n;
    printf("\nThe average is = %.2f", avr);

    // 4 - finding students with bigger or equal grade to the average one
    for (i = 0; i < n; i++)
    {
        if (grades[i] >= avr)
            printf("\nstudent %d has bigger or equal garde than the average grade", i + 1);
    }
    printf("\n");

    // 5 - finding nim and max grade
    int max_grade = 0, min_grade = 7;
    for (i = 0; i < n; i++)
    {
        if (grades[i] > max_grade)
            max_grade = grades[i];
        else if (grades[i] < min_grade)
            min_grade = grades[i];
    }
    printf("\nmax grade is = %d", max_grade);
    printf("\nmin grade is = %d", min_grade);

    printf("\n");

    // 6 - finding students with max grade
    for (i = 0; i < n; i++)
    {
        if (grades[i] == max_grade)
            printf("\nstudent %d has a grade equal to the max grade", i + 1);
    }

    printf("\n");

    // 7 - finding student with min grade
    for (i = 0; i < n; i++)
    {
        if (grades[i] == min_grade)
            printf("\nstudent %d has a grade equal to the min grade", i + 1);
    }

    return 0;
}