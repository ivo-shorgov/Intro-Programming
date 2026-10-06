#include<stdio.h>
int main() {
    int n;

    printf("n = ");
    scanf("%d", &n);

    while(n < 1 ) {
        printf("invalid intiger for n: \n ");
        printf("n = ");
        scanf("%d", &n);
    }
    int max=-1, min=10, x;

    while (n > 0)
    {

        x=n%10;

        if(x>max) {
            max=x;
        }

        if(x<min) {
            min=x;
        }

        n=n/10;
    }

    printf("max = %d\n", max);
    printf("min = %d\n", min);
    return 0;
}