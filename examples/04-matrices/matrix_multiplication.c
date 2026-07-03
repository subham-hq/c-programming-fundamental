#include <stdio.h>

// declaring the parameters of the matrix dimensions beforehand
#define row1 4
#define col1 3
#define row2 3
#define col2 4
#define row3 4
#define col3 4

int main()
{ 
    int M1[row1][col1], M2[row2][col2], M3[row3][col3];
  	int i, j, k;
	
	// Filling the matrices with elements taken as input
    printf("Enter data for Matrix M1\n");
    for(i=0; i<row1; i++)
    { 
        for(j=0; j<col1; j++)
        {
            scanf("%d", &M1[i][j]);
        }	
        printf("\n");
    }

    printf("Enter data for Matrix M2\n");
    for(i=0; i<row2; i++)
    { 
        for(j=0; j<col2; j++)
        {
            scanf("%d", &M2[i][j]);
        }	
        printf("\n");
    }

	// Checking for the precondition for matrix multiplication
    if (col1 != row2)
    {
        printf("Multiplication is not possible");   
        return 0;
    }

	// Performing the multiplication, dot product of each row and column
    for(i=0; i<row1; i++)
    {
      	for(j=0; j<col2; j++)
        { 
         	M3[i][j] = 0;
			// since col1 = row2, we could have also written 
            // k<row2 in the condition of the loop below
         	for(k=0; k<col1 ;k++)	
            {
                M3[i][j] += M1[i][k] * M2[k][j];
         	}
      	}   
  	}

	// Printing the result of the matrix multiplication
    printf("Result matrix:\n ");
  	for(i=0; i<row3; i++)
    { 
        for(j=0; j<col3; j++)
        {
     		printf("%d", M3[i][j]);
     	}
     	printf("\n");
  	}
  	return 0;
}
