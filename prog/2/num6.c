#include <stdio.h>
#include <stdint.h>

int main() {
    int input;
    if (scanf("%d", &input) != 1) return 1;

    uint8_t var = input;

    uint8_t add = var + 10;
    uint8_t mul2 = var * 2;
    uint8_t sqr = var * var;

    printf("ADD: %u\n", (unsigned int)add);
    printf("MUL2: %u\n", (unsigned int)mul2);
    printf("SQR: %u\n", (unsigned int)sqr);

    return 0;
}