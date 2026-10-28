#include <stdio.h>
#include <math.h>

#define N 100
#define PI 3.14159265

int main() {
    int i, j;
    double x;
    int position;

    for (i = 0; i <= N; i++) {
        x = sin(2 * PI * 5 * i / N);
        position = (int)((x + 1) * 20);

        printf("%3d |", i);

        for (j = 0; j <= 40; j++) {
            printf("%c", "                                        *"[j == position]);
        }

        printf("\n");
    }

    return 0;
}