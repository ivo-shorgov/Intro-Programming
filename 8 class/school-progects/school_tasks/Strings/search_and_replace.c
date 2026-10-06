// search and replace
#include <stdio.h>
#include <string.h>

int main()
{
    char s[50];
    char s1[10];
    char s2[10];
    char *p;
    int l1, l2, l, i;
    printf("s=");
    fgets(s, 50, stdin);
    if (p = strchr(s, '\n'))
        *p = '\0';

    printf("s1=");
    fgets(s1, 10, stdin);
    if (p = strchr(s1, '\n'))
        *p = '\0';

    printf("s2=");
    fgets(s2, 10, stdin);
    if (p = strchr(s2, '\n'))
        *p = '\0';

    l1 = strlen(s1);
    l2 = strlen(s2);

    p = s;

    while (p = strstr(p, s1))
    {
        strcpy(p, p + l1); 

       
        l = strlen(p); 
        for (i = l + l2; i >= l2; i--)
            *(p + i) = *(p + i - l2); 

        for (i = 0; s2[i]; i++)
        {
            *p = s2[i];
            p++;
        }
    }
    printf("\ns=%s", s);

    return 0;
}
