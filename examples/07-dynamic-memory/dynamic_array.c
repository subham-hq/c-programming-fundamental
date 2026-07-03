#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p, *q;
    p = (int *) malloc(5*sizeof(int));

    q = p; // assigning array p to q
    // the address contained in p is copied into q.

    for (int i = 0; i<5; i++)
    {
        *p = i*i;
        p++;
    }

    for (int i = 0; i<5; i++)
    {
        printf("Element at index %d is %d\n", i, q[i]);
    }

    for (int i = 0; i<5; i++)
    {
        printf("Element at index %d is %d\n", i, *(q + i));
    }
}