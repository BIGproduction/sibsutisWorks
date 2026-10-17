#include <stdio.h>

#define Node_ID 42

void ping() {
    printf("PING");
}
void pong() {
    printf("PONG");
}
void handshake() {
    ping();
    printf("-");
    pong();
    printf("-");
    ping();
}

int main() {
    int packet_size = Node_ID * 4;
    int total_transfer = packet_size * 3;

    handshake();
    printf(":%d\n", packet_size);
    handshake();
    printf(":%d\n", total_transfer);
    printf("SESSION:CLOSED\n");

    return 0;
}