#include <stdio.h>

int main() {
    FILE *fp;
    char data[100];
    
    fp = fopen("data.bin", "rb");
    
    if (fp == NULL) {
        printf("Error opening file.");
        return 1;
    }
    
    fread(data, sizeof(char), 100, fp);
    printf("%s", data);
    
    fclose(fp);
    
    return 0;
}



