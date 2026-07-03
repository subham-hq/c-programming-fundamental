#include <stdio.h>
#include <string.h>

int main()
{
    char toRead[100];
    FILE * fp = fopen("data1.txt", "r");
    if (fp == NULL)
    {
        printf("Could not open data1.txt\n");
        return 1;
    }

    fgets(toRead, 100, fp);

    fclose(fp);

    char s_temp[] = "How";

    char * p = strstr(toRead, s_temp);

    if (p)
    {
        printf("String is found.\n");
        printf("First occurence of string '%s' in '%s' is '%s'\n", s_temp, toRead, p);
    }
    else
        printf("String is not found.\n");

    return 0;
}