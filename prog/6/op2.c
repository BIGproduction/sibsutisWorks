#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");

    wint_t ch;
    int count = 0;
    int state = 0;

    wprintf(L"введите текст:\n");

    while ((ch = getwchar()) != L'#' && ch != WEOF) {
        
        switch (state) {
            case 0:
                if (ch == L'е') {
                    state = 1;
                }
                break;
            case 1:
                if (ch == L'й') {
                    count++;
                    state = 0;
                } else if (ch == L'е') {
                    state = 1;
                } else {
                    state = 0;
                }
                break;
        }
    }
    wprintf(L"количество вхождений последовательности L\"ей\": %d\n", count);

    return 0;
}