#include <stdio.h>

int main()
{
    int num;
    printf("Enter number rows to be printed: ");
    scanf("%d", &num);

    for (int row = 1; row <= num; row++)
    {
        for (int col = 1; col <= row; col++)
        {
            printf("* ");
        }
        printf("\n");
    }
}