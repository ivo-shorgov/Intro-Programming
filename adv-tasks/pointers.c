#include <stdio.h>

int main()
{
    char c = 'K';
    short int si = 29;
    int i = 0;
    long int l = 94;
    long long int ll = 42;
    float f = 4.025;
    double d = 12.74;

    char *pc = &c;
    short int *psi = &si;
    int *pi = &i;
    long int *pl = &l;
    long long int *pll = &ll;
    float *pf = &f;
    double *pd = &d;

    printf("%-10p  %-10p  %-10p  %-10p  %-10p  %-10.3p  %-10.3p", pc, psi, pi, pl, pll, pf, pd);
    printf("\n");
    printf("%p %p", &i, pi);
    printf("\n");

    int s =49;
    int *ps =&s;
    s =50;
    *ps = 51;
    printf("%d  %d",s, *ps);

    return 0;
}