
// LINKED-LIST REPRESENTATION OF CIRCULAR QUEUE

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *rear = NULL, *front = NULL;

void insert(int item);
int delete ();
void display();

int main()
{
    int choice, item;
    while (1)
    {
        printf("\n**********************    MAIN MENU     *************************");
        printf("\n===============================================================");
        printf("\n\n 1.Insert elements in the CIRCULAR QUEUE ");
        printf("\n 2.Delete element from the CIRCULAR QUEUE ");
        printf("\n 3.Display all elements of the CIRCULAR QUEUE ");
        printf("\n 4.EXIT \n");
        printf("\n===============================================================");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter the element for insertion : ");
            scanf("%d", &item);
            insert(item);
            break;
        case 2:
            printf("\nDeleted element is %d\n", delete ());
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
            break;
        default:
            printf("\nWrong choice\n");
        }
    }
}

void insert(int item)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data = item;
    // tmp->next = NULL;
    if (tmp == NULL)
        printf("\n****  Memory is not available(allocated) ****\n");

    else if ((rear == NULL) && (front == NULL)) // for the 1st ele
    {
        rear = front = tmp;
        rear->next = front;
    }
    else
    {
        rear->next = tmp;
        rear = rear->next; // update rear
        rear->next = front;
    }
}

int delete ()
{
    int item;
    struct node *tmp;
    tmp = front;

    if ((rear == NULL) && (front == NULL))
        printf("\n**** Queue underflow ****\n");

    else if (front == rear)
    {
        front = rear = NULL;
        free(tmp);
    }
    else
    {
        front = front->next;
        rear->next = front; // update rear
        // free(tmp);
    }
    item = tmp->data;
    return tmp->data;
}

void display()
{
    struct node *p;
    p = front;
    if ((rear == NULL) && (front == NULL))
        printf("\nQueue is empty\n");

    printf("\n<------  Queue is :\n");
    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while (p != front);
    printf("\n");
}