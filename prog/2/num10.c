#include <stdio.h>
#include <stdint.h>

int main() {
    int packet_id;
    unsigned int temp_status;
    float voltage;

    printf("Введите ID (hex), статус (octal) и напряжение: ");
    scanf("%x %o %f", &packet_id, &temp_status, &voltage);

    uint8_t status_code = (uint8_t)temp_status;

    uint16_t checksum = (uint16_t)packet_id + (uint16_t)status_code;

    printf("PACKET_ID: %d\n", packet_id);
    printf("STATUS_CODE: %d\n", status_code);
    printf("STATUS_CHAR: %c\n", status_code);
    printf("VOLTAGE: %.2f\n", voltage);
    printf("CHECKSUM: %d\n", checksum);

    return 0;
}