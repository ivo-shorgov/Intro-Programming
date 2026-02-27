#include <stdio.h>

int main() {
    int k, n;
    printf("k = ");
    scanf("%d", &k);
    while ( k < 1) {
        printf("invalid input, k must be >= 1\n");
        printf("k = ");
    }

    printf("n = ");
    scanf("%d", &n);
    while (n < 1) {
        printf("invalid input, n must be >= 1\n");
        printf("n = ");
    }

    int count = 0;
    for (int i = 0; i < n; ++i) {
        int num;
        printf("num = ");
        scanf("%d", &num);

        if (num < 0) {
            num = -num; 
        }

        int digits = 0;
        if (num == 0) {
            digits = 1;
        } else {
            while (num > 0) {
                digits++;
                num /= 10;
            }
        }

        if (digits == k)
            count++;
    }

    printf("the count of numbers with %d digits is %d\n", k, count);
    return 0;
}
