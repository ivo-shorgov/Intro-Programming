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
    printf("\n");

    int x;
    printf("Enter the number you are surching for : ");
    scanf("%d", &x);

    int temp;
    int ok = 1;
    for (int i = 0; i < elements - 1; i++)
    {
        for (int k = 0; k < elements - i; k++)
        {
            if (arr[k] > arr[k + 1])
            {
                temp = arr[k];
                arr[k] = arr[k + 1];
                arr[k + 1] = temp;
                ok = 0;
            }
            if (ok)
                break;
        }
    }

    int found = 0;
    for (int first = 0, last = elements - 1; first <= last;)
    {
        int middel = (first + last) / 2;
        if (arr[middel] == x)
            found = 1;
        else if (arr[middel] > x)
        {
            last = middel - 1;
        }
        else
        {
            first = middel + 1;
        }
    }


    if (found)
        printf("the number %d is in the arrey", x);
    else
        printf("the number %d is in the arrey", x);
    return 0;
}