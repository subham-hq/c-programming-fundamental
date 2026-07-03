#include <stdio.h>

int main()
{
    int marks;
    printf("Enter your marks: ");
    scanf("%d", &marks);

    if ( marks > 90 )
    {
        printf("Grade is A");
    }

    else if ( marks <= 90 && marks >= 80 )
    {
        printf("Grade is B");
    }
    else if ( marks <= 80 && marks >= 70 )
    {
        printf("Grade is C");
    }

    else
    {
        printf("Failed");
    }

    return 0;
}