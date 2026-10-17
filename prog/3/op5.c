#include <stdio.h>
#include <ctype.h>

int main(void) {
    char a = '0';

    if (scanf("%c", &a) != 1) {
        return -1;
    }

    printf("CODE_DEC: %d\n CODE_HEX: %x\n CODE_OCT: %o\n UPPER: %c\n NEXT: %c\n PREV: %c\n", a, a, a, toupper(a), a+1, a-1);

    return 0;
}