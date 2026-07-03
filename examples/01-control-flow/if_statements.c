#include <stdio.h>

int main()
{
    int a;
    printf("Enter any number: ");
    scanf("%d", &a);

    if ( a > 0 )
    {
        printf("This is a positive integer");
    }

    printf("Rest of the programme");

    return 0;
}