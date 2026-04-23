// 2 зад. Обръщане на масив.
// Пренаредете елементите на масива в обратен ред (без да използвате втори помощен масив).

#include <stdio.h>

int main()
{
    int n, i;
    printf("Enter number of elements in masiv : ");
    scanf("%d", &n);
    int masiv[n];

    for (i = 0; i < n; i++)
    {
        printf("element %d = ", i + 1);
        scanf("%d", &masiv[i]);
    }

    int tail = n - 1, head = 0, temp;
    while (head < tail)
    {
        temp = masiv[head];
        masiv[head] = masiv[tail];
        masiv[tail] = temp;
        head++;
        tail--;
    }

    printf("masiv in reverse is : ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", masiv[i]);
    }
    return 0;
}