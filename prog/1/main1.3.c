#include <stdio.h>
#include <string.h>

int main() {
    char name[] = "Valentine";
    char group[] = "IV-622";
    char hostname[] = "big";

    int len_name = (int)strlen(name);
    int len_group = (int)strlen(group);
    int len_hostname = (int)strlen(hostname);

    int some = len_name;
    int sum = len_group + len_hostname;

    printf("%s\t{%d}\n%s\t%s\t{%d}\n",
           name, some,
           group, hostname, sum);
    return 0;
}
