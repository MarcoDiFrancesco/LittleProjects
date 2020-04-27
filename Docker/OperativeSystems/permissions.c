#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFF_SIZE 255

int main() {
    int fd, size = 1;
    char buffer[BUFF_SIZE];
    fd = open("README.md", O_RDONLY);
    // Check if error occured
    if (fd == -1) {
        // Error
        exit(2);
    }

    while (size > 0) {
        size = read(fd, buffer, BUFF_SIZE-1);
        if (size == -1) {
            close(fd);
            exit(3);
        }
        if (size > 0) {
            buffer[size] = '\0';
            printf("%s", buffer);
        }
        
    }
    // Ask kernel to read in fd and save to buffer 50 chars
    // read returns the amount ofread bytes
    
    
    close(fd);
    return 0;
}