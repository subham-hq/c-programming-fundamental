#include <stdio.h>

int main()
{
    int arr[10], index, key;

    printf("Enter elements to be included in the array: \n");
    for (index = 0; index<10; index++)
        scanf("%d", &arr[index]);

    printf("Enter the search element: ");
    scanf("%d", &key);

    for (index = 0; index<10; index++)
    {
        if (key == arr[index])
        {
            printf("Element found at %d location.\n", index);
            return 0;
        }
    }
    
    printf("Element not found.");
    return 0;
}
