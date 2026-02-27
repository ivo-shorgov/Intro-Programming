// 1
// Начин на изпълнение: Изразът се оценява веднъж.
// Стойността му се сравнява последователно с всяка case константа.
// При съвпадение се изпълняват операторите от съответния case до срещане на break (който прекъсва изпълнението на switch) или до края на блока.
// Ако няма съвпадение, се изпълнява блокът default (ако е наличен).
// Ако няма default и няма съвпадение, switch не прави нищо.
// Константите трябва да бъдат цели числа или символи.
// switch (променлива или символ)
// {
// case 'име на кейса':
//     /* code */
//     break;
// default:
//     break;
// }

// #include <stdio.h>

// int main()
// {
//     int day;
//     printf("Enter a number for the day (1-7): ");
//     scanf("%d", &day);
//     switch (day)
//     {
//     case 1:
//         printf("the day is Monday\n");
//         break;
//     case 2:
//         printf("the day is Tuesday\n");
//         break;
//     case 3:
//         printf("the day is Wednesday\n");
//         break;
//     case 4:
//         printf("the day is Thursday\n");
//         break;
//     case 5:
//         printf("the day is Friday\n");
//         break;
//     case 6:
//         printf("the day is Saturday\n");
//         break;
// //     case 7:
// //         printf("the day is Sunday\n");
// //         break;
// //     default:
// //         printf("Invalid day\n");
// //         break;
// //     }
// //     return 0;
// // }

// // 2
// #include <stdio.h>

// int main()
// {
//     int day, month;
//     printf("Enter a Day : ");
//     scanf("%d", &day);
//     printf("Enter a Month : ");
//     scanf("%d", &month);

//     if (month < 1 || month > 12 || day < 1 || day > 28 || day > 30 || day > 31)
//     {
//         printf("Invalid date\n");
//         return 1;
//     }

//     day++;
//     if (day > 28 || day > 30 || day > 31)
//     {
//         day = 1;
//         month++;
//         if (month > 12)
//         {
//             month = 1;
//         }
//     }

//     printf("%d.%d\n", day, month);

//     return 0;
// }

// 1. а/ Опишете синтаксиса и начина на изпълнение на оператор за многовариантен избор.
//     б/ Дайте пример за използването му:  въвежда се ден от седмицата като цяло число. Да се изведе името на съответния ден.
// 2. Задача: Въвежда се дата - ден и месец (цели числа) за 2026 год. Да се изведе следващата дата (ден и месец като цели числа).

#include <stdio.h>

int main()
{
    int day, month;
    printf("Enter a Day : ");
    scanf("%d", &day);
    printf("Enter a Month : ");
    scanf("%d", &month);
    if (month < 1 || month > 12)
    {
        printf("Invalid month\n");
        return 1;
    }

    int days_in_month;
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

    if (day < 1 || day > days_in_month)
    {
        printf("Invalid day\n");
        return 1;
    }

    day++;
    if (day > days_in_month)
    {
        day = 1;
        month++;
        if(month > 12)
        {
            month = 1;
        }
    }
    printf("%d.%d\n", day, month);

    return 0;
}