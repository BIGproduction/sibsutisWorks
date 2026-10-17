#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>

int main(void) {
    setlocale(LC_ALL, "");

    const char a[] = "Сбой матрицы";
    const wchar_t b[] = L"Сбой матрицы";

    printf("char -> sizeof: %ld bytes, strlen: %ld chars \n wchar -> sizeof: %ld bytes, wslen: %ld chars\n", sizeof(a), strlen(a), sizeof(b), wcslen(b));

    return 0;
}