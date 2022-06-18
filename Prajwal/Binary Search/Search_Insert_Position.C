#include<stdio.h>
#include<stdlib.h>

int Search_Insert_Position(int array[], int size, int target){

    int low, mid, high; 

    low = 0;
    high = size - 1; 
    
       
    while (low <= high)
    {
        mid = (low + high) / 2;
        
        if (array[mid] == target){
            return mid;
        }
        

        if (target > array[mid]){
            low = mid + 1;
          
        }
        else{
            high = mid - 1;  
        }
    }
    
    // for (int i = 0; i < size; i++){
    //     if (target > array[i]){
    //         return i;
    //     }
    // }'

    return high;
}


int main (){

    int array_size, target; 

    printf("Enter the Size of Array:\n");
    scanf("%d", &array_size);

    printf("Enter the element for search or Insert:\n");
    scanf("%d", &target);

    int array[array_size];

    for(int i = 0; i < array_size; i++){
        printf("Array[%d] = ", i);
        scanf("%d", &array[i]);
    }

    int index = Search_Insert_Position(array, array_size, target);
    printf("%d", index);
    return 0;
}