#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulbs(string message);

int main(void)
{
    // TODO
    // Get message from user
    string message = get_string("Message: ");

    // Get length of message
    int len = strlen(message);

    // Call print_bulbs function to print the message in binary
    print_bulbs(message);
}

void print_bulbs(string message)
{
    // Loop through each character in the message
    for (int i = 0; i < strlen(message); i++)
    {
        // Get the decimal value of the character
        int decimal = message[i];

        // Loop through each bit in the character, from left to right
        for (int j = 7; j >= 0; j--)
        {
            // If the jth bit in the decimal value is 1, print a lit bulb
            if (decimal & (1 << j))
            {
                printf("\U0001F7E1");
            }
            // If the jth bit in the decimal value is 0, print an unlit bulb
            else
            {
                printf("\U000026AB");
            }
        }

        // Print a new line after each character
        printf("\n");
    }
}
