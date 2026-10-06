#include <stdio.h>

void reverse() {
    int c = getchar();
    if (c == '.') {
        printf(".");
        return;
    }
    reverse();
    printf("%c", c);
}

int main()
{
    printf("Enter characters ending with '.' (dot):\n");
    reverse();
    printf("\n");
    return 0;
}