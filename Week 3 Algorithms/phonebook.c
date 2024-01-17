#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    string name;
    string number;
}
person;

int main(void)
{
    string name = get_string("What's your name? ");
    int age = get_int("How old are you? ");
    string phone = get_string("What is your phone number? ");

    printf("Your name is %s, you are %i years old, and your phone number is %s.\n", name, age, phone);
    char confirm = get_char("Confirmation : [y/n] ");
    if (confirm == 'y' || confirm == 'Y')
    {
        printf("True\n");
    }
    else if (confirm == 'n' || confirm == 'N')
    {
        printf("False\n");
    }

    person people[2];

    people[0].name = "Carter";
    people[0].number = "+1-617-495-1000";

    people[1].name = "David";
    people[1].number = "+1-949-468-2750";

    string nama = get_string("Name: ");
    for(int i = 0; i < 2; i++)
    {
        if(strcmp(people[i].name, nama) == 0)
        {
            printf("Found %s\n", people[i].number);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}