#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} NODE, *PNODE, **PPNODE;

int Count(PNODE head);  // Count Function Prototype

void InsertFirst(PPNODE head, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = no;
    newn -> next = NULL;

    if (*head == NULL) // IF LL IS EMPTY
    {
        *head = newn;
    }
    
    else // IF LL CONTAINS ATLEAST 1 NODE
    {
        newn -> next = *head;
        *head = newn;
    }
}

void DeleteFirst(PPNODE head)
{
    PNODE temp = NULL;
    
    if(*head == NULL)   // IF LL IS EMPTY
    {
        return;
    }

    else    // IF LL CONTAINS ATLEAST 1 NODE
    {
        temp = *head;
        (*head) = (*head) -> next;
        free(temp);
    }
}

void InsertLast(PPNODE head, int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = no;
    newn -> next = NULL;

    if(*head == NULL)   // IF LL IS EMPTY
    {
        *head = newn;
    }
    
    else    // IF LL IS NOT EMPTY
    {
        temp = *head;

        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }

        temp -> next = newn;
    }
}

void DeleteLast(PPNODE head)
{
    PNODE temp = NULL;

    if(*head == NULL)   // IF LL IS EMPTY
    {
        return;
    }

    else if((*head) -> next == NULL)    // IF LL CONTAINS ONLY 1 NODE
    {
        free(*head);
        *head = NULL;
    }

    else    // IF LL CONTAINS MORE THAN 1 NODE
    {
        temp = *head;

        while(temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }

        free(temp -> next);
        temp -> next = NULL;
    }
}

void InsertAtPos(PPNODE head, int no, int pos)
{
    PNODE newn = NULL;
    PNODE temp = NULL;
    int size = 0;
    size = Count(*head);

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = no;
    newn -> next = NULL;

    if(pos < 1 || pos > (size + 1))
    {
        printf("Invalid position!\n");
        return;
    }

    else if(pos == 1)       // InsertFirst
    {
        InsertFirst(head, no);
    }

    else if(pos == size+1)      // InsertLast
    {
        InsertLast(head, no);
    }

    else        // Inserting at any random position
    {
        temp = *head;

        for(int i = 1; i < (pos-1); i++)
        {
            temp = temp -> next;
        }

        newn -> next = temp -> next;
        temp -> next = newn;
    }
}

void DeleteAtPos(PPNODE head, int pos)
{
    PNODE temp = NULL;
    PNODE tempdelete = NULL;

    int size = 0;
    size = Count(*head);

    if(pos < 1 || pos > size)
    {
        printf("Invalid position!\n");
        return;
    }

    if(pos == 1)       // DeleteFirst
    {
        DeleteFirst(head);
    }

    else if(pos == size)         // DeleteLast
    {
        DeleteLast(head);
    }

    else         // Deleting at any random position
    {
        temp = *head;

        for(int i = 1; i < (pos-1); i++)
        {
            temp = temp -> next;
        }

        tempdelete = temp -> next;
        temp -> next = temp -> next -> next;
        free(tempdelete);
    }
}

void Display(PNODE head)        // To display the LL
{
    printf("Elements in linked list are : \n");
    while(head != NULL)
    {
        printf("| %d | -> ", head -> data);
        head = head->next;
    }
    printf("NULL\n");
}

int Count(PNODE head)       // To count number of nodes in LL
{
    int iCnt = 0;
    
    while(head != NULL)
    {
        iCnt++;
        head = head -> next;
    }

    return iCnt;
}

int main()
{
    PNODE first = NULL;
    int iret = 0;

    printf("-------------------------------------------------------------\n");

    InsertFirst(&first, 51);
    InsertFirst(&first, 21);
    InsertFirst(&first, 11);

    Display(first);
    iret = Count(first);
    printf("No. of elements are : %d\n", iret);

    printf("-------------------------------------------------------------\n");

    InsertLast(&first, 71);
    InsertLast(&first, 101);
    InsertLast(&first, 121);

    Display(first);
    iret = Count(first);
    printf("No. of elements are : %d\n", iret);

    printf("-------------------------------------------------------------\n");

    // DeleteFirst(&first);
    // // DeleteFirst(&first);
    // DeleteFirst(&first);

    // Display(first);
    // iret = Count(first);
    // printf("No. of elements are : %d\n", iret);

    // printf("-------------------------------------------------------------\n");


    // DeleteLast(&first);
    // DeleteLast(&first);
    // DeleteLast(&first);

    // Display(first);
    // iret = Count(first);
    // printf("No. of elements are : %d\n", iret);

    // printf("-------------------------------------------------------------\n");

    InsertAtPos(&first, 61, 4);

    Display(first);
    iret = Count(first);
    printf("No. of elements are : %d\n", iret);

    printf("-------------------------------------------------------------\n");

    // DeleteAtPos(&first, 4);

    // Display(first);
    // iret = Count(first);
    // printf("No. of elements are : %d\n", iret);

    // printf("-------------------------------------------------------------\n");

    return 0;
}