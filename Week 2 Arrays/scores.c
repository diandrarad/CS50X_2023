#include <cs50.h>
#include <stdio.h>

const int N = 3;
float average(int scores[N]);

int main(void)
{
    int scores[N];
    for(int i = 0; i < N; i++)
    {
        scores[i] = get_int("Scores: ");
    }
    printf("Avarage: %f\n", average(scores));
}

float average(int scores[N])
{
    int sum = 0;
    for(int i = 0; i < N; i++)
    {
        sum += scores[i];
    }
    return(sum / (float) N);
}