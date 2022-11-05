
#include <stdlib.h>
#include <stdio.h>

#define MAX 50

void insert();
void delete ();
void display();
int queue_array[MAX];
int rear = -1, front = -1;

int main()
{
    int choice;
    while (1)
    {
        printf("\n \n **************** CHOOSE AN OPTION **********************");
        printf("\n\n 1.Insert elements in the QUEUE ");
        printf("\n 2.Delete element from the QUEUE ");
        printf("\n 3.Display all elements of the QUEUE ");
        printf("\n 4.EXIT \n");
        printf("\n ********************** EXIT *****************************\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            traverse();
            break;
        case 4:
            exit(1);
        default:
            printf("Wrong choice \n");
        }
    }
}

void push() // insert , push enqueue same
{
    int num;
    printf("Inset the element in queue : ");
    scanf("%d", &num);
    if (rear == MAX - 1)
        printf("Queue Overflow \n");
    else
    {
        if ((front == -1) && (rear == -1))
            front = rear = 0; /*If queue is initially empty */
        else
            rear++;
        queue_array[rear] = num;
    }
}

void pop() // pop , dequeue same
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow \n");
        return;
    }
    else
    {
        printf("Element deleted from queue is : %d\n", queue_array[front]);
        front++;
    }
}

void traverse()
{
    int i;
    if ((front == -1) && (rear == -1))
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        for (i = front; i <= rear; i++)
            printf("%d ", queue_array[i]);
    }
}