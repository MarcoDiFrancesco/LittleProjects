#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main() {
    printf("Running ls -l");
    // Check for possible errors
    if (system("ls -l; sleep 2s") == -1) {
        printf("Error %d\n", errno);
    }
    return 0;
}
