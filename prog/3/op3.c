#include <stdio.h>
#include <string.h>

int main(void) {
    char name[100];

    if (scanf("%s", name) != 1) {
        return -1;
    }

    printf("\"%s\"\n", name);
    printf("\"%20s\"\n", name);
    printf("\"%-20s\"\n", name);

    int some = (int)strlen(name) + 5;

    printf("\"%*s  %s  %-*s\"\n", some, "", name, some, "");

    return 0;
}