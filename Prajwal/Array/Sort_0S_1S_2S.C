/*
Input:
N = 5
arr[]= {0 2 1 2 0}

Output:
0 0 1 2 2
*/

#include<stdio.h>
#include<stdlib.h>

void swap(int *X, int *Y){
    
    int temp = *X;
    *X = *Y;
    *Y = temp;
}

int main (){
    //Declaring size of array
    int array_size; 

    printf("Enter the Size of array:\n");
    scanf("%d", &array_size);

    //Declaring array
    int array[array_size];

    for (int i = 0; i < array_size; i++){

        printf("Array[%d] = ", i);
        scanf("%d", &array[i]);
    }

    for (int i = 0; i < array_size; i++){
        for (int j = i; j < array_size; j++){

            if (array[i] > array[j + 1]){
                swap(&array[i], &array[j + 1]);
            }
        }    
    }

    for (int k = 0; k < array_size; k++){
        printf("%d", array[k]);
    }
}