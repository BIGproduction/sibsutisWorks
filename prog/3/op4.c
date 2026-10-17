#include <stdio.h>
#include <string.h>

/*
 * x48 - H
 * x65 - e
 * x6C - l
 * x6C - l
 * x6F - o
 * \t  - использование Tab
 * x57 - W
 * x6F - o
 * x72 - r
 * x6C - l
 * x64 - d
 */
int main(void) {
    char str[] = "\x48\x65\x6C\x6C\x6F\t\x57\x6F\x72\x6C\x64\n";
    
    int escape_len = (strlen(str) - 1);
    printf("%s\n STRLEN: %d\n SIZEOF: %ld", str, escape_len, sizeof(str));
    
    return 0;
}