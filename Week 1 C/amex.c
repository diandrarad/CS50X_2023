//This program checks the validity of credit card numbers
#include <cs50.h>
#include <stdio.h>

//Get credit card number from user input
int main(void)
{
    long number;
    do
    {
        number = get_long("Credit card number: ");
    }
    while(number < 0);

    //Initialize variables
    int i1 = number % 10;
    number /= 10;
    int i2 = number % 10;
    number /= 10;
    int p1 = i2 * 2;
    int i3 = number % 10;
    number /= 10;
    int i4 = number % 10;
    number /= 10;
    int p2 = i4 * 2;
    int i5 = number % 10;
    number /= 10;
    int i6 = number % 10;
    number /= 10;
    int p3 = i6 * 2;
    int i7 = number % 10;
    number /= 10;
    int i8 = number % 10;
    number /= 10;
    int p4 = i8 * 2;
    int i9 = number % 10;
    number /= 10;
    int i10 = number % 10;
    number /= 10;
    int p5 = i10 * 2;
    int i11 = number % 10;
    number /= 10;
    int i12 = number % 10;
    number /= 10;
    int p6 = i12 * 2;
    int i13 = number % 10;
    number /= 10;
    int i14 = number % 10;
    number /= 10;
    int p7 = i14 * 2;
    int i15 = number % 10;
    number /= 10;
    int i16 = number % 10;
    number /= 10;
    int p8 = i16 * 2;

    //Calculate the sum of digits
    if(p1 > 9)
    {
        p1 -= 9;
    }
    if(p2 > 9)
    {
        p2 -= 9;
    }
    if(p3 > 9)
    {
        p3 -= 9;
    }
    if(p4 > 9)
    {
        p4 -= 9;
    }
    if(p5 > 9)
    {
        p5 -= 9;
    }
    if(p6 > 9)
    {
        p6 -= 9;
    }
    if(p7 > 9)
    {
        p7 -= 9;
    }
    if(p8 > 9)
    {
        p8 -= 9;
    }

    //Calculate the checksum
    int y = i1 + i3 + i5 + i7 + i9 + i11 + i13 + i15;
    int z = p1 + p2 + p3 + p4 + p5 + p6 + p7 + p8;
    int r = (y + z) % 10;

    //Determine the card's issuer
    if(r == 0)
    {
        if(i16 == 0 && i15 == 3 && (i14 == 4 || i14 == 7))
        {
            printf("American Express\n");
        }
        else if(i16 == 5 && (i15 == 1 || i15 == 2 || i15 == 3 || i15 == 4 || i15 == 5))
        {
            printf("MasterCard\n");
        }
        else if(i16 == 4 || (i15 == 0 && i14 == 0 && i13 == 4))
        {
            printf("Visa\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}