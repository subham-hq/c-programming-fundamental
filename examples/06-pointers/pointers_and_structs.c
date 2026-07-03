#include <stdio.h>

typedef struct
{
    int roll;
    char dept[10];
    float cgpa;
} Student;

int main()
{
    Student s1 = {100, "CS", 9.5};
    Student *p1 = &s1;
    printf("\n Roll: %d Dept: %s CGPA: %f\n", s1.roll, p1->dept, (*p1).cgpa);
    Student list[3] = {{100, "DM", 9.5}, {200, "CS", 9.9}, {300, "WP", 9.1}};
    p1 = list + 1;
    printf("\n Roll: %d Dept: %s CGPA: %f\n", p1->roll, p1->dept, (*p1).cgpa);
    p1++;
    printf("\n Roll: %d Dept: %s CGPA: %f\n", p1->roll, p1->dept, (*p1).cgpa);
}
