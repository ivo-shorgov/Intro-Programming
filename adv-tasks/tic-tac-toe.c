#include <stdio.h>

int main()
{
    char a1 = ' ', a2 = ' ', a3 = ' ';
    char b1 = ' ', b2 = ' ', b3 = ' ';
    char c1 = ' ', c2 = ' ', c3 = ' ';

    for (int turn = 1; turn < 9; turn++)
    {
        int cell_number;
        printf("Pick a cell number from 1 to 9 : ");
        scanf("%d", &cell_number);
        while (cell_number < 1 || cell_number > 9)
        {
            printf("Invalide input \n");
            printf("Please enter the cell number again : ");
            scanf("%d", &cell_number);
        }
        char symbol = ' ';
        if (turn % 2 == 0)
        {
            symbol = '0';
        }
        else
        {
            symbol = 'X';
        }

        if (cell_number == 1)
        {
            if (a1 != ' ')
            {
                printf("This cell is full.\n");
                turn --;
                continue;
            }

            a1 = symbol;
        }
        else if (cell_number == 2)
        {
            if (a2 != ' ')
            {
                printf("This cell is full.\n");
                turn --;
                continue;
            }
            a2 = symbol;
        }
        else if (cell_number == 3)
        {
            if (a3 != ' ')
            {
                printf("This cell is full.\n");
                turn --;
                continue;
            }
            a3 = symbol;
        }
        else if (cell_number == 4)
        {
            if (b1 != ' ')
            {
                printf("This cell is full.\n");
                turn --;
                continue;
            }
            b1 = symbol;
        }
        else if (cell_number == 5)
        {
            if (b2 != ' ')
            {
                printf("This cell is full.\n");
                turn --;
                continue;
            }
            b2 = symbol;
        }
        else if (cell_number == 6)
        {
            if (b3 != ' ')
            {
                printf("This cell is full.\n");
                turn --;
                continue;
            }
            b3 = symbol;
        }
        else if (cell_number == 7)
        {
            if (c1 != ' ')
            {
                printf("This cell is full.\n");
                turn --;
                continue;
            }
            c1 = symbol;
        }
        else if (cell_number == 8)
        {
            if (c2 != ' ')
            {
                printf("This cell is full.\n");
                turn --;
                continue;
            }
            c2 = symbol;
        }
        else if (cell_number == 9)
        {
            if (c3 != ' ')
            {
                printf("This cell is full.\n");
                turn --;
                continue;
            }
            c3 = symbol;
        }

        printf("[%c][%c][%c]\n", a1, a2, a3);
        printf("[%c][%c][%c]\n", b1, b2, b3);
        printf("[%c][%c][%c]\n", c1, c2, c3);

        if(a1 == a2 && a2== a3 && a2 == symbol )
        {
            printf("The player with %c wins", symbol);
            break;
        }
        if(b1 == b2 && b2== b3 && b2 == symbol )
        {
            printf("The player with %c wins", symbol);
            break;
        }
        if(c1 == c2 && c2== c3 && c2 == symbol )
        {
            printf("The player with %c wins", symbol);
            break;
        }
        if(a1 == b1 && b1 == c1 && b1 == symbol )
        {
            printf("The player with %c wins", symbol);
            break;
        }
        if(a2 == b2 && b2 == c2 && b2 == symbol )
        {
            printf("The player with %c wins", symbol);
            break;
        }
        if(a3 == b3 && b3 == c3 && b3 == symbol)
        {
            printf("The player with %c wins", symbol);
            break;
        }
        if(a1 == b2 && b2 == c3 && b2 == symbol )
        {
            printf("The player with %c wins", symbol);
            break;
        }
        if(a3 == b2 && b2 == c1 && b2 == symbol )
        {
            printf("The player with %c wins", symbol);
            break;
        }
    }

    return 0;
}