#include <stdio.h>

int main()
{
    int var = 1;
    while ( var <= 3 )
    {
        printf("%d\n", var++);
    }
    
    printf("While loop is over");
}