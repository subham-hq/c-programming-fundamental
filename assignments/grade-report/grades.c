#include <stdio.h>

char grades(int marks)
{
    char grade;

    // Check for invalid marks
    if (marks >100 || marks < 0)
    {
        grade = 'X';
    }

    // Assign grades based on range
    else if (marks >= 90)
    {
        grade = 'A';
    }
    else if (marks >= 80)
    {
        grade = 'B';
    }
    else if (marks >= 70)
    {
        grade = 'C';
    }
    else if (marks >= 60)
    {
        grade = 'D';
    }
    else if (marks >= 50)
    {
        grade = 'E';
    }
    else
    {
        grade = 'F';
    }

    return grade;
}
