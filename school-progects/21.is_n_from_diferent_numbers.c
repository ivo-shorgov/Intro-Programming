#include<stdio.h>
int main()
{
    int n, reversed = 0, original, remainder;
    printf("Enter an integer: ");
    scanf("%d", &n);
    original = n;
    while (n > 0) 
    {
        int digit = n % 10;
        int temp = n / 10;
        int OK = 1;
        while (temp > 0 && OK) 
        {
            if (digit == temp % 10) 
            {
                OK = 0;
                break;
            }
            temp /=10;
        }
        n /= 10;
    }
        if(OK)
        {
            printf("%d has all different digits.\n", original);
        } 
        else 
        {
            printf("%d does not have all different digits.\n", original);
        }
    return 0;
}
