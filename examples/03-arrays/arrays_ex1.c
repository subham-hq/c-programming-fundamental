#include <stdio.h>

int main()
{
    int num[5] = {1, 2, 3, 4, 5};
    for(int i = 0; i < (sizeof(num)/sizeof(num[0])); i++)
    {
        printf("%d\t", num[i]);
    }
}