#include <iostream>
#include <stdio.h>

using namespace std;

FILE *file = fopen("in.txt", "r");

int convert(const char *s)
{
    int result = 0;
    while (*s >= '0' && *s <= '9')
    {
        result = result * 10 + (*s++ - '0');
    }

    return result;
}

int main()
{
    int sum = 0;
    if (file != NULL)
    {
    }
    char line[256];
    int result;
    while (fgets(line, sizeof(line), file))
        result = convert(line), sum += result;
    fclose(file);
    printf("%d", sum);
    return 0;
}