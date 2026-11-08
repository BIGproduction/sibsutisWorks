#include <stdio.h>
 
int main(void)
{
    int x = 10;
    int *p;
    p = &x;
    printf("%p \n", p);     // 0060FEA8
    return 0;
}