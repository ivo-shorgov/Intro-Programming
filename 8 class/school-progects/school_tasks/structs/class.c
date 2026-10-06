#include <stdio.h>
#include <string.h>

typedef struct {
    int num;
    char name[50];
    int marks[20];
    float avr;
} TStudent;

int main()
{
    TStudent students[100]; // Масив за учениците
    int n, brp, i, j;
    char *p;

    // 1. Въвеждане на брой предмети 
    do {
        printf("Subject count (1-20) = \n");
        scanf("%d", &brp);
    } while(brp < 1 || brp > 20);

    // 2. Въвеждане на брой ученици
    do {
        printf("Student count (1-100) = \n");
        scanf("%d", &n);
    } while(n < 1 || n > 100);

    // 3. Въвеждане на данните за всеки ученик
    for(i = 0; i < n; i++) {
        printf("\n--- Next Student ---\n");
        
        printf("Num = \n");
        scanf("%d", &students[i].num);
        getchar();

        printf("Name =");
        fgets(students[i].name, 50, stdin);
    
        if(p = strchr(students[i].name, '\n')) {
            *p = '\0';
        }

        students[i].avr = 0;
        for(j = 0; j < brp; j++) {
            printf("Mark = \n");
            scanf("%d", &students[i].marks[j]);
            students[i].avr += students[i].marks[j];
        }
        students[i].avr = students[i].avr / brp;
    }

    // 4. Извеждане на таблицата
    printf("\n========================================================");
    printf("No.   | Name                 | Marks        | Average");
    printf("--------------------------------------------------------");

    for(i = 0; i < n; i++) {
        // Комбинирано извеждане на числа и низ -> printf
        printf("%-5d | %-20s | ", students[i].num, students[i].name);
        
        for(j = 0; j < brp; j++) {
            printf("%d ", students[i].marks[j]);
        }
        
        printf("\t | %.2f\n", students[i].avr);
    }
    printf("========================================================");

    return 0;
}