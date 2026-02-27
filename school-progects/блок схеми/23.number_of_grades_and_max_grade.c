#include <stdio.h>
int main(void) 
{
    int n;
    printf("Enter number of grades: ");
    scanf("%d", &n);
    while (n < 1) {
        printf("Invalid input. Enter number of grades: ");
        if ( n < 1) {
            printf("Invalid input.\n");
            printf("Enter number of grades: ");
            scanf("%d", &n);
           
        }
    }

    int br2 = 0, br3 = 0, br4 = 0, br5 = 0, br6 = 0;
    for (int i = 1; i <= n; ++i) {
        int grade;
        printf("Enter grade #%d: ", i);
        if (scanf("%d", &grade) != 1) {
            printf("Invalid input.\n");
            return 1;
        }
        while (grade < 2 || grade > 6) {
            printf("Invalid grade. Please enter a grade between 2 and 6.\n");
            printf("Enter grade #%d: ", i + 1);
            if (scanf("%d", &grade) != 1) {
                printf("Invalid input.\n");
                return 1;
            }
        }

        if (grade == 2) br2++;
        else if (grade == 3) br3++;
        else if (grade == 4) br4++;
        else if (grade == 5) br5++;
        else if (grade == 6) br6++;
    }

    int max;
    if (br6 > 0) max = 6;
    else if (br5 > 0) max = 5;
    else if (br4 > 0) max = 4;
    else if (br3 > 0) max = 3;
    else max = 2;

    if (max == 2)
    {
        printf("Maximum grade is 2\n");
        printf("Number of 2: %d\n", br2);
    }
    else if (max == 3)
    {
        printf("Maximum grade is 3\n");
        printf("Number of 3: %d\n", br3);
    }
    else if (max == 4)
    {
        printf("Maximum grade is 4\n");
        printf("Number of 4: %d\n", br4);
    }
    else if (max == 5)
    {
        printf("Maximum grade is 5\n");
        printf("Number of 5: %d\n", br5);
    }   
    else
    {
        printf("Maximum grade is 6\n");
        printf("Number of 6: %d\n", br6);   
    }

    return 0;
}