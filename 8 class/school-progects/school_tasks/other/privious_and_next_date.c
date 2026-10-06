#include <stdio.h>

int main()
{
    int day, month, year;
    int is_leap;
    int nextDay, nextMonth, nextYear;
    int privDay, privMonth, PrivYear;

    printf("Day : ");
    scanf("%d", &day);
    printf("Month : ");
    scanf("%d", &month);
    printf("Year : ");
    scanf("%d", &year);

    is_leap = 0;
    if (year % 4 == 0)
    {
        if (year % 100 != 0)
            is_leap = 1;
        else if (year % 400 == 0)
            is_leap = 1;
    }

    int days_in_month;

    while (month < 1 || month > 12)
    {
        printf("Invalid month. Month : ");
        scanf("%d", &month);
    }
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        days_in_month = 31;
        break;
    case 2:
        days_in_month = 28;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        days_in_month = 30;
        break;
    }

    if (is_leap && month == 2)
    {
        days_in_month = 29;
    }

    while (day > days_in_month || day < 1)
    {
        printf("Invalid day. Day : ");
        scanf("%d", &day);
        switch (month)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            days_in_month = 31;
            break;
        case 2:
            days_in_month = 28;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            days_in_month = 30;
            break;
        }

        if (is_leap && month == 2)
        {
            days_in_month = 29;
        }
    }

    nextDay = day + 1;
    if (nextDay > days_in_month)
    {
        nextDay = 1;
        nextMonth = month + 1;
        if (nextMonth > 12)
        {
            nextMonth = 1;
            nextYear = year + 1;
        }
        else 
        {
            nextYear = year;
        }
    }
    else
    {
        nextMonth = month;
        nextYear = year;
    }

    privDay = day - 1;
    if (privDay < 1)
    {
        privMonth = month - 1;
        int priv_days_in_month;
        switch (privMonth)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            priv_days_in_month = 31;
            break;
        case 2:
            priv_days_in_month = 28;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            priv_days_in_month = 30;
            break;
        }
        privDay = priv_days_in_month;
        if (privMonth < 1)
        {
            PrivYear = year - 1;
            privMonth = 12;
            priv_days_in_month = 31;
        }
        else
        {
            PrivYear = year;
            
        }
    }
    else
    {
        privMonth = month;
        PrivYear = year;
    }

    printf("Priveous date is : %d.%d.%d\n", privDay, privMonth, PrivYear);
    printf("Currunt date is : %d.%d.%d\n", day, month, year);
    printf("Next date is : %d.%d.%d\n", nextDay, nextMonth, nextYear);
    return 0;
}