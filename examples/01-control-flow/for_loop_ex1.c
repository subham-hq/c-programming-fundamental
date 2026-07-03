#include <stdio.h>
# define N 1000

int main()
{
    int sum;

    for (int i = 0; i<=N; i ++)
    {
        if ( (i%3 == 0) && (i%4 != 0) )
        {
            sum += i;
        }
    }
    printf("Sum of all numbers from 1 to %d that are multiple of 3 but not multiple of 4 is %d", N, sum);
}