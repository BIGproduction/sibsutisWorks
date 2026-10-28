#include <stdio.h>

int main() {
    const int HEIGHT = 5; 
    int spaces[] = {0, 4, 8, 4, 0}; 

    for (int i = 0; i < HEIGHT; i++) {
        
        for (int j = 0; j < spaces[i]; j++) {
            printf(" ");
        }
        printf("*\n");
    }

    return 0;
}