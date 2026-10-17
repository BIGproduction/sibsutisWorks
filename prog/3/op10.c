#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main(void) {
    setlocale(LC_ALL, "");

    wchar_t a[23];
    wchar_t b[23];
    wchar_t c[23];

    if (wscanf(L"%ls %ls %ls", &a, &b, &c) != 3) {
        return -1;
    }

    wprintf(L"%-15ls|%20ls|%.5ls\n", a, b, c);

    return 0;
}