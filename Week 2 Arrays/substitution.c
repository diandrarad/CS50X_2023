#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char substitute(char c, const char *key);

int main(int argc, char *argv[])
{
    if (argc != 2 || strlen(argv[1]) != 26)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }
        for (int j = i + 1; j < 26; j++)
        {
            if (toupper(argv[1][i]) == toupper(argv[1][j]))
            {
                printf("Key must not contain repeated characters.\n");
                return 1;
            }
        }
    }

    // Get plaintext from user
    printf("plaintext: ");
    char plaintext[100];
    fgets(plaintext, 100, stdin);

    // Substitute plaintext
    int plaintext_length = strlen(plaintext);
    char ciphertext[plaintext_length];
    for (int i = 0; i < plaintext_length; i++)
    {
        ciphertext[i] = substitute(plaintext[i], argv[1]);
    }
    ciphertext[plaintext_length] = '\0';

    // Print ciphertext
    printf("ciphertext: %s", ciphertext);

    return 0;
}

char substitute(char c, const char *key)
{
    if (isupper(c))
    {
        return toupper(key[c - 'A']);
    }
    else if (islower(c))
    {
        return tolower(key[c - 'a']);
    }
    return c;
}