#include <stdio.h>
#include <string.h>

int readAndCleanString(char string[], int maxSize);
void printStringLengths(char string[]);
void firstAndLastSymbol(char string[]);
void numberOFvowels(char string[]);
void reverseString(char reversed[], char string[]);
void checkForPalindrom(char string[], char reversed[], int len);
void UpercaseForLettersAndStarsForNumbers(char string[]);
void Palindrom(char string[], int len);
void revers(char string[], int last_index);

#define MAX_SIZE 20

int main()
{
    char string[MAX_SIZE];

    // task 1
    int len = readAndCleanString(string, MAX_SIZE);

    // task 2
    printStringLengths(string);

    // task 3
    firstAndLastSymbol(string);

    // task 4
    numberOFvowels(string);

    // task 5
    char reversed[20];
    reverseString(reversed, string);

    // task 6
    checkForPalindrom(string, reversed, len);

    // task 7
    UpercaseForLettersAndStarsForNumbers(string);

    Palindrom(string, len);

    revers(string, len - 1);

    return 0;
}

int readAndCleanString(char string[], int maxSize)
{
    printf("[Task 1] - Reading, printing and cleaning a string?\n");
    printf("string : ");
    fgets(string, maxSize, stdin);
    puts(string);

    int len = strlen(string);
    if (len > 0 && string[len - 1] == '\n')
    {
        string[len - 1] = '\0';
        len--;
    }
    return len;
}

void printStringLengths(char string[])
{
    printf("[Task 2] - Finding the lenght of a string two ways?\n");
    int lenStrlen = strlen(string);
    printf("Length (strlen): %d\n", lenStrlen);

    int lenLoop = 0;
    while (string[lenLoop] != '\0')
    {
        lenLoop++;
    }
    printf("Length (loop): %d\n", lenLoop);
}

void firstAndLastSymbol(char string[])
{
    printf("\n[Task 3] -First and last symbol of a string?\n");
    int len = strlen(string);
    printf("First symbol: %c\n", string[0]);
    printf("Last symbol: %c\n", string[len - 1]);
}

void numberOFvowels(char string[])
{
    printf("\n[Task 4] - RNumber of vowels in a string?\n");
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
}

void reverseString(char reversed[], char string[])
{
    printf("\n[Task 5] - Reversing a string?\n");
    int len = strlen(string);
    int j = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        reversed[j++] = string[i];
    }
    reversed[j] = '\0';
    puts(reversed);
}

void checkForPalindrom(char string[], char reversed[], int len)
{
    printf("\n[Task 6] - Checking if the string is a palindrom?\n");
    int isPalindrome = 1;
    for (int i = 0; i < len; i++)
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
}

void UpercaseForLettersAndStarsForNumbers(char string[])
{
    printf("\n[Task 7] -  Change lower case letters to upercase and replace the digits with a star?\n");
    printf("Input: %s\n", string);
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] >= 'a' && string[i] <= 'z')
        {
            string[i] = string[i] - 'a' + 'A';
        }
        if (string[i] >= '0' && string[i] <= '9')
        {
            string[i] = '*';
        }
    }
    printf("Result: %s\n", string);
}

void Palindrom(char string[], int len)
{
    int ok = 1, left = 0, right = len - 1;
    while (left < right)
    {
        if (string[left] != string[right])
        {
            ok = 0;
            break;
        }
        left++;
        right--;
    }
    if (ok)
        printf("Yes, it's a palindrome!\n");
    else
        printf("No, it's not a palindrome.\n");
}

void revers(char string[], int last_index)
{
    if (last_index < 0)
        return;
    else
    {
        printf("%c", string[last_index]);
        revers(string, last_index - 1);
    }
}