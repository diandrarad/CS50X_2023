#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long number;
    do
    {
        number = get_long("Credit card number: ");
    }
    while(number < 0);

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

    int y = i1 + p1 + i3 + p2 + i5 + p3 + i7 + p4 + i9 + p5 + i11 + p6 + i13 + p7 + i15 + p8;
    int r = y % 10;

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