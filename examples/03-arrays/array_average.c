#define SIZE 9
#include <stdio.h>

int avg(int, int[]);

int avg(int n, int arr[])
{
    int sum = 0;
    for(int i = 0; i<n; i++)
    sum += arr[i];

    return sum/n;
}

int main()
{
    int Array[SIZE], average;

    for (int i = 0; i<SIZE; i++)
    Array[i] = i;

    average = avg(SIZE, Array);

    printf("Average: %d\n", average);
}