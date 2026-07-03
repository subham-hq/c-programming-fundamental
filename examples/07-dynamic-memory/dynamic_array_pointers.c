#include <stdio.h>
#include <stdlib.h>

int *copy(int a[], int n)
{
    int *b = (int *) malloc(sizeof(int)*n);

    for (int i = 0; i<n; i++)
    {
        b[i] = a[i];
        // or *(b+i) = *(a+i);
    }

    return b;
}

int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    int *b;

    b = copy(a, 5);

    for (int i = 0; i<5; i++)
    {
        printf("%d\t", b[i]);
    }
}