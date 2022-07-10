/*
Aim - To check the Mountain shape is occuring in Array or Not
Date - 9 July 2022
@Author - Prajwal Ghadigaonkar
*/

/*
Input - [6, 5, 4, 1, 2, 3, 4, 6, 4, 3, 2, 0]

Output - From Index 3 to 11

*/


#include<stdio.h>
#include<stdlib.h>


void Display(int Left_Count, int Right_Count){

    printf("Height of Mountain is %d\n", Left_Count+Right_Count);
}


int Left_Tracking (int Array[], int Peak_Index){
    
    int Count = 0;
    while(Peak_Index >= 1 and Array[Peak_Index - 1] < Array[Peak_Index]){
        printf("Value %d < Value %d \n", Array[Peak_Index], Array[Peak_Index - 1]);
        Count++;
        Peak_Index--;
    }
    return Count;
}

int Right_Tracking (int Array[], int Peak_Index, int Array_Size){

    int Count = 1;

    // {6, 5, 3, 2, 6, 3, 2, 1, 6, 2, 1, 0};

    while (Peak_Index < Array_Size - 1 and Array[Peak_Index + 1] < Array[Peak_Index]){
        printf("Value %d < Value %d \n", Array[Peak_Index], Array[Peak_Index + 1]);
        Count++;
        Peak_Index++;
    }

    return Count;
}


void Mountain(int Array[], int Array_Length){
    int Number_of_Mountain = 0;

    for (int i = 1; i < Array_Length; i++){

        if (Array[i - 1] <= Array[i] && Array[i] >= Array[i + 1]){

            printf("Array %d is the best position with Index %d"
            " Which can be a peak position of Array \n", Array[i], i);
            
            int Left_Count = Left_Tracking(Array, i);
            printf("%d\n", Left_Count);

            int Right_Count = Right_Tracking(Array, i, Array_Length);
            printf("%d\n", Right_Count);

            
            Number_of_Mountain ++;
            Display(Left_Count, Right_Count);
        }
    }
    printf("We found %d Mountain in Array\n", Number_of_Mountain);
}

int main (){

    // int Array[] = {6, 5, 4, 1, 2, 3, 4, 6, 4, 3, 2, 0};

    int Array[] = {6, 5, 3, 2, 6, 3, 2, 1, 6, 2, 1, 0};

    int Array_Length = sizeof(Array) / sizeof(int);

    Mountain(Array, Array_Length);
    return 0;
}
