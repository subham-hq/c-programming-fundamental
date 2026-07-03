#include <stdio.h>

int main()
{
    int a, b, c;
    printf("Enter threee numbers: ");
    scanf("%d %d %d", &a, &b, &c);

    if ( a > b )
    {
        if ( a > c )
        {
            printf("A is the largest.");
        }

        else
        {
            printf ("C is the largest.");
        }
    }
    else
    {
        if ( b > c )
        {
            printf("B is the largest.");
        }
        else
        {
            printf("C is the largest.");
        }
    }
}