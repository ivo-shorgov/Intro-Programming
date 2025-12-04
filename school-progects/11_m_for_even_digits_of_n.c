#include<stdio.h>  
int main()  
{  
    int n, digit, m = 0, place = 1;  
    printf("n = ");  
    while(scanf("%d", &n)<2)
    {
        printf("invalid input. Please enter a non-negative integer for n.\n");
        printf("n ="); 
    }
    
    while(n > 0)  
    {  
        digit = n % 10;  
        if(digit % 2 == 0)  
        {  
            m = m + digit * place;  
            place = place * 10;  
        }  
        n = n / 10;  
    }  
    
    printf("The number formed by the even digits of n is: %d\n", m);  
    return 0;  
}