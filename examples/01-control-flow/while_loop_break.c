#include <stdio.h>

int main()
{
    int num, sum;
    printf("Enter a positive number: ");
    scanf("%d", &num);

    while ( 1 )
    {
        printf("\nEnter a positive number: ");
        scanf("%d", &num);
        if (num < 0 )
        {
            continue;
        }

        if ( num == 0 )
        {
            break;
        }
        sum += num;
    }
    printf("\n The sum of all postive numbers entered is %d\n", sum);
}