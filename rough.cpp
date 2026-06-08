// Basic echo protocol - server
// Client and Server on the same host

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    // Create socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(server_fd < 0){
        perror("Socket failed"); // C standard library function used to print a human-readable error message that explains why the last system/library call failed. Some additional information based on errno, set by system calls and some library functions in the event of an error to indicate what went wrong.
        exit(EXIT_FAILURE);
    }

    // Prepare the sockaddr_in structure to store address information
        
    struct sockaddr_in server_addr; // structure to hold an internet address. It contains a family (AF_INET for IPv4), a port number, and an IP address.
    memset(&server_addr, 0, sizeof(server_addr)); // Initialize the structure to zero to avoid garbage values
    server_addr.sin_family = AF_INET; // Address family - AF_INET for IPv4
    server_addr.sin_addr.s_addr = INADDR_ANY; // Accept connections from any IP address
    server_addr.sin_port = htons(PORT); /* Host TO Network Short - converts the unsigned short integer hostshort from host byte order to network byte order. Different CPU architectures store multi-byte numbers differently:
        - Little-endian (x86, ARM): least-significant byte first
        - Big-endian (some older CPUs): most-significant byte first

    Network byte order is always big-endian, no matter what machine you’re on.
    
    So before sending numbers like port numbers over the network, we must convert them.
    
    It can be used safely on all systems.
    */
    
    // Bind the socket to the specified IP and port
    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_fd, 3) < 0) { // second argument is the maximum number of pending connection requests allowed
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Echo server listening on port %d...\n", PORT);

    // Accept and handle client connections
    struct sockaddr_in client_addr;
    socklen_t addr_len = sizeof(client_addr);
    int client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &addr_len); // Accept a connection from a client and return a new socket file descriptor for communication with the client. server_fd is the listening socket for incoming connections.

    if(client_fd < 0){
        perror("Accept failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Client connected.\n");

    // Echo loop
    char buffer[BUFFER_SIZE] = {0};
    int bytes_read;
    while ((bytes_read = read(client_fd, buffer, BUFFER_SIZE)) > 0) {
        write(client_fd, buffer, bytes_read); // echo back
        printf("Message from client: %s\n", buffer);
    }

    printf("Client disconnected.\n");

    // Clean up
    close(client_fd);
    close(server_fd);

    return 0;
}
