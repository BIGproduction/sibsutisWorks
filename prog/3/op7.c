#include <stdio.h>
#include <string.h>
#define DISTRO "LinuxDistro"

int main(void) {
    const char r_date[] = "2026";

    printf("DISTRO: %s\n RDATE: %s\n STRLEN: %ld\n SIZEOF: %ld\n", DISTRO, r_date, strlen(DISTRO), sizeof(DISTRO));

    return 0;
}