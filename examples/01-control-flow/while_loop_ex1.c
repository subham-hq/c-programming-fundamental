#include <stdio.h>
#define N 1000
int main()
{
    int index = 1, sum = 0;
    while (index <= N)
    {
        sum += index;
        index++;
    }
    printf("Sum of %d Positive Integers is %d\n", N, sum);
}