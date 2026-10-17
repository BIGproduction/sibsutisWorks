#include <stdio.h>

int main(void) {
    char str[] = "";
    int width;

    if (scanf("%s %d", str, &width) != 2) {
        return -1;
    }

    printf("%*s\n", width, str);
    printf("%-*s\n", width + 5, str);

    return 0;
}