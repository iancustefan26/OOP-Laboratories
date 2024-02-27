#include <stdio.h>
#include <stdlib.h>
#include <iostream>

void orderAlphabetic(char *s, char *t)
{
    for (int i = 0; i < strlen(s); ++i)
        if (s[i] == t[i])
            continue;
        else if (t[i] < s[i])
        {
            char *aux = s;
            s = t;
            t = aux;
            return;
        }
        else
            return;
}

int main()
{
    char *text = (char *)malloc(100 * sizeof(char));
    char **words = (char **)malloc(100 * sizeof(char));
    char *ptr = text;
    char **buffer = words;
    scanf("%99[^\n]%*c", text, 100); // scanf_s("%99[^\n]%*c", text, 100);
    *words = text;
    *words++;
    while (*ptr != '\0')
    {
        if (*ptr == ' ')
        {
            ptr++;
            *words = ptr;
            ptr--;
            *words++;
            char *temp = ptr;
            ptr++;
            *temp = '\0';
        }
        else
            ptr++;
    }
    *words = NULL;
    char **my = buffer;
    char **ptrr = buffer;
    while (*buffer != NULL)
    {
        ptrr = buffer;
        while (*ptrr != NULL)
        {
            if (strlen(*ptrr) > strlen(*buffer))
            {
                char *aux = *ptrr;
                *ptrr = *buffer;
                *buffer = aux;
            }
            if (strlen(*ptrr) == strlen(*buffer))
                orderAlphabetic(*buffer, *ptrr);
            *ptrr++;
        }
        *buffer++;
    }
    while (*my != NULL)
        printf("%s\n", *my), *my++;
    // free(ptr);
    // free(text);
    // free(words);
    return 0;
}