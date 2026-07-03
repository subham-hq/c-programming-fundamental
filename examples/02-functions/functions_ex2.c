#include <stdio.h>

int factorial(int);

int factorial(int n)
{
    int factorial_output;
    factorial_output = 1;
    while(n > 0)
    {
        factorial_output = factorial_output * n;
        n--;
    }
    return factorial_output;
}

int main()
{
    int x, fact;
    printf("Enter a number: ");
    scanf("%d", &x);
    fact = factorial(x);

    printf("The factorial of %d is %d.\n", x, fact);
}
