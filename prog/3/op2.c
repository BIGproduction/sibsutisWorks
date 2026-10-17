#include<string.h>
#include<stdio.h>

int main(void) {
    char word1[15];
    char word2[15];

    scanf("%s %s", word1, word2);
    printf("%s-%s\n", word1, word2);
    size_t total_len = strlen(word1) + strlen(word2);

    printf("TOTAL_LEN: %zu\n", total_len);

    return 0;
}