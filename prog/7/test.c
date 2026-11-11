#include <stdio.h>

int main() {
    int num1 = (111260500 % 30) + 1;
    int num2 = ((111260500 + (0 + 6))% 30) + 1;
    int num3 = ((111260500 + (0 + 12))% 30) + 1;
    int num4 = ((111260500 + (0 + 18))% 30) + 1;
    int num5 = ((111260500 + (0 + 22))% 30) + 1;
    printf("%d %d %d %d %d", num1, num2, num3, num4, num5);
}