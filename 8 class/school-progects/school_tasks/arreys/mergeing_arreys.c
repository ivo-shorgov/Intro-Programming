#include <stdio.h>

int main()
{
    int arr_1[] = {1, 3, 5, 7, 9};
    int size_1 = sizeof(arr_1) / sizeof(arr_1[0]);

    int arr_2[] = {0, 2, 4, 6, 8, 10};
    int size_2 = 6;

    int arr_3[size_1 + size_2];

    for (int first = 0, second = 0, third = 0; first < size_1 || second < size_2;)
    {
        if (second == size_2 || (first < size_1 && arr_1[first] < arr_2[second]))
        {
            arr_3[third++] = arr_1[first++];
        }
        else
        {
            arr_3[third++] = arr_2[second++];
        }
    }

    for (int i = 0; i < (size_1 + size_2); i++)
    {
        printf("%d ", arr_3[i]);
    }
    return 0;
}