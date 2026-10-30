#include <stdio.h>

int main() {
    double A = 0.0;
    double B = 5.0;
    double H = 1.0;
    
    double x;
    double y;
    int iteration = 1;

    printf("Показательная функция 2^x \n");

    for (x = A; x <= B + H / 2.0; x += H) {

        printf("%8d | %5.4f | %10.4f \n", iteration, x, y);

        y *= 2.0;
        iteration++;
    }
    return 0;
}