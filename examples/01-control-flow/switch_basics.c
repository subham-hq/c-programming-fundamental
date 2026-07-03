#include <stdio.h>

int main()
{
    int language = 10;

    switch (language)
    {
        case 1: printf("C#\n");
        break;

        case 2: printf("C\n");
        break;

        case 3: printf("C++\n");
        break;

        case 4:
        // This way we can skip through a specific case as well
        default:
            printf("Other Programming Language\n");
    }
}