#include <stdio.h>

bool ishex(char ch) {
    return ((ch >= '0') && (ch <='9')) || ((ch >= 'a') && (ch <= 'f')) || ((ch >= 'A') && (ch <= 'F')) ? true:false;
}

int main(void) {
   // 9 Количество шестнадцатеричных цифр (0-9, a-f, A-F)
    char cha;
    int counter = 0;

    while ((cha = getchar()) != EOF)
        if (ishex(cha)) counter++;

    printf("total:%d\n",counter);
    return 0;
}