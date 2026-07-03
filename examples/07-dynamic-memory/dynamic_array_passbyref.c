#include <stdio.h>
#include <stdlib.h>

void copy(int c[], int n, int d[])
{
    for (int i = 0; i<n; i++)
    {
        d[i] = c[i];
        // or *(b+i) = *(a+i);
    }
}

int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    int b[5];

    copy(a, 5, b);

    for (int i = 0; i<5; i++)
    {
        printf("%d\t", b[i]);
    }
}