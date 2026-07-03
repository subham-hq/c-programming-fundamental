#include <stdio.h>

int average(float, float);
int average_out(float, float);

int average(float x, float y)
{
    int avg;
    avg = (x + y)/2;
    return avg;
}
int average_out(float a, float b)
{
    int avg;
    avg = average(a, b);
    return avg;
}

int main()
{
    float m, n;
    int o;
    m = 5.5;
    n = 10.5;
    o = average_out(m, n);
    printf("%d", o);

    return 0;
}