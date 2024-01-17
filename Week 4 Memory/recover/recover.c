#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BLOCK_SIZE 512
#define FILE_NAME_SIZE 8

int main(int argc, char *argv[])
{
    // Check if program was executed with one command-line argument
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s image\n", argv[0]);
        return 1;
    }

    // Open forensic image for reading
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        fprintf(stderr, "Could not open %s\n", argv[1]);
        return 1;
    }

    char *file_name = malloc(FILE_NAME_SIZE);
    if (file_name == NULL)
    {
        fclose(input);
        fprintf(stderr, "Could not allocate memory for file name\n");
        return 1;
    }

    uint8_t buffer[BLOCK_SIZE];
    int file_count = 0;
    FILE *output = NULL;

    while (fread(buffer, BLOCK_SIZE, 1, input))
    {
        // Check if block starts with JPEG signature
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Close previous output file (if any)
            if (output != NULL)
            {
                fclose(output);
            }

            // Generate file name for output file
            sprintf(file_name, "%03d.jpg", file_count);

            // Open output file for writing
            output = fopen(file_name, "w");
            if (output == NULL)
            {
                fclose(input);
                free(file_name);
                fprintf(stderr, "Could not create %s\n", file_name);
                return 1;
            }

            // Increment file count
            file_count++;
        }

        // Write block to output file (if any)
        if (output != NULL)
        {
            fwrite(buffer, BLOCK_SIZE, 1, output);
        }
    }

    // Close last output file (if any)
    if (output != NULL)
    {
        fclose(output);
    }

    free(file_name);
    fclose(input);
    return 0;
}