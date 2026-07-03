#include <stdio.h>
#define NUM 4
typedef struct
{
    char name[20];
    int id;
    int marks[2];
} Student;

int main()
{
    Student list[NUM] = {
        {"John", 100, {60, 70}},
        {"Ram", 200, {75, 92}},
        {"Francis", 300, {85, 68}},
        {"Gopal", 400, {89, 97}}
    };

    printf("All the students having grades average greater than 70 are as follows: \n");
    for (int i = 0; i<NUM; i++)
    {
        float average;
        average = (list[i].marks[0] + list[i].marks[1]) / 2.0f;
        if (average > 70)
            printf("%s %d\n", list[i].name, list[i].id);
        else
            continue;
    }
}
