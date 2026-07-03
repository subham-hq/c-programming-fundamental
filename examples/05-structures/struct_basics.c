#include <stdio.h>
#include <string.h>
struct Student 
{
    int ID;
    char name[20];
    float CGPA;
};
int main() 
{
    struct Student s;
    s.ID=89;
    strcpy(s.name, "Midori");
    s.CGPA = 8.60f;
    printf("%d ", s.ID);
    printf("%s ", s.name);
    printf("%f ", s.CGPA);
}