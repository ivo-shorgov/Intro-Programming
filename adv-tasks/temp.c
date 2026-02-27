#include <stdio.h>

int main()
{
    int size = 10;
    int arr[] = {3, 7, 2, 8, 5, 1, 9, 4, 6, 10};

    int temp,pos;
    for(int i = 0 ;i < size ;i++)
    {
        pos = i;

        for(int k = i + 1; k < size;k++)
        {
            if(arr[k]< arr[pos])
            pos = k;
        }

        temp = arr[i];
        arr[i] = arr[pos];
        arr[pos] = temp;
    }

    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}
    