#include <stdio.h>
#include "rotation.c"
#include <stdbool.h>

int main()
{
    int num;
    printf("Enter a number:\n");
    scanf("%d", &num);
    if(is_rotationally_same(num) == true){
        printf("Yes, the number can be read upside down.\n");
    }
    else
    {
        printf("No, the number cannot be read upside down.\n");
    }
}