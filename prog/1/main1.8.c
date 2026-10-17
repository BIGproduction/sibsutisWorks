#include <stdio.h>

void pulse() {
    printf("@");
}

int main() {
    pulse();
    printf("\n");

    pulse();
    pulse();
    printf("\n");

    pulse();
    pulse();
    pulse();
    printf("\n");

    return 0;
}