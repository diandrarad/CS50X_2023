#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("n: ");
    }
    while(n < 1);
    int c = 1;
    int a[n];
    printf("1\n");
    for(int i = 1; i < n; i++)
    {
        c *= 2;
        a[i] = c;
        printf("%i\n", a[i]);
    }
}