#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main(void) {
    char filename[1024];
    char search_string[1024];
    char line[MAX_LINE_LENGTH];
    FILE *file;

    printf("Enter the name of the file to search: ");
    scanf("%s", filename);
    printf("Enter the search string: ");
    scanf("%s", search_string);

    file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {

        if (strstr(line, search_string) != NULL) 

            printf("%s", line);
        }
    }
    fclose(file);

    return 0;
}
 
