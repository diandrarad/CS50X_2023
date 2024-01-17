#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_valid_credit_card(const char *card_number);

int main()
{
    char card_number[20];
    printf("Enter credit card number: ");
    scanf("%s", card_number);

    if (is_valid_credit_card(card_number))
    {
        if (strncmp(card_number, "34", 2) == 0 || strncmp(card_number, "37", 2) == 0)
        {
            printf("American Express\n");
        }
        else if (strncmp(card_number, "51", 2) == 0 || strncmp(card_number, "52", 2) == 0 ||
                 strncmp(card_number, "53", 2) == 0 || strncmp(card_number, "54", 2) == 0 ||
                 strncmp(card_number, "55", 2) == 0)
        {
            printf("Mastercard\n");
        }
        else if (strncmp(card_number, "4", 1) == 0)
        {
            printf("Visa\n");
        }
        else
        {
            printf("Invalid\n");
        }
    }
    else
    {
        printf("Invalid\n");
    }

    return 0;
}

bool is_valid_credit_card(const char *card_number)
{
    int len = strlen(card_number);
    int sum = 0;
    bool double_digit = false;

    for (int i = len - 1; i >= 0; i--)
    {
        int digit = card_number[i] - '0';
        if (double_digit)
        {
            digit *= 2;
            if (digit > 9)
            {
                digit -= 9;
            }
        }
        sum += digit;
        double_digit = !double_digit;
    }

    return (sum % 10 == 0);
}