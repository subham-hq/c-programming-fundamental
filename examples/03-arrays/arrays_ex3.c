#include <stdio.h>

int main()
{
    int arr[5];
    int i;
    for (i = 0; i < 5; i++)
    {
        printf("Enter the number to store: ");
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < 5; i++)
    {
        printf("%d\t", arr[i]);
    }

    printf("\n");
}