#include<stdio.h>
#include<stdlib.h>

int Binary_Search(int array[], int size, int element){

    int low, mid, high;

    low = 0;
    high = size - 1;

    

    while (low <= high){
        
        mid = (high + low) / 2;
        // Lets use checker to match the conditions
        //Checker 1...
        if (array[mid] == element){
            return mid;
        }
        //Checker 2...
        if (element > array[mid]){

            low = mid + 1;
        }
        //Checker 3...
        else{

            high = mid - 1;
        }
    }
    return -1;
}

int main(){

    //Declaring the Size Variable for array
    int array_size, element;

    printf("Enter the size of array:\n");
    scanf("%d", &array_size);

    printf("Enter the element:\n");
    scanf("%d", &element);

    //Declaring Array
    int array[array_size];

    for (int i = 0; i < array_size; i++){

        printf("Array[%d] = ", i);
        scanf("%d", &array[i]);
    }

    int index = Binary_Search(array, array_size, element);
    printf("Element %d found at %d", element, index);
    return 0;
}