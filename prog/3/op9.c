#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main(void) {
    setlocale(LC_ALL, "");

    wchar_t name[50];

    if (wscanf(L"%ls", &name) != 1) {
        return -1;
    }

    wprintf(L"Агент {%ls} авторизован в системе\n", name);

    return 0;
}