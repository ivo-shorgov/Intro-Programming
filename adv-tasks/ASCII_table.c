#include <stdio.h>
#include <windows.h>

int main()
{
    //SetConsoleOutputCP(437); 
    char c1 = 1;
    int i = 0;
    while( i < 256)
    {
        printf("\n%c -> %d",c1,c1);
        c1++;
        i++;
    }
    return 0;
}