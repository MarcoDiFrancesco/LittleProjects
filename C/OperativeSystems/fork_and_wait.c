#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

int rand_int(int min, int max) {
    srand(time(NULL) + getpid());
    int range = max - min + 1;
    int r = rand() % range;
    return r + min;
}

int delay(double delay) {
    time_t start = time(NULL);
    time_t current;
    do {
        time(&current);
    } while(difftime(current, start) < delay);
    return delay;
}

int main() {
    int f = fork();
    if (f == -1) {
        printf("Error in creating fork\n");
        return 1;
    }
    printf("Forked, pid=%d, ppid=%d\n", getpid(), getppid());
    delay(2);
    
    // Parent
    if (f > 0) {
        int d = delay(rand_int(1,2));
        printf("I'm the parent, waited for %d, pid=%d, child=%d\n", d, getpid(), f);
        // Wait for a process (the first that comes)
        wait(NULL);
        printf("Waited, now ending\n");
    } else { // Child
        int d = delay(rand_int(3,4));
        printf("I'm the child, waited for %d, pid=%d, parent=%d\n", d, getpid(), getppid());
    }
}
