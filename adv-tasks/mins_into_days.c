#include <stdio.h>
int main()
{
   int minutesTotal;
   printf("Please enter total minutes : ");
   scanf("%d", &minutesTotal);

   while (minutesTotal < 1)
   {
      printf("Invalide input for minutes");
      printf("Please enter total minutes again : ");
      scanf("%d", &minutesTotal);
   }

   int hoursTotal = minutesTotal / 60;
   int days = hoursTotal / 24;
   int hours = hoursTotal - days * 24;
   int minutes = (minutesTotal - hours * 60 - days * 24 * 60);

   char daysLabel[5] = {'d', 'a', 'y', 's', '\0'};
   if (days == 1)
   {
      daysLabel[3] = '\0';
   }

   char *hoursLabel;
   if (hours == 1)
   {
      hoursLabel = "hour";
   }
   else
   {
      hoursLabel = "hours";
   }

   char *minutesLabel;
   if (minutes == 1)
   {
      minutesLabel = "minute";
   }
   else
   {
      minutesLabel = "minutes";
   }

   printf("%d minutes are %d %s, %d %s, %d %s.", minutesTotal, days, daysLabel, hours, hoursLabel, minutes, minutesLabel);
   return 0;
}
