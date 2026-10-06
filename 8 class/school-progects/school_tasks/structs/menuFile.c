#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  int num;
  char name[20];
  int marks[20];
  float avr;
} TStudent;

void mywrite(char *filename);
void myread(char *filename);
void myadd(char *filename);
void myedit(char *filename);
void mydelete(char *filename);

int main()
{
  int op;
  char filename[80], *p;

  printf("Enter filename: ");
  fgets(filename, 80, stdin);
  if (p = strchr(filename, '\n'))
    *p = '\0';

  while (1)
  {
   // system("cls");

    printf("1. Change file\n");
    printf("2. Write\n");
    printf("3. Read\n");
    printf("4. Add\n");
    printf("5. Edit\n");
    printf("6. DELETE\n");
    printf("7. Exit\n");
    printf("Select option: ");
    scanf("%d", &op);

    switch (op)
    {
    case 1:
      printf("New filename: ");
      getchar(); 
      fgets(filename, 80, stdin);
      if (p = strchr(filename, '\n'))
        *p = '\0';
      break;
    case 2:
      mywrite(filename);
      break;
    case 3:
      myread(filename);
      break;
    case 4:
      myadd(filename);
      break;
    case 5:
      myedit(filename);
      break;
    case 6:
      mydelete(filename);
      break;
    case 7:
      return 0;
    default:
      printf("Incorrect choice!");
    }
    printf("\nPress Enter to continue...");
    getchar();
    getchar(); 
  }
  return 0;
}

void mywrite(char *filename)
{
  TStudent s;
  FILE *f = fopen(filename, "wb");
  char *p;
  int k, i = 0;

  if (!f)
    return;
  while (1)
  {
    printf("num (-1 for end) = ");
    scanf("%d", &s.num);
    if (s.num == -1)
      break;

    getchar(); 
    printf("name = ");
    fgets(s.name, 20, stdin);
    if (p = strchr(s.name, '\n'))
      *p = '\0';

    s.avr = 0;
    k = 0;
    while (k < 20)
    {
      printf("Mark %d (-1 for end) = ", k + 1);
      scanf("%d", &s.marks[k]);
      if (s.marks[k] == -1)
        break;
      s.avr += s.marks[k];
      k++;
    }
    if (k)
      s.avr /= k;

    fwrite(&s, sizeof(s), 1, f);
  }
  fclose(f);
}

void myread(char *filename)
{
  TStudent s;
  FILE *f = fopen(filename, "rb");
  int k;

  if (!f)
    return;
  while (fread(&s, sizeof(s), 1, f))
  {
    printf("%3d %-21s", s.num, s.name);
    k = 0;
    while (k < 20)
    {
      if (s.marks[k] == -1)
        break;
      printf("%3d", s.marks[k]);
      k++;
    }
    printf("%6.2f\n", s.avr);
  }
  fclose(f);
}

void myadd(char *filename)
{
  TStudent s;
  FILE *f = fopen(filename, "a");
  char *p;
  int k;

  if (!f)
    return;

  printf("num = ");
  scanf("%d", &s.num);

  getchar(); 
  printf("name = ");
  fgets(s.name, 20, stdin);
  if (p = strchr(s.name, '\n'))
    *p = '\0';

  s.avr = 0;
  k = 0;
  while (k < 20)
  {
    printf("Mark %d (-1 for end) = ", k + 1);
    scanf("%d", &s.marks[k]);
    if (s.marks[k] == -1)
      break;
    s.avr += s.marks[k];
    k++;
  }
  if (k)
    s.avr /= k;

  fwrite(&s, sizeof(s), 1, f);
  fclose(f);
}

void myedit(char *filename)
{
  TStudent s;
  FILE *f = fopen(filename, "r+");
  char *p;
  int num, k;
  long int mypos;

  if (!f)
    return;
  
  printf("Enter ID to edit: ");
  scanf("%d", &num);

  while (fread(&s, sizeof(s), 1, f))
  {
    mypos = ftell(f) - sizeof(s);
    if (num == s.num)
    {
      printf("Enter new ID: ");
      scanf("%d", &s.num);

      getchar(); 
      printf("New name: ");
      fgets(s.name, 20, stdin);
      if (p = strchr(s.name, '\n'))
        *p = '\0';

      s.avr = 0;
      k = 0;
      while (k < 20)
      {
        printf("New mark %d (-1 for end) = ", k + 1);
        scanf("%d", &s.marks[k]);
        if (s.marks[k] == -1)
          break;
        s.avr += s.marks[k];
        k++;
      }
      if (k)
        s.avr /= k;

      fseek(f, mypos, SEEK_SET);
      fwrite(&s, sizeof(s), 1, f);
      break;
    }
  }
  fclose(f);
}

void mydelete(char *filename)
{
  TStudent s;
  FILE *f = fopen(filename, "rb");
  FILE *temp = fopen("temp.dat", "wb");
  int searchNum;

  if (!f || !temp)
    return;

  printf("Enter ID to DELETE: ");
  scanf("%d", &searchNum);

  while (fread(&s, sizeof(s), 1, f))
  {
    if (s.num == searchNum)
      continue;
    fwrite(&s, sizeof(s), 1, temp);
  }

  fclose(f);
  fclose(temp);

  remove(filename);
  rename("temp.dat", filename);
}