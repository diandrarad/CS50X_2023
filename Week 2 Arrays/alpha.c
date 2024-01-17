#include <stdio.h>
#include <string.h>

int main(void)
{
    char word[20];
    int valid = 1;
    do
    {
        printf("Word: ");
        scanf("%s", word);

        int len = strlen(word);
        for(int i = 0; i < len; i++)
        {
            if(word[0] < 'a' || word[0] > 'z')
            {
                valid = 0;
                break;
            }
        }
    }
    while(strlen(word) == 0 && !valid);

    int len = strlen(word);
    for (int i = 0; i < len - 1; i++)
    {
        if(word[i] > word[i + 1])
        {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
}