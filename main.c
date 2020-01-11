#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>

#include "constants.h"

// Functions
void setupServer();

// Global variables
int socket_descriptor;
struct sockaddr_in server;

int main(int argc, char *argv[]) {
    pthread_t server_thread, draw_thread;

    //Creates socket
    setupServer();

    //Connects to the server
    if (connect(socket_descriptor, (struct sockaddr *) &server, sizeof(server)) < 0) {
        puts("Connection Error");
        return 1;
    } else {
        puts("Connected");
    }

    return 0;
}

void setupServer() {
    socket_descriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_descriptor == -1) {
        printf("Could not create socket");
    }

    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
}
