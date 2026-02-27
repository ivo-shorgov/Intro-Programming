// array 20 elements: negatives on left, positives on right

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

    for (int i = 0; i < 5; i++)
    {
        printf("Enter element %d : ", i + 1);
        scanf("%d", &arr[i]);
    }

    int temp;
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] > 0)
        {
            for (int m = i + 1; m < 10; m++)
            {
                if (arr[m] < 0)
                {
                    temp = arr[m];
                    arr[m] = arr[i];
                    arr[i] = temp;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    temp = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int k = 0; k < 9; k++)
        {
            if (arr[k] > arr[k + 1])
            {
                temp = arr[k];
                arr[k] = arr[k + 1];
                arr[k + 1] = temp;
            }
        }
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}