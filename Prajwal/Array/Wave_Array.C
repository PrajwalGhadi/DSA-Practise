/*
Aim - This program is based on swaping theory and some wave logic through  where we keep
    larger number at previous index, Smaller Number at Current Index, and again Larger on Furthermost
    index

Date - 6 july 2020
Author - Prajwal

Time complexity - O(N)
Space Complexity - O(N)
*/
// -------------------------------------------------------
/*
Input:
n = 5
array = [1,2,3,4,5]

Output:
[2,1,4,3,5]
*/
#include<stdio.h>
#include<stdlib.h>

// Swap Function 
void swap (int *X, int *Y){

    int temp = *X;
    *X = *Y;
    *Y = temp;
}

void printing (int array[], int array_size){

    // Time Complexity of below loop is O(N)
    for (int i = 0; i < array_size; i++){
        printf("%d\n", array[i]);
    }
}


// Wave Function 

void wave (int array[], int array_size){


    // Time Complexity of below loop is O(N)
    for (int i = 1; i < array_size; i = i+2){
        
        // Condition to check elements current index is more than previous index 
        // If Condition Statisfy then SWAP
        if (array[i - 1] < array[i]){
            swap(&array[i-1], &array[i]);
        }

        // Condition to check whether current index is greater than furthermost index or not
        // If Condition Statisfy then SWAP 
        if(array[i] > array[i + 1] && i <= array_size - 2){
            swap(&array[i], &array[i + 1]);
        }
    }

    printing(array, array_size);
}

// Main Function 
int main(){

    // Array Variable 
    int array[] = {13, 2, 32, 324, 35, 52, 2};

    int array_size = sizeof(array)/sizeof(int);

    // printf("%d\n", array_size);
    wave(array, array_size);    

    return 0;
}