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

    int ok = 1;
    for (int i = 0; i < elements ; i++)
    {
        if (arr[i] < arr[i+1])
            continue;
        else
            ok = 0;
        break;
    }
    if(ok)printf("The arrey is from smallest to biggest");
    else printf("The arrey is not from smallest to biggest");
    return 0;
}