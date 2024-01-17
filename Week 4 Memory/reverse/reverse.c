#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 3)
    {
        fprintf(stderr, "Usage: ./reverse input.wav output.wav\n");
        return 1;
    }

    // Open input file for reading
    FILE *input = fopen(argv[1], "rb");
    if (input == NULL)
    {
        fprintf(stderr, "Could not open %s for reading.\n", argv[1]);
        return 2;
    }

    // Read header
    WAVHEADER header;
    fread(&header, sizeof(WAVHEADER), 1, input);

    // Use check_format to ensure WAV format
    if (!check_format(header))
    {
        fprintf(stderr, "File %s is not in WAV format.\n", argv[1]);
        fclose(input);
        return 3;
    }

    // Open output file for writing
    FILE *output = fopen(argv[2], "wb");
    if (output == NULL)
    {
        fprintf(stderr, "Could not create %s for writing.\n", argv[2]);
        fclose(input);
        return 4;
    }

    // Write header to file
    fwrite(&header, sizeof(WAVHEADER), 1, output);

    // Use get_block_size to calculate size of block
    int block_size = get_block_size(header);

    if (fseek(input, block_size, SEEK_END))
    {
        return 1;
    }

    BYTE buffer[block_size];
    while (ftell(input) - block_size > sizeof(header))
    {
        if (fseek(input, - 2 * block_size, SEEK_CUR))
        {
            return 1;
        }
        fread(buffer, block_size, 1, input);
        fwrite(buffer, block_size, 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);

    return 0;
}

int check_format(WAVHEADER header)
{
    // Check if the file is in the WAV format
    if (header.chunkID[0] != 'R' || header.chunkID[1] != 'I' ||
        header.chunkID[2] != 'F' || header.chunkID[3] != 'F') {
        return 0;
    }
    if (header.format[0] != 'W' || header.format[1] != 'A' ||
        header.format[2] != 'V' || header.format[3] != 'E') {
        return 0;
    }
    if (header.subchunk1ID[0] != 'f' || header.subchunk1ID[1] != 'm' ||
        header.subchunk1ID[2] != 't' || header.subchunk1ID[3] != ' ') {
        return 0;
    }
    if (header.subchunk2ID[0] != 'd' || header.subchunk2ID[1] != 'a' ||
        header.subchunk2ID[2] != 't' || header.subchunk2ID[3] != 'a') {
        return 0;
    }
    return 1;
}

int get_block_size(WAVHEADER header)
{
    // Calculate the size of a single audio block in bytes
    return header.numChannels * header.bitsPerSample / 8;
}