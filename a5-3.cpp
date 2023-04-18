#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

int main() {
    FILE *input_file, *output_file;
    char line[MAX_LINE_LENGTH];

    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, input_file) != NULL) {

        char *pos = line;
        while ((pos = strstr(pos, "red")) != NULL) {
            strncpy(pos, "blue", 4);
            pos += 4;
        }
        fprintf(output_file, "%s", line);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}

