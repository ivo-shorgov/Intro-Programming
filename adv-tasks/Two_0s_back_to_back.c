#include <stdio.h>
int main()
{
    int n;
    printf("Enter the number of elements - ");
    scanf("%d",&n);
    while(n < 1)
    {
        printf("Invalid input.\n");
        printf("Enter the number of elements again - ");
        scanf("%d",&n);
    }
    int i, br;
    for(i=1,br=0;i<=n;i++)
    {
    
        int a = 0;
        printf("Enter a number : ");
        scanf("%d",&a);
        while(a < 1)
        {
            printf("Invalid input.\n");
            printf("Enter the number of elements again - ");
            scanf("%d",&n);
        }
        while(a>0)
        {
            int x = a%10, m = (a%100-x)/10;
            if(m==x && x == 0)
            {
                br++;
                break;
            }
            a/=10;
        }
        
    }
    printf("The number of elements that have 2 0s back to back is %d",br);
    return 0;
}