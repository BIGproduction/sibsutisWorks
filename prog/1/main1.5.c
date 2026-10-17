#include <stdio.h>

int main() {
    int reactor_core = 12;

    int some1 = reactor_core * 2;
    int some2 = reactor_core * reactor_core;

    printf("[");

    printf("%d, ", reactor_core);
    printf("%d, ", some1);
    printf("%d", some2);

    printf("]\n");

    return 0;
}
