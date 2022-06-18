#include<stdio.h>
#include<stdlib.h>

int main(){

    // Declaring Rows and Cols
    int rows, cols;

    printf("Enter the Rows and Cols: \n");
    scanf("%d\n %d", &rows, &cols);

    // Declaring Array 
    int array1[rows][cols];
    int array2[rows][cols];

    //Taking Elements from user for Array 1
    printf("Taking Elements for Array 1\n");
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            printf("array1[%d][%d] = ", i, j);
            scanf("%d", &array1[i][j]);
        }
    }

    //Taking Elements from user for Array 2
    printf("Taking Elements for Array 2\n");
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            printf("array2[%d][%d] = ", i, j);
            scanf("%d", &array2[i][j]);
        }
    }

    //Declaring Resultant Variable to store the result
    int result[rows][rows];
    printf("Summation of 2 array \n");

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            result[i][j] = array1[i][j] + array2[i][j];            
        }
    }

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            printf("result[%d][%d] = %d\t",i, j, result[i][j]);

            if (j == 1){
                printf("\n");
            }
        }
    }
}