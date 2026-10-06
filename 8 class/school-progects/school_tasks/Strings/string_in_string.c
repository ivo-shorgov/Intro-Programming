#include <stdio.h>
#include <string.h>

int count(char *s1, char *s2) {
    int counter = 0;
    char *p = strstr(s1, s2);
    
    while (p != NULL) {
        counter++;
        p = strstr(p + 1, s2);
    }
    
    return counter;
}

int main() {
    char s1[100], s2[100];
    
    printf("Въведете s1: ");
    fgets(s1, sizeof(s1), stdin);
    char *p = strchr(s1, '\n');
    if (p != NULL) *p = '\0';
    int l1 = strlen(s1);
    
    printf("Въведете s2: ");
    fgets(s2, sizeof(s2), stdin);
    p = strchr(s2, '\n');
    if (p != NULL) *p = '\0';
    int l2 = strlen(s2);

    int loop_counter=0,counter = 0;
    char *ptr =  strstr(s1,s2);
    while (loop_counter <= l1 )
    {
        if(ptr != NULL)
        {
            counter++;
            loop_counter = loop_counter + l2;
        }
    }
    printf("Брой срещания: %d\n", counter);
    
    printf("Брой срещания: %d\n", count(s1, s2));
    return 0;
}