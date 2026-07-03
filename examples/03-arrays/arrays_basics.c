#include <stdio.h>

int main()
{
    int arr[10];
    int i;
    for (i = 0; i < 10; i++)
    {
        printf("Enter the number to store: ");
        scanf("%d", &arr[i]);
    }

    int sum;
    for (i = 0; i < 10; i++)
    {
        sum += arr[i];
    }

    printf("%d", sum);
}