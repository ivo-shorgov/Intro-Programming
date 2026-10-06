#include <stdio.h>

// Функция за решаване на Ханойските кули
void hanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("Премести диск 1 от %c към %c\n", from, to);
        return;
    }

    // Преместваме n-1 диска към помощната кула
    hanoi(n - 1, from, aux, to);

    // Преместваме най-големия диск
    printf("Премести диск %d от %c към %c\n", n, from, to);

    // Преместваме обратно n-1 диска върху него
    hanoi(n - 1, aux, to, from);
}

int main() {
    int n;

    printf("Въведи брой дискове: ");
    scanf("%d", &n);

    hanoi(n, 'A', 'C', 'B');

    return 0;
}