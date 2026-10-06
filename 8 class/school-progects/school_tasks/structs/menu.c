#include <stdio.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_SUBJECTS 20

typedef struct
{
    int num;
    char name[MAX_NAME_LEN];
    int marks[MAX_SUBJECTS];
    float avr;
} TStudent;

void printMenu(void)
{
    printf("\n===== МЕНЮ =====\n");
    printf("1. Сортиране по име\n");
    printf("2. Сортиране по успех\n");
    printf("3. Ученици със стипендия\n");
    printf("4. Ученици с поправителни\n");
    printf("5. Брой поправителни изпити\n");
    printf("6. Изход\n");
}

void printStudentRow(const TStudent *student, int brp)
{
    printf("%-5d | %-20s | ", student->num, student->name);
    for (int j = 0; j < brp; j++)
    {
        printf("%d ", student->marks[j]);
    }
    printf("\t | %.2f\n", student->avr);
}

int createStudentFile(const char *filename)
{
    int n, brp;
    printf("Въведете брой ученици: ");
    scanf("%d", &n);
    printf("Въведете брой предмети: ");
    scanf("%d", &brp);
    getchar();

    FILE *f = fopen(filename, "wb");
    if (!f)
    {
        printf("Грешка при отваряне на файл за запис\n");
        return 0;
    }

    fwrite(&n, sizeof(int), 1, f);
    fwrite(&brp, sizeof(int), 1, f);

    for (int i = 0; i < n; i++)
    {
        TStudent student;
        printf("\nУченик %d\n", i + 1);
        printf("Номер: ");
        scanf("%d", &student.num);
        getchar();

        printf("Име: ");
        if (fgets(student.name, MAX_NAME_LEN, stdin) == NULL)
            student.name[0] = '\0';
        char *p = strchr(student.name, '\n');
        if (p)
            *p = '\0';

        float sum = 0;
        for (int j = 0; j < brp; j++)
        {
            printf("Оценка %d: ", j + 1);
            scanf("%d", &student.marks[j]);
            sum += student.marks[j];
        }
        getchar();

        student.avr = sum / brp;
        fwrite(&student, sizeof(student), 1, f);
    }

    fclose(f);
    return 1;
}

void printAllStudents(const char *filename)
{
    FILE *f = fopen(filename, "rb");
    if (!f)
    {
        printf("Грешка при отваряне на файл за четене\n");
        return;
    }

    int recordCount, brp;
    if (fread(&recordCount, sizeof(int), 1, f) != 1 || fread(&brp, sizeof(int), 1, f) != 1)
    {
        fclose(f);
        return;
    }

    printf("\n========================================================\n");
    printf("No.   | Name                 | Marks        | Average\n");
    printf("--------------------------------------------------------\n");

    TStudent student;
    for (int i = 0; i < recordCount; i++)
    {
        if (fread(&student, sizeof(student), 1, f) == 1)
            printStudentRow(&student, brp);
    }

    printf("========================================================\n");
    fclose(f);
}

static void swapFileRecords(FILE *f, int i, int j, int brp)
{
    TStudent a, b;
    long offset_a = sizeof(int) * 2 + (long)i * sizeof(TStudent);
    long offset_b = sizeof(int) * 2 + (long)j * sizeof(TStudent);

    fseek(f, offset_a, SEEK_SET);
    if (fread(&a, sizeof(a), 1, f) != 1)
        return;

    fseek(f, offset_b, SEEK_SET);
    if (fread(&b, sizeof(b), 1, f) != 1)
        return;

    fseek(f, offset_a, SEEK_SET);
    fwrite(&b, sizeof(b), 1, f);
    fseek(f, offset_b, SEEK_SET);
    fwrite(&a, sizeof(a), 1, f);
}

void sortFileByName(const char *filename)
{
    FILE *f = fopen(filename, "r+b");
    if (!f)
    {
        printf("Грешка при отваряне на файл за редакция\n");
        return;
    }

    int recordCount, brp;
    if (fread(&recordCount, sizeof(int), 1, f) != 1 || fread(&brp, sizeof(int), 1, f) != 1)
    {
        fclose(f);
        return;
    }

    TStudent a, b;
    for (int i = 0; i < recordCount - 1; i++)
    {
        for (int j = i + 1; j < recordCount; j++)
        {
            long offset_i = sizeof(int) * 2 + (long)i * sizeof(TStudent);
            long offset_j = sizeof(int) * 2 + (long)j * sizeof(TStudent);

            fseek(f, offset_i, SEEK_SET);
            if (fread(&a, sizeof(a), 1, f) != 1)
                continue;
            fseek(f, offset_j, SEEK_SET);
            if (fread(&b, sizeof(b), 1, f) != 1)
                continue;

            if (strcmp(a.name, b.name) > 0)
                swapFileRecords(f, i, j, brp);
        }
    }

    fclose(f);
}

void sortFileByAverage(const char *filename)
{
    FILE *f = fopen(filename, "r+b");
    if (!f)
    {
        printf("Грешка при отваряне на файл за редакция\n");
        return;
    }

    int recordCount, brp;
    if (fread(&recordCount, sizeof(int), 1, f) != 1 || fread(&brp, sizeof(int), 1, f) != 1)
    {
        fclose(f);
        return;
    }

    TStudent a, b;
    for (int i = 0; i < recordCount - 1; i++)
    {
        for (int j = i + 1; j < recordCount; j++)
        {
            long offset_i = sizeof(int) * 2 + (long)i * sizeof(TStudent);
            long offset_j = sizeof(int) * 2 + (long)j * sizeof(TStudent);

            fseek(f, offset_i, SEEK_SET);
            if (fread(&a, sizeof(a), 1, f) != 1)
                continue;
            fseek(f, offset_j, SEEK_SET);
            if (fread(&b, sizeof(b), 1, f) != 1)
                continue;

            if (a.avr < b.avr)
                swapFileRecords(f, i, j, brp);
        }
    }

    fclose(f);
}

void printScholarshipStudents(const char *filename)
{
    FILE *f = fopen(filename, "rb");
    if (!f)
    {
        printf("Грешка при отваряне на файл за четене\n");
        return;
    }

    int recordCount, brp;
    if (fread(&recordCount, sizeof(int), 1, f) != 1 || fread(&brp, sizeof(int), 1, f) != 1)
    {
        fclose(f);
        return;
    }

    TStudent student;
    int count = 0;

    printf("\nУченици със стипендия:\n");
    printf("\n========================================================\n");
    printf("No.   | Name                 | Marks        | Average\n");
    printf("--------------------------------------------------------\n");

    for (int i = 0; i < recordCount; i++)
    {
        if (fread(&student, sizeof(student), 1, f) != 1)
            break;
        if (student.avr >= 5.50)
        {
            count++;
            printStudentRow(&student, brp);
        }
    }

    if (count == 0)
        printf("Няма ученици със средна оценка >= 5.50\n");

    printf("========================================================\n");
    fclose(f);
}

void printStudentsWithRetakes(const char *filename)
{
    FILE *f = fopen(filename, "rb");
    if (!f)
    {
        printf("Грешка при отваряне на файл за четене\n");
        return;
    }

    int recordCount, brp;
    if (fread(&recordCount, sizeof(int), 1, f) != 1 || fread(&brp, sizeof(int), 1, f) != 1)
    {
        fclose(f);
        return;
    }

    TStudent student;
    int count = 0;

    printf("\nУченици с поправителни:\n");
    printf("\n========================================================\n");
    printf("No.   | Name                 | Marks        | Average\n");
    printf("--------------------------------------------------------\n");

    for (int i = 0; i < recordCount; i++)
    {
        if (fread(&student, sizeof(student), 1, f) != 1)
            break;

        int hasExam = 0;
        for (int j = 0; j < brp; j++)
        {
            if (student.marks[j] < 3)
            {
                hasExam = 1;
                break;
            }
        }

        if (hasExam)
        {
            count++;
            printStudentRow(&student, brp);
        }
    }

    if (count == 0)
        printf("Няма\n");

    printf("========================================================\n");
    fclose(f);
}

int printAndCountRetakeExams(const char *filename)
{
    FILE *f = fopen(filename, "rb");
    if (!f)
    {
        printf("Грешка при отваряне на файл за четене\n");
        return 0;
    }

    int recordCount, brp;
    if (fread(&recordCount, sizeof(int), 1, f) != 1 || fread(&brp, sizeof(int), 1, f) != 1)
    {
        fclose(f);
        return 0;
    }

    TStudent student;
    int totalRetakes = 0;
    int studentCount = 0;

    printf("\nУченици с поправителни изпити:\n");
    printf("\n========================================================\n");
    printf("No.   | Name                 | Marks        | Average\n");
    printf("--------------------------------------------------------\n");

    for (int i = 0; i < recordCount; i++)
    {
        if (fread(&student, sizeof(student), 1, f) != 1)
            break;

        int hasExam = 0;
        for (int j = 0; j < brp; j++)
        {
            if (student.marks[j] < 3)
            {
                hasExam = 1;
                totalRetakes++;
            }
        }

        if (hasExam)
        {
            studentCount++;
            printStudentRow(&student, brp);
        }
    }

    if (studentCount == 0)
        printf("Няма\n");

    printf("========================================================\n");
    fclose(f);
    return totalRetakes;
}

int main(void)
{
    const char *filename = "students.dat";
    if (!createStudentFile(filename))
        return 1;

    int choice;
    do
    {
        printMenu();
        printf("Изберете опция: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            sortFileByName(filename);
            printAllStudents(filename);
            break;
        case 2:
            sortFileByAverage(filename);
            printAllStudents(filename);
            break;
        case 3:
            printScholarshipStudents(filename);
            break;
        case 4:
            printStudentsWithRetakes(filename);
            break;
        case 5:
        {
            int totalRetakes = printAndCountRetakeExams(filename);
            printf("\nОбщ брой поправителни изпити: %d\n", totalRetakes);
            break;
        }
        case 6:
            printf("Изход...\n");
            break;
        default:
            printf("Невалиден избор!\n");
            break;
        }
    } while (choice != 6);

    return 0;
}
