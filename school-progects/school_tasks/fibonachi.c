#include <stdio.h>

// функция за намиране на n-тото число на Фибоначи
int fibonacci(int n) {
    int a = 0, b = 1, next, i = 2;

    if (n == 0) return a;
    if (n == 1) return b;

    while (i <= n) {
        next = a + b;
        a = b;
        b = next;
        i++;
    }

    return b;
}
int fibonacci_recrusion(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;

    printf("Въведи n: ");
    scanf("%d", &n);

    printf("Fibonacci(%d) = %d\n", n, fibonacci(n));

    return 0;
}