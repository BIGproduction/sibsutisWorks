#include <stdio.h>

#define Days_Per_Year 365
#define Hours_Per_Day 24
#define Seconds_Per_Hour 3600
#define Ticks_Per_Seconds 1

int main() {
    int years = 18;

    long long days = years * Days_Per_Year;
    long long hours = days * Hours_Per_Day;
    long long seconds = hours * Seconds_Per_Hour;
    long long ticks = seconds * Ticks_Per_Seconds;

    printf("Тики: %lld|Часы: %lld|Дни: %lld|Годы: %d\n",
           ticks,
           hours,
           days,
           years);

    return 0;
}