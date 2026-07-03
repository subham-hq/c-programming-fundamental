#include <stdio.h>

int main()
{
    int num, sq_num;
    printf("Enter a number:");
    scanf("%d", &num);
    while (num <= 0)
    {
        printf("\nPlease enter a positive integer: ");
        scanf("%d", &num);
    }
    
    sq_num = num*num;

    printf("%d is the square value of %d.\n", sq_num, num);

    return 0;
}