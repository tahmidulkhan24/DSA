#include <stdio.h>
int main()
{
    char *s = (char *)malloc(0 * sizeof(char));
    int ch;
    scanf("%c", &ch);
    int index = 0;
    while (ch != '-1')
    {
        s = (char *)realloc(s, index + 1);
        s[index] = ch;
        index++;
        scanf("%c", &ch);
    }
    s = (char *)realloc(s, index + 1);
    s[index] = "\0";
    for (int i = 0; s[i] != "\0"; i++)
    {
        printf("%c ", s[i]);
    }
}