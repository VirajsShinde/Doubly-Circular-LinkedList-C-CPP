#include<stdio.h>
#include<stdlib.h>

////////////////////////////////////////////////////////////////////////////////////////
//Linear Data Structure  //github.com/VirajsShinde

//Linked List --> Doubly->Circular.c (C)  

////////////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

int iCount = 0;
//////////////////////////////////////////////////////////////////////////

void InsertFirst(PPNODE first,PPNODE last,int iNo)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if((*first == NULL) && (*last == NULL))
    {
        *first = *last = newn;

        iCount++;
    }
    else
    {
        newn->next = *first;

        (*first)->prev = newn;

        *first = newn;

        iCount++;
    }
    (*last)->next = *first;
    (*first)->prev = *last;
}

/////////////////////////////////////////////////////////////////////////

void InsertLast(PPNODE first,PPNODE last,int iNo)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if((*first == NULL) && (*last == NULL))
    {
        *first = *last = newn;

        iCount++;
    }
    else
    {
        (*last)->next = newn;
        newn->prev = *last;
        (*last)= newn;
        
        iCount++;
    }

    (*last)->next = *first;
    (*first)->prev = *last;
}

/////////////////////////////////////////////////////////////////////////

void DeleteFirst(PPNODE first, PPNODE last)
{
    if((*first == NULL) && (*last == NULL))
    {
        printf("Linked list is empty\n");
        return;
    }
    else if((*first) == (*last))
    {
        free(*first);

        *first = NULL;
        *last = NULL;

        iCount--;
    }
    else
    {
        (*first)= (*first)->next;
        
        free((*last)->next);

        (*last)->next = *first;
        (*first)->prev = *last;

        iCount--;
    }
}

///////////////////////////////////////////////////////////////////////

void DeleteLast(PPNODE first,PPNODE last)
{
    if((*first == NULL) && (*last == NULL))
    {
        printf("Linked list is empty\n");
        return;
    }
    else if((*first) == (*last))
    {
        free(*first);

        *first = NULL;
        *last = NULL;

        iCount--;
    }
    else
    {
        (*last) = (*last)->prev;
        free ((*first)->prev);

        (*last)->next = *first;
        (*first)->prev = *last;

        iCount--;
    }
}

///////////////////////////////////////////////////////////////////////

void InsertAtPosition(PPNODE first,PPNODE last,int iNo,int iPos)
{
    if((iPos < 1) || (iPos > iCount+1))
    {
        printf("Invalid Position\n");
        return;
    }
    if(iPos == 1)
    {
        InsertFirst(first,last,iNo);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(first,last,iNo);
    }
    else
    {
        PNODE newn = (PNODE)malloc(sizeof(NODE));

        newn->data = iNo;
        newn->next = NULL;
        newn->prev = NULL;

        PNODE temp = *first;

        for(int iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
}

//////////////////////////////////////////////////////////////////////

void DeleteAtPosition(PPNODE first,PPNODE last,int iPos)
{
    if((iPos < 1) || (iPos > iCount))
    {
        printf("Invalid Position\n");
        return;
    }
    if(iPos == 1)
    {
        DeleteFirst(first,last);
    }
    else if(iPos == iCount)
    {
        DeleteLast(first,last);
    }
    else
    {
        PNODE temp = *first;

        for(int iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;

        free (temp->next->prev);

        temp->next->prev = temp;

        iCount--;
    }
}

///////////////////////////////////////////////////////////////////////
void Display(PNODE first,PNODE last)
{
    printf("Elements of Linked List are : \n");

    PNODE temp = first;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        printf("| %d |->",temp->data);
        temp = temp->next;
    }
    printf("| NULL | \n");
}

////////////////////////////////////////////////////////////////////////////

void Options()
{
    printf("-------------------------------------------------------------------\n");

        printf("Please Select Desire Option : \n");
        printf("1 : Insert First \n");
        printf("2 : Insert Last \n");
        printf("3 : Insert At given Position\n");
        printf("4 : Delete First\n");
        printf("5 : Delete Last\n");
        printf("6 : Delete At given Position\n");
        printf("7 : Display the contents of Linked List\n");
        printf("8 : Count Number of Nodes from Linked List\n");
        printf("9 : Options\n");
        printf("10 : EXIT\n");
        printf("-------------------------------------------------------------------\n");
}

////////////////////////////////////////////////////////////////////////////////////////

int main()
{   
    PNODE Head = NULL;
    PNODE Tail = NULL;

    int iChioce = 0, iPos = 0, iNo = 0;

    printf("\n Welcome --DS--> Doubly->Circular.c | github.com/VirajsShinde\n");

    Options();

    while(1)
    {
        printf("Enter Number : ");
        scanf("%d",&iChioce);

        switch(iChioce)
        {
            case 1: 
                printf("Enter the data that you want to insert first : \n");
                scanf("%d",&iNo);

                InsertFirst(&Head,&Tail,iNo);
                Display(Head,Tail);
                break;
            
            case 2:
                printf("Enter the data that you want to insert last : \n");
                scanf("%d",&iNo);

                InsertLast(&Head,&Tail,iNo);
                Display(Head,Tail);
                break;

            case 3:
                printf("Enter the data that you want to insert at position : \n");
                scanf("%d",&iNo);
                printf("Enter the Position : \n");
                scanf("%d",&iPos);

                InsertAtPosition(&Head,&Tail,iNo,iPos);
                Display(Head,Tail);
                break;

            case 4:
                DeleteFirst(&Head,&Tail);
                Display(Head,Tail);
                break;

            case 5:
                DeleteLast(&Head,&Tail);
                Display(Head,Tail);
                break;

            case 6:
                printf("Enter the Position : \n");
                    scanf("%d",&iPos);
                    
                    DeleteAtPosition(&Head,&Tail,iPos);
                    Display(Head,Tail);
                    break;

            case 7:
                Display(Head,Tail);
                break;

            case 8:
                printf("Number of Elemnets are : %d\n",iCount);
                break;

            case 9:
                Options();
                break;

            case 10:
                printf("Thank you for using this application\n");
                printf("--------------------------------------------------------------------\n");
                return 0;

            default:
                printf("Invalid Position\n");
                break;
        }
        printf("\n");
        printf("--------------------------------------------------------------------\n");
    }
    return 0;
}

/////////////////////////////////////////////////////////////////////////