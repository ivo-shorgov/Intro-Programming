#include <stdio.h>

int main()
{
    for (int n = 100; n < 1000; n++)
    {
        int ones = n % 10;
        int tens = (n / 10) % 10;
        int hundreds = (n / 100) % 10;

        if (hundreds != 0 && tens != 0 && ones != 0)
        {
            if (n % hundreds == 0 && n % tens == 0 && n % ones == 0)
            {
                printf("%d\n", n);
            }
        }

        // if ((hundreds != 0 && tens != 0 && ones != 0) && (n % hundreds == 0 && n % tens == 0 && n % ones == 0))
        // {
        //     printf("%d\n", n);
        // }
    }
    return 0;
}
// Да се състави програма, която намира и извежда всички трицифрени числа, които нямат в записа си цифра 0 и се делят на всяка своя цифра.