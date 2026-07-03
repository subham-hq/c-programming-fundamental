#include <stdio.h>

int main()
{ 
	int row1, col1, row2, col2;
    printf("Enter number of rows for M1\n");
    scanf("%d",&row1);
    printf("Enter number of columns for M1\n");
    scanf("%d",&col1);
    printf("Enter number of rows for M2\n");
    scanf("%d",&row2);
    printf("Enter number of columns for M2\n");
    scanf("%d",&col2);

    // Checking the precondition about the dimensions
    if(row1!=row2 || col1!=col2)
    { 
        printf("Invalid Input: Addition is not possible");
        return 0;
    }

    // Declaring and initializing the matrices and their dimensions
    int M1[row1][col1], M2[row1][col1], M3[row1][col1], i, j;

    // If the precondition is satisfied, we proceed to fill our matrices
    printf("Enter data for Matrix M1\n");
 	
    for(i=0;i<row1;i++)
    { 
        for(j=0;j<col1;j++)
        {
            scanf("%d",&M1[i][j]);
        }
        printf("\n");
    }

    printf("Enter data for Matrix M2\n");
    for(i=0;i<row2;i++)
    { 
        for(j=0;j<col2;j++)
        {
            scanf("%d",&M2[i][j]);
        }
        printf("\n");
    }

    // Performing the element-wise addition step
    printf("Addition of Matrices is as follows\n");
    for(i=0; i<row2; i++)
        for(j=0; j<col2; j++)
                M3[i][j]= (M1[i][j] + M2[i][j]);

    // Displaying the new matrix after performing addition
    for(i=0;i<row2;i++)
    { 
        for(j=0;j<col2;j++)
        {
            printf("%-3d",M3[i][j]);
        }
        printf("\n");
    }
}