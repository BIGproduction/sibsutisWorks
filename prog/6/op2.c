#include <stdio.h>

int main() {
    const int HEIGHT = 5;
    const int TIERS = 3;

    for (int tier = 0; tier < TIERS; tier++) {
        
        for (int i = 0; i < HEIGHT; i++) {
            
            for (int j = 0; j < HEIGHT - 1 - i; j++) {
                printf(" ");
            }
            
            for (int k = 0; k < (2 * i + 1); k++) {
                printf("*");
            }
            printf("\n");
        }
    }
    return 0;
}