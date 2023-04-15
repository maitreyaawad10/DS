#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


void InsertFirst(struct Node** head, int value){
    struct Node* newn = NULL;

    newn = (struct Node*)malloc(sizeof(struct Node));

    newn -> data = value;
    newn -> next = NULL;

    if(*head == NULL){
        *head = newn;
    }
    else{
        newn -> next = *head;
        *head = newn;
    }
}

void InsertLast(struct Node** head, int value){
    struct Node* newn = NULL;

    newn = (struct Node*)malloc(sizeof(struct Node));

    newn -> data = value;
    newn -> next = NULL;

    if(*head == NULL){
        *head = newn;
    }
    else{
        struct Node* temp = *head;

        while(temp -> next != NULL){
            temp = temp -> next;
        }

        temp -> next = newn;
    }
}

void Display(struct Node* head){

    struct Node* temp = head;

    while(temp != NULL){
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}

int main(){
    struct Node* first = NULL;

    InsertFirst(&first, 10);
    InsertFirst(&first, 20);
    InsertFirst(&first, 30);
    Display(first);

    InsertLast(&first, 40);
    InsertLast(&first, 50);
    InsertLast(&first, 60);
    Display(first);

    return 0;
}