#include<stdio.h>
int main()
{
    int a;
    printf("a= ");
    scanf("%d",&a);
    if (a % 3==0 && a % 5==0)
        printf("FizzBuzz\n");
    else if (a % 3==0)
        printf("Fizz\n");
    else if (a % 5==0)
        printf("Buzz\n");
    
}