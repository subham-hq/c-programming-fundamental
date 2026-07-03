#include <stdio.h>

int sum(int x, int y);
int sum(int x, int y)
{
    int total;
    total = x + y;
    return total;
}

int main()
{
    int a, b, c;
    a = 50;
    b = 25;
    c = sum(a, b);
    printf("%d", c);
}