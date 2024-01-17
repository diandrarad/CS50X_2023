#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt the user for the height of the pyramid and ensure it's between 1 and 8
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Build the pyramid
    for (int i = 0; i < height; i++)
    {
        // Print the spaces on the left side of the pyramid
        for (int j = height - i - 1; j > 0; j--)
        {
            printf(" ");
        }

        // Print the left half of the pyramid
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }

        // Print the gap between the two halves of the pyramid
        printf("  ");

        // Print the right half of the pyramid
        for (int l = 0; l <= i; l++)
        {
            printf("#");
        }

        // Move to the next line for the next row of the pyramid
        printf("\n");
    }
}