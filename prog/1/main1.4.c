#include <stdio.h>

int main() {
    int year;
    int days_per_year;
    int total_days;

    year = 3;
    days_per_year = 365;

    total_days = year * days_per_year;

    printf("year = %d\n" , year);
    printf("days_per_year = %d\n" , days_per_year);
    printf("total_days = %d\n" , total_days);

    return 0;
}