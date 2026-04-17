#include <stdio.h>
#define max_br 20

int main()
{
    int elements;
    printf("Enter a number of elements(<=%d) : ", max_br);
    scanf("%d", &elements);
    while (elements > max_br || elements < 1)
    {
        printf("Enter a valid number of elements : ");
        scanf("%d", &elements);
    }

    int arr[elements];

    for (int i = 0; i < elements; i++)
    {
        printf("Enter element %d : ", i + 1);
        scanf("%d", &arr[i]);
    }

    int temp;
    for (int i = 0; i < elements - 1; i++)
    {
        int ok = 1;
        for (int k = 0; k < elements - i; k++)
        {
            if (arr[k] > arr[k + 1])
            {
                temp = arr[k];
                arr[k] = arr[k + 1];
                arr[k + 1] = temp;
                ok = 0;
            }
        }
        if (ok)
            break;
    }

    for (int i = 0; i < elements; i++)
    {
        printf("%d", arr[i]);
    }

    return 0;
}