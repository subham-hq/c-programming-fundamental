#include <stdio.h>
#include <stdlib.h>

struct stud
{
    int roll;
    char dept_code[25];
    float cgpa;
};

int main()
{
    struct stud *studArray = (struct stud *) malloc(sizeof(struct stud)*10);
    if (studArray == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }
    int i = 0;
    while (i<10)
    {
        printf("Enter roll no of student %d: ", i);
        scanf("%d", &(studArray[i].roll));
        printf("Enter Dept Code of student %d: ", i);
        scanf("%s", studArray[i].dept_code);
        printf("Enter CGPA of student %d: ", i);
        scanf("%f", &(studArray[i].cgpa));

        i++;
    }
    
    struct stud temp = studArray[0];
    i = 1;
    while (i<10)
    {
        if (temp.cgpa < studArray[i].cgpa)
            temp = studArray[i];

        i++;
    }
    
    printf("The roll number of student with max CGPA is: %d\n", temp.roll);

    free(studArray);
    return 0;
}
