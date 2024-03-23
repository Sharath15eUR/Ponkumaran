#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 12345
#define BUFFER_SIZE 1024

// Function to check if a string is palindrome
int isPalindrome(char *str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        if (str[i] != str[length - i - 1]) {
            return 0; // Not a palindrome
        }
    }
    return 1; // Palindrome
}

int main() {
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE] = {0};

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Prepare the sockaddr_in structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket to localhost port 12345
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 1) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening for connections...\n");

    // Accept a connection from client
    int client_addr_len = sizeof(client_addr);
    if ((client_fd = accept(server_fd, (struct sockaddr *)&client_addr, (socklen_t *)&client_addr_len)) < 0) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }

    printf("Connection established with client\n");

    // Receive string from client
    int valread;
    if ((valread = recv(client_fd, buffer, BUFFER_SIZE, 0)) == -1) {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }
    printf("Received string from client: %s\n", buffer);

    // Check if received string is palindrome
    if (isPalindrome(buffer)) {
        char *palindrome_message = "Palindrome";
        send(client_fd, palindrome_message, strlen(palindrome_message), 0);
    } else {
        char *not_palindrome_message = "Not a Palindrome";
        send(client_fd, not_palindrome_message, strlen(not_palindrome_message), 0);
    }

    // Close the connection
    close(client_fd);
    close(server_fd);

    return 0;
}
