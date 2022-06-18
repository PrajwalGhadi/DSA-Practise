#include<stdio.h>
#include<stdlib.h>

// int main(){

// // Manually Creating Array and storing data in same and Printing it.
// //     int arr[] = {2, 3, 4, 5, 7}; //int arr[] -> Decalaring array with datatype int
// //     int size_arr = sizeof(arr) / sizeof(int); //Size of Array Calculation

// //     for (int i = 0; i < size_arr; i++){
// //         printf("%d ", arr[i]);
// //     } 


// // Creating Array and Taking Data from user, storing and printing same

// int size;
// int arr[size];
// // int size_arr = sizeof(arr) / sizeof(int);

// printf("Please enter the size for array \n");
// scanf("%d", &size);
// // printf("%d", size);
// for (int i = 0; i < size-1; i++){
//     scanf("%d", arr[i]);
// }
// for (int j = 0; j < size-1; j++){
//     printf("%d ", arr[j]);
// }
// }

int main(){
    int size;
    printf("Enter the size of array:\n");
    scanf("%d", &size);

// Whenever you have to take the input from user Declare the size of array before declaring array
    int arr[size];

    for (int i = 0; i < size - 1; i++){
        scanf("%d ", &arr[i]);
    }

    for (int j = 0; j < size - 1; j++){
        printf("%d ", arr[j]);
    }
    return 0;
}