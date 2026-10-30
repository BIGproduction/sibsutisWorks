#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846
#define PERIODS 5
#define SAMPLES_PER_PERIOD 20

int main(void) {
    int total_samples = PERIODS * SAMPLES_PER_PERIOD;

    for (int i = 0; i <= total_samples; i++) {

        double x = 2.0 * PI * i / SAMPLES_PER_PERIOD;
        double y = sin(x);

        int position = (int)((y + 1.0) * 20 + 0.5);

        printf("%3d | ", i);

        for (int j = 0; j <= 40; j++) {

            putchar(j == position ? '*' : (j == 20 ? '|' : ' '));
        }
        printf("\n");
    }
    return 0;
}