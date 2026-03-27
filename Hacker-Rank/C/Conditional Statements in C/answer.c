#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();



#include <stdio.h>

int main() {

    int number;

    scanf("%d", &number);

    if (number > 9) printf("Greater than 9\n");
    else if (number == 1) printf("one\n");
    else if (number == 2) printf("two\n");
    else if (number == 3) printf("three\n");
    else if (number == 4) printf("four\n");
    else if (number == 5) printf("five\n");
    else if (number == 6) printf("six\n");
    else if (number == 7) printf("seven\n");
    else if (number == 8) printf("eight\n");
    else if (number == 9) printf("nine\n");

    return 0;
}
char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}
