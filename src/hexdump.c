#include "hexdump.h"
#include <ctype.h>
#include <stdint.h>
#include <stdio.h>

void read_file(const char *path, const char *mode) {
    /*
     * pointer that will represent file will be open
     *
     * note that `FILE` data type has exactly this function
     */
    FILE *file;

    /*
     * array that will store read bytes
     *
     * note that it just have 16 spaces because each line of a binary file has
     * 16 bytes (at last)
     */
    int16_t buffer[16];

    file = fopen(path, mode);
    if (file == NULL) {
        perror("Error opening file");
    }

    /*
     * while loop that will iterate as long as there are lines
     *
     * `read` varible represents the amount of bytes read succesfully
     *
     * `offset` represents the current index of bytes
     * note that its icrease value it's 16
     */
    int read = fread(buffer, 1, 16, file);
    unsigned int offset = 0x00000000;
    while (read > 0) {
        read = fread(buffer, 1, 16, file);
        printf("%x  ", offset);
        for (int i = 0; i < read; i++) {
            printf("%x ", buffer[i]);
        }

        for (int i = 0; i < read; i++) {
            if (isprint(buffer[i])) {
                printf("%c", buffer[i]);
            } else {
                printf(".");
            }
        }
    }
}
