#include <stdio.h>
#include <string.h>

int main()
{
    char string[20];
    printf("string : ");
    fgets(string, 20, stdin);
    puts(string);

    int l = strlen(string);

    if (l > 0 && string[l - 1] == '\n')
    {
        string[l - 1] = '\0';
        l--;
    }
    printf("Length (strlen): %d\n", l);

    int count = 0;
    for (int i = 0; string[i] != '\0'; i++)
    {
        count++;
    }
    printf("Length (loop): %d\n", count);

    printf("First symbol: %c\n", string[0]);
    printf("Last symbol: %c\n", string[count - 1]);

    int vowels = 0;
    for (int i = 0; string[i] != '\0'; i++)
    {
        char c = string[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        {
            vowels++;
        }
    }
    printf("Number of vowels: %d\n", vowels);

    char reversed[20];
    int j = 0;
    for (int i = l - 1; i >= 0; i--)
    {
        reversed[j++] = string[i];
    }
    reversed[j] = '\0';
    puts(reversed);

    strrev(string);
    puts(string);

    int isPalindrome = 1;
    for (int i = 0; i < l; i++)
    {
        if (string[i] != reversed[i])
        {
            isPalindrome = 0;
            break;
        }
    }
    if (isPalindrome)
        printf("Yes, it's a palindrome!\n");
    else
        printf("No, it's not a palindrome.\n");

    return 0;
}