#include <stdio.h>
int main()
{
    int h1, m1;
    int h2, m2;
    int travel_times_in_mins;

    printf("start hour(h1): ");
    scanf("%d", &h1); 
    printf("start minute(m1): ");
    scanf("%d", &m1);
    printf("end hour(h2): ");
    scanf("%d", &h2);
    printf("end minute(m2): ");
    scanf("%d", &m2);

    travel_times_in_mins = (h2 * 60 + m2) - (h1 * 60 + m1);

    printf("The car was traveling for %d hours and %d minutes\n", travel_times_in_mins / 60, travel_times_in_mins % 60);
    
    return 0;
}