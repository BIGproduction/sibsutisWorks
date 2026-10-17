#include <stdio.h>

int main() {
    int unit_id;
    int unit_version;
    int unit_status;
    int sum;

    scanf("%d %x %o", &unit_id, &unit_version, &unit_status);

    sum = unit_id + unit_version + unit_status;

    printf("UNIT_ID: %d\n", unit_id);
    printf("UNIT_VERSION: %d\n", unit_version);
    printf("UNIT_STATUS: %d\n", unit_status);
    printf("SUM: %d\n", sum);

    return 0;
}