// 3 зад. Премахване на дубликати.  Отпечатайте елементите на масива без повторение
// Пример:
// Вход:   12 44 55 12 4 55 2
// Изход: 12 44 55 4 2

#include <stdio.h>
#define max_br 20
int main()
{
    int n = 0;
    printf("Enter number of elements in masiv : ");
    scanf("%d", &n);
    int arr[max_br];

    for (int i = 0; i < n; i++)
    {
        printf("element %d = ", i + 1);
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int m = i + 1; m < n; m++)
        {
            if (arr[i] == arr[m])
                arr[m] = 0;
        }
    }

    printf("Masiv without dublicate : \n");
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
            printf("%d ", arr[i]);
    }

    return 0;
}