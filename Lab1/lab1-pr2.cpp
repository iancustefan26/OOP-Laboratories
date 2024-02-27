#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int main()
{
    char *text = (char *)malloc(100 * sizeof(char));
    char **words = (char **)malloc(100 * sizeof(char));
    char *ptr = text;
    char **buffer = words;
    scanf("%99[^\n]%*c", text, 100);
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