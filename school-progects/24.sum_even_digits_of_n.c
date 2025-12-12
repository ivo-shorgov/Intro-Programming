#include <stdio.h>
int main() {
    int n, sum = 0;
    printf("Enter a value for n: ");
    scanf("%d", &n);
    while (n != 0) {
        int digit = n % 10;
        if (digit % 2 == 0) {
            sum += digit;
        }
        n /= 10;
    }
    printf("Sum of even digits: %d\n", sum);
    return 0;
}