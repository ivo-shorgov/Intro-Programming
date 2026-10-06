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

    int ok;
    for (int i = 0; i < elements; i++)
    {
        if (arr[i] == x)
            ok = 1;
        break;
    }

    if (ok)
        printf("the number %d is in the arrey", x);
    else
        printf("the number %d is in the arrey", x);
    return 0;
}