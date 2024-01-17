#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    // Prompt user for input text
    string text = get_string("Text: ");

    // Initialize variables to track number of letters, words, and sentences
    int letters = 0, words = 1, sentences = 0;

    // Iterate over every character in the input text
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // If the character is alphabetic, increment the letters count
        if (isalpha(text[i]))
        {
            letters++;
        }
        // If the character is a space, increment the words count
        else if (isspace(text[i]))
        {
            words++;
        }
        // If the character is a period, exclamation point, or question mark, increment the sentences count
        else if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences++;
        }
    }

    // Calculate the average number of letters per 100 words and the average number of sentences per 100 words
    float L = (float) letters / words * 100;
    float S = (float) sentences / words * 100;

    // Compute the Coleman-Liau index rounded to the nearest integer
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // Output the reading level based on the computed index
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}
