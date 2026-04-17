#include <stdio.h>

void swap(int *p_a, int *p_b)
{
    int c;
    c = *p_a;
    *p_a = *p_b;
    *p_b = c;
}

int main()
{
    int num1 = 5, num2 = 7;
     printf("%p  %p\n", &num1,&num2);
    swap(num1, num2);
    printf("num1 = %d; num2 = %d", num1, num2);
    int p_a = num1;
    num1 = 4;
    printf("%d  %d\n",num1,p_a);
    return 0;
}