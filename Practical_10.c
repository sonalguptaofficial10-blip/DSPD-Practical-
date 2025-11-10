#include <stdio.h>
#include <stdlib.h>

int main() {
    char inputFile[100], outputFile[100];
    FILE *src, *dest;
    char ch;

    
    printf("Enter the name of the input file: ");
    scanf("%s", inputFile);

    printf("Enter the name of the output file: ");
    scanf("%s", outputFile);

    
    src = fopen(inputFile, "r");
    if (src == NULL) {
        printf("Error: Cannot open input file %s\n", inputFile);
        exit(1);
    }

    
    dest = fopen(outputFile, "w");
    if (dest == NULL) {
        printf("Error: Cannot create output file %s\n", outputFile);
        fclose(src);
        exit(1);
    }

    // Copy contents character by character
    while ((ch = fgetc(src)) != EOF) {
        fputc(ch, dest);
    }

    printf("File copied successfully from %s to %s.\n", inputFile, outputFile);

    // Close both files
    fclose(src);
    fclose(dest);

    return 0;
}
