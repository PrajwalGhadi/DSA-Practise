/*
Aim - Practising Linked List
Date - 10 July 2022
@Author - Prajwal 
*/


#include<stdio.h>
#include<stdlib.h>

//Creating Structure of Linked List 

struct Node
{
    int Data;
    struct Node *Next;
};

void PrintList(struct Node *Head){

    while (Head != NULL)
    {
        printf("%d", Head->Data);
        Head = Head->Next;
    }
}


void Insert_Data (struct Node *Head, int New_Data){
    
    struct Node *ptr = (struct Node*) malloc(sizeof(struct Node));

    ptr ->Data = New_Data;
    ptr ->Next = Head ->Data;

    PrintList(ptr);         
}

int main (){

    struct Node* Head = NULL;
    struct Node* Second = NULL;
    struct Node* Third = NULL;

    Head = (struct Node*) malloc(sizeof(struct Node));
    Second = (struct Node*) malloc(sizeof(struct Node));
    Third = (struct Node*) malloc(sizeof(struct Node));

    Head->Data = 2;
    Head->Next = Second;

    Second->Data = 4;
    Second->Next = Third;

    Third->Data = 6;
    Third->Next = NULL;

    int New_Data = 8;

    Insert_Data(Head, New_Data);
    PrintList(Head);

    return 0;
}
