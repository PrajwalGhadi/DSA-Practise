#include<stdio.h>
#include<stdlib.h>

int main(){
    //Declaring rows and cols before declaring array
    int rows;
    int cols;

    printf("Enter the Number of rows and cols respectively:\n");
    scanf("%d\n %d", &rows, &cols);

    printf("Row = %d\n", rows);
    printf("Cols = %d\n\n", cols);

    //Now Declaring the 2D_Array using above rows and columns
    int array[rows][cols]; 

    for (int i = 0; i <= rows - 1; i++){
        for (int j = 0; j <= cols - 1; j++){
            printf("Enter a[%d][%d]: ",i,j);                
            scanf("%d",&array[i][j]);   
        }
    }

    printf("\t Printing Elements...\t\n");

    for (int i = 0; i <= rows - 1; i++){
        printf("\n");  // Because of this print statement we get our data in next line after completing 1st loop of cols
        for (int j = 0; j <= cols - 1; j++){
            printf("%d\t", array[i][j]);
        }
    }
    return 0; 
}