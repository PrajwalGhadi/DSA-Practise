#include<stdio.h>
#include<stdlib.h>

int main(){
    //Declaring rows and Cols 

    int rows, cols;

    printf("Enter rows and cols respectively:\n");
    scanf("%d\n %d", &rows, &cols);

    //Declaring 2D Array
    int array[rows][cols];
    int array1[rows][cols];
    for (int i = 0; i < rows; i++){  
        for (int j = 0; j < cols; j++){
            printf("array[%d][%d] = ", i, j);
            scanf("%d", &array[i][j]);
        }
    }

    //Sum of all elements in array

    // Declaring Resultant variable 
    int result = 0;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            result = result + array[i][j]; 
        }
    }
    printf("Sum of 2 Array: %d", result);
    return 0;
}