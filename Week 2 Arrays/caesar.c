#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int only_digits(int key, int argc);
char rotate(char c, int key);

int main(int argc, char *argv[])
{
    cdint key = atoi(argv[1]);

    if(only_digits(key, argc))
    {
        return 1;
    }

    string plaintext = get_string("plaintext:  ");
    int len = strlen(plaintext);
    char *ciphertext = malloc(len + 1);

    for (int i = 0; i < len; i++)
    {
        if (isalpha(plaintext[i]))
        {
            char c = rotate(plaintext[i], key);
            strncat(ciphertext, &c, 1);
        }
        else
        {
            strncat(ciphertext, &plaintext[i], 1);
        }
    }

    printf("ciphertext: %s\n", ciphertext);

    free(ciphertext);
    return 0;
}

int only_digits(int key, int argc)
{
    if(key <= 0 || argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    return 0;
}

char rotate(char c, int key)
{
    if(islower(c))
    {
        return 'a' + (c - 'a' + key) % 26;
    }
    return 'A' + (c - 'A' + key) % 26;
}