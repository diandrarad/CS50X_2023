#include <cs50.h>
#include <stdio.h>

bool valid_triangle(float a, float b, float c);

int main(void)
{
    float a = get_int("side a: ");
    float b = get_int("side b: ");
    float c = get_int("side c: ");
    
    if(valid_triangle(a, b, c))
    {
        printf("VALID TRIANGLE\n");
    }
    else
    {
        printf("NOT A TRIANGLE\n");
    }
}

bool valid_triangle(float a, float b, float c)
{
    if(a < 1 || b < 1 || c < 1)
    {
        return false;
    }
    if(a >= b + c || b >= a + c || c >= a + b)
    {
        return false;
    }
    return true;
}