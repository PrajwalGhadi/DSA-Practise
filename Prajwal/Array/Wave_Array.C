/*
Input:
n = 5
array = [1,2,3,4,5]

Output:
[2,1,4,3,5]
*/
#include<stdio.h>
#include<stdio.h>

void swap(int *X, int *Y){

    int temp = *X;
    *X = *Y;
    *Y = temp;
}

int main(){

    // Declaring input variable & array
    int array_size;

    printf("Enter the size of Array: \n");
    scanf("%d", &array_size);

    int array[array_size];

    for (int i = 0; i < array_size; i++){
        printf("Array[%d] = ", i);
        scanf("%d", &array[i]);
    }


    for (int i = 1; i < array_size; i = i+2){
        if (array[i] > array[i - 1]){
            swap(&array[i], &array[i-1]);
        }
        if (array[i] > array[i - 1] && i <= array_size - 2){
            swap(&array[i], &array[i-1]);
        }
    }

    for (int i = 0; i < array_size; i++){
        printf("%d", array[i]);
    }
}