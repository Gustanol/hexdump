#include "hexdump.h"
#include <ctype.h>
#include <stdint.h>
#include <stdio.h>

int read_file(const char *path, const char *mode) {
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
     *
     * the array is declared as a char type because 1 char = 1 byte and, in some cases, unsigned for
     * default
     *
     * int8_t defines a byte as well but in a range of -127 and 127
     */
    unsigned char buffer[16];

    file = fopen(path, mode);
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }

    /*
     * while loop that will iterate as long as there are lines
     *
     * `read` varible represents the amount of bytes read succesfully
     *
     * `offset` represents the current index of bytes (in hexadecimal)
     */
    unsigned int offset = 0x0;
    int read = fread(buffer, 1, 16, file);
    while (read > 0) {
        printf("%.8x: ", offset);

        /*
         * loop to print each hexadecimal value stored in buffer array
         */
        for (int i = 0; i < read; i++) {
            printf("%.2x ", buffer[i]);
        }

        /*
         * loop to convert each hexadecimal value in an ASCII character, if available
         */
        printf(" ");
        for (int i = 0; i < read; i++) {
            if (isprint(buffer[i])) {
                printf("%c", buffer[i]);
            } else {
                printf(".");
            }
        }
        printf("\n");
        offset += read;
        read = fread(buffer, 1, 16, file);
    }
    fclose(file);
    return 0;
}
