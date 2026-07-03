# include <stdio.h>

int main()
{
    int choice = 8;
    switch (choice)
    {
        case 2:
            printf("You chose 2!\n");
            break;
        default: 
            printf("I\'m default but a bit out of placc\n");
            // break;
        case 1:
            printf("Fell through Default? Cause I\'m 1\n");
            break;
        case 4:
            printf("Today we choose 4!\n");
            break;
        case 3:
            printf("3 it is!\n");
            break;
    }
    return 0;
}