#include <stdio.h>

int main()
{
    char toRead[100];
    FILE * fp = fopen("data2.txt", "r");
    if (fp == NULL)
    {
        printf("Could not open data2.txt\n");
        return 1;
    }

    while (fgets(toRead, 100, fp) != NULL)
    {
        printf("%s", toRead);
    }
    
    fclose(fp);

    FILE * fp2 = fopen("output_file.txt", "w");
    if (fp2 == NULL)
    {
        printf("Could not open output_file.txt for writing\n");
        return 1;
    }
    fputs(toRead, fp2);
    fputs("Just printed the last element read from the above list", fp2);
    fclose(fp2);

    return 0;
}