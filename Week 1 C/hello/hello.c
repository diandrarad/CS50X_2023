#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt the user to input their name
    string answer = get_string("what's your name? ");

    // Print a greeting with the user's name
    printf("hello, %s\n", answer);
}