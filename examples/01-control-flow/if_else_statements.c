#include <stdio.h>

int main()
{
    int a;
    printf("Enter any number: ");
    scanf("%d", &a);

    if ( a>0 )
    {
        printf("You have entered a positive number");
    }
    else
    {
        printf("You have entered a negative number");
    }

    return 0;
}