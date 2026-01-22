#include <stdio.h>

int main()
{
    for (int n = 100; n < 1000; n++)
    {
        int temp = n;
        int hundreds = temp / 100;
        temp %= 100;
        int tens = temp / 10;
        int units = temp % 10;
        
        if (hundreds == 0 || tens == 0 || units == 0)
        {
            continue;
        }
        
        if (n % hundreds == 0 && n % tens == 0 && n % units == 0)
        {
            printf("%d\n", n);
        }
    }
    return 0;
    
}
// Да се състави програма, която намира и извежда всички трицифрени числа, които нямат в записа си цифра 0 и се делят на всяка своя цифра.