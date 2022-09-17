#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} NODE, *PNODE, **PPNODE;

void Display(PNODE Head)        // To display the LL
{
    printf("Elements in linked list are : \n");
    
    while(Head != NULL)
    {
        printf("| %d | -> ", Head -> data);
        Head = Head -> next;
    }
    
    printf("NULL\n");
}

int Count(PNODE Head)       // To count number of nodes in LL
{
    int iCnt = 0;
    
    while(Head != NULL)
    {
        iCnt++;
        Head = Head -> next;
    }

    return iCnt;
}

void InsertFirst(PPNODE Head, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));     // dynamic memory allocation

    newn -> data = no;
    newn -> prev = NULL;
    newn -> next = NULL;

    if(*Head == NULL)       // If LL is empty
    {
        *Head = newn;
    }

    else        // If LL contains atleast 1 element
    {
        newn -> next = *Head;
        (*Head) -> prev = newn;
        *Head = newn;
    }
}

void InsertLast(PPNODE Head, int no)
{
    PNODE newn = NULL, temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));     // dynamic memory allocation

    newn -> data = no;
    newn -> prev = NULL;
    newn -> next = NULL;

    if(*Head == NULL)       // If LL is empty
    {
        *Head = newn;
    }

    else        // If LL contains atleast 1 element
    {
        temp = *Head;

        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }

        temp -> next = newn;
        newn -> prev = temp;
    }
}

void DeleteFirst(PPNODE Head)
{
    if(*Head == NULL)       // If LL is empty
    {
        return;
    }

    if((*Head)-> next == NULL)	// If LL contains only 1 node
    {
    	free(*Head);
    	*Head = NULL;
    }

    else        // If LL contains more than 1 element
    {
        *Head = (*Head) -> next;
        free((*Head) -> prev);
        (*Head) -> prev = NULL;
    }
}

void DeleteLast(PPNODE Head)
{
    PNODE temp = NULL;

    if(*Head == NULL)       // If LL is empty
    {
        return;
    }

    if((*Head)-> next == NULL)	// If LL contains only 1 node
    {
    	free(*Head);
    	*Head = NULL;
    }

    else        // If LL contains more than 1 element
    {
        temp = *Head;

        while(temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }

        free(temp -> next);
        temp -> next = NULL;
    }
}

void InsertAtPos(PPNODE Head, int no, int pos)
{
    PNODE newn = NULL, temp = NULL;
    int size = Count(*Head);

    newn = (PNODE)malloc(sizeof(NODE));     // dynamic memory allocation

    newn -> data = no;
    newn -> prev = NULL;
    newn -> next = NULL;

    if(pos < 1 || pos > (size+1))
    {
        printf("Invalid position!\n");
        return;
    }

    if(pos == 1)        // InsertFirst
    {
        InsertFirst(Head, no);
    }

    else if(pos == size+1)      // InsertLast
    {
        InsertLast(Head, no);
    }

    else        // Inserting at any random position
    {
        temp = *Head;

        for(int i = 1; i < (pos-1); i++)
        {
            temp = temp -> next;
        }

        newn -> next = temp -> next;
        newn -> next -> prev = newn;
        newn -> prev = temp;
        temp -> next = newn;
    }
}

void DeleteAtPos(PPNODE Head, int pos)
{
    PNODE temp = NULL;
    int size = Count(*Head);
    
    if(pos < 1 || pos > size)
    {
        printf("Invalid position!\n");
        return;
    }

    if(pos == 1)        // DeleteFirst
    {
        DeleteFirst(Head);
    }

    else if(pos == size)         // DeleteLast
    {
        DeleteLast(Head);
    }

    else         // Deleting any random position node
    {
        temp = *Head;

        for(int i = 1; i < (pos-1); i++)
        {
            temp = temp -> next;
        }

        temp -> next = temp -> next -> next;
        free(temp -> next -> prev);
        temp -> next -> prev = temp;
    }
}

int main()
{
    PNODE first = NULL;
    int iChoice = 1, iRet = 0, iValue = 0, ipos = 0;
    
    while(iChoice != 0)
    {
    	printf("Choose from the following options :\n");
    	printf("1 : InsertFirst\n");
    	printf("2 : InsertLast\n");
    	printf("3 : InsertAtPos\n");
    	printf("4 : DeleteFirst\n");
    	printf("5 : DeleteLast\n");
    	printf("6 : DeleteAtPos\n");
    	printf("7 : Display the Linked list\n");
    	printf("8 : Count the number of nodes\n");
    	printf("9 : Exit\n");
    	printf("Enter your choice : ");
    	
    	scanf("%d", &iChoice);
    	
    	switch(iChoice)
    	{
    		case 1:
    			printf("Enter the value to insert : ");
    			scanf("%d", &iValue);
    			InsertFirst(&first, iValue);
    			printf("|-------------------------------------------|\n");  
    			break;
    		
    		case 2:
    			printf("Enter the value to insert : ");
    			scanf("%d", &iValue);
    			InsertLast(&first, iValue);
    			printf("|-------------------------------------------|\n");  
    			break;
    		
    		case 3:
    			printf("Enter the value to insert : ");
    			scanf("%d", &iValue);
    			printf("Enter the position : ");
    			scanf("%d", &ipos);
    			InsertAtPos(&first, iValue, ipos);
    			printf("|-------------------------------------------|\n");  
    			break;
    		
    		case 4:
    			DeleteFirst(&first);
    			printf("|-------------------------------------------|\n");  
    			break;
    		
    		case 5:
    			DeleteLast(&first);
    			printf("|-------------------------------------------|\n");  
    			break;
    		
    		case 6:
    			printf("Enter the pos : ");
    			scanf("%d", &ipos);
    			DeleteAtPos(&first, ipos);
    			printf("|-------------------------------------------|\n");  
    			break;
    		
    		case 7:
    			Display(first);
    			printf("|-------------------------------------------|\n");  
    			break;
    		
    		case 8:
    			iRet = Count(first);
    			printf("Number of elements are : %d\n", iRet);
    			printf("|-------------------------------------------|\n");  
    			break;
    		
    		case 9:
                	printf("Thank you for using the application.\n");
                	printf("|-------------------------------------------|\n");  
                	iChoice = 0;
                	break;
                
                default:
                	printf("Invalid choice!\n");
                	printf("|-------------------------------------------|\n");  
                	break;
    	}    	
    }
    

    return 0;
}
