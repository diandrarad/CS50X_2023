#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    if (strlen(input) == 1)  // base case
    {
        return input[0] - '0';  // convert last char to integer
    }
    else  // recursive case
    {
        char last = input[strlen(input) - 1];  // get last char
        input[strlen(input) - 1] = '\0';  // remove last char from string
        int remaining = convert(input);  // recursively convert remaining string
        return remaining * 10 + (last - '0');  // add last digit to result
    }
}