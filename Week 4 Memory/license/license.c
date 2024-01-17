#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./read infile\n");
        return 1;
    }

    char buffer[7];
    char *plates[8];

    FILE *infile = fopen(argv[1], "r");

    int idx = 0;
    while (fread(buffer, 1, 7, infile) == 7 && idx < 8)
    {
        buffer[6] = '\0';
        plates[idx] = malloc(strlen(buffer) + 1);
        strcpy(plates[idx], buffer);
        idx++;
    }

    for (int i = 0; i < idx; i++)
    {
        printf("%s\n", plates[i]);
        free(plates[i]); // free memory allocated for each plate
    }
    
    fclose(infile);
    return 0;
}