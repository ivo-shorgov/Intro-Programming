#include <stdio.h>

void bublle_sort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int temp = 0;
        int sorted = 1;
        for (int k = 0; k < size - i - 1; k++)
        {
            if (arr[k] > arr[k + 1])
            {
                temp = arr[k + 1];
                arr[k + 1] = arr[k];
                arr[k] = temp;
                sorted = 0;
            }
        }
        if (sorted)
            break;
    }
    for (int i = 0; i < 10; i++)
        printf("%d ", arr[i]);
}
int main()
{
    int arr[] = {3, 5, 1, 9, 6, 8, 7, 2, 4, 10};
    int size = 10;
    bublle_sort(arr, size);
    return 0;
}
