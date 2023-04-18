#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    FILE *input_file, *output_file;
    char c;
    int counts[26] = {0};


    input_file = fopen("data.txt", "r");
    if (input_file == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    while ((c = fgetc(input_file)) != EOF) {
        if (isalpha(c)) {
            counts[tolower(c) - 'a']++;
        }
    }

    fclose(input_file);


    output_file = fopen("statistics.txt", "w");
    if (output_file == NULL) {
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }


    for (int i = 0; i < 26; i++) {
        fprintf(output_file, "%c: %d\n", 'a' + i, counts[i]);
    }

    fclose(output_file);

    return 0;
}


