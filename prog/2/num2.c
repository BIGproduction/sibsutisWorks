#include <stdio.h>
#include <stdbool.h>

int main() {
    int num1, num2;

    scanf("%d %d", &num1, &num2);

    bool module_ready = num1;
    bool fault_state = num2;

    printf("MODULE_READY: %d\n", module_ready);
    printf("FAULT_STATE: %d\n", fault_state);

    printf("BOOL_SIZE: %zu\n", sizeof(bool));

    int flags_sum = module_ready + fault_state;

    printf("FLAGS_SUM: %d\n", flags_sum);

    return 0;
}