
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *front; // Global Variables
struct node *rear;

void insert(); // prototypes
void delete ();
void display();
void main()
{
    int choice;
    while (choice != 4)
    {
        printf("\n*************************Main Menu*****************************");
        printf("\n===============================================================");
        printf("\n\n 1.Insert elements in the QUEUE ");
        printf("\n 2.Delete element from the QUEUE ");
        printf("\n 3.Display all elements of the QUEUE ");
        printf("\n 4.EXIT \n");
        printf("\n===============================================================");
        printf("\nEnter your choice ? ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nEnter valid choice??\n");
        }
    }
}
void insert()
{
    struct node *ptr;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
        printf("\nOVERFLOW\n"); // condition if node ptr is not created.
    else
    {
        printf("\nEnter value ? :-> ");
        scanf("%d", &item);
        ptr->data = item;
        if (front == NULL)
        {
            front = rear = ptr;
            front->next = rear->next = NULL;
        }
        else
        {
            rear->next = ptr;
            rear = ptr;
            rear->next = NULL;
        }
    }
}

void delete ()
{
    struct node *ptr;
    int val = -1;
    if (front == NULL) // no element present.
        printf("< ---- UNDERFLOW --- >");
    else
    {
        val = front->data;
        ptr = front;
        front = front->next;
        free(ptr);
        printf("***** Sucessfully deleted %d ***** ", val);
    }
}

void display()
{
    struct node *ptr;
    ptr = front;
    if (front == NULL)
        printf("\n ***** QUEUE IS EMPTY ***** \n");
    else
    {
        printf("\n***** Display the QUEUE  *****\n");
        while (ptr != NULL)
        {
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        }
    }
}