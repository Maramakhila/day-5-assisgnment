#include <stdio.h>
#include <string.h>

int main() {
    FILE *input_file, *output_file, *error_file;
    char line[100];

    // open input file for reading
    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    // open output file for writing
    output_file = fopen("error_log.txt", "w");
    if (output_file == NULL) {
        printf("Error: could not open output file.\n");
        return 1;
    }

    // iterate over each line in the input file
    while (fgets(line, sizeof(line), input_file)) {
        // check if the line contains the word "error"
        if (strstr(line, "error") != NULL) {
            // write the line to the output file
            fputs(line, output_file);
        }
    }

    // close input and output files
    fclose(input_file);
    fclose(output_file);

    // open error log file for reading
    error_file = fopen("error_log.txt", "r");
    if (error_file == NULL) {
        printf("Error: could not open error log file.\n");
        return 1;
    }

    // print contents of error log file to console
    while (fgets(line, sizeof(line), error_file)) {
        printf("%s", line);
    }

    // close error log file
    fclose(error_file);

    return 0;
}

