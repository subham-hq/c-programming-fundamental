#include <stdio.h>

void check_prime(int);

void check_prime(int n)
{
    int i;
    int notPrimeFlag = 0;
    for (i = 2; i<n; i++)
    {
        if (n%i == 0)
        {
            notPrimeFlag = 1;
            break;
        }
    }
    if (notPrimeFlag == 1)
    {
        printf("%d is not a prime number.\n", n);
    }
    else
    {
        printf("%d is a prime number.\n", n);
    }
}

int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    check_prime(n);

    return 0;
}