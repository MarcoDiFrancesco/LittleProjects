#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int read_file, read_file2;
    // Reserve memory
    // (char *) is used to tell the system this is a char allocation
    char *txt = (char *)calloc(100, sizeof(char));
    read_file = open("processes.c", O_RDONLY);
    if (read_file < 0) {
        exit(1);
    }
    printf("%d\n", read_file);

    // Returns the amount of read chars
    // Write txt 10 chars, read from read_file
	while (read_file2 = read(read_file, txt, 10)) {
		if (read_file2 > 0) {
			// We need to write to the last char the EOF aka char \0 or int 0
			// So if there are 4 byts read the fifth (4) will be EOF
			txt[read_file2] = 0;
			printf("%s", txt);
		} else {
			break;
		}
	}

    close(read_file);
    return 0;
}
