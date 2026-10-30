#include <stdio.h>
#include <math.h>

int main() {
    double A = 0.0;
    double B = 5.0;
    double H = 1.0;
    
    double x;

    printf("Показательная функция 2^x \n");

    for (x = A; x <= B + H / 2.0; x += H) {
        double y = pow(2.0, x);

        printf("%5.4f | %10.4f \n", x, y);
    }

    return 0;
}