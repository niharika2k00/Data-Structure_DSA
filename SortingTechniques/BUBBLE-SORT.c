#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <malloc.h>

// structure construction
struct node
{
    int data;
    struct node *next;
};
struct node *start = NULL; // start - global variable

// prototype
void create();
void bubble_sort(struct node *start);
void display();
void swap(struct node *a, struct node *b);

int main(void)
{
    int option;

    do
    {

        printf("\n \n **************** CHOOSE AN OPTION **********************");
        printf("\n \n 1. Create a linked-list.");
        printf("\n 2. Display a linked-list.");
        printf("\n 3. BUBBLE-SORT execution.\n \n");
        printf("\n ********************** EXIT ***************************** ");
        printf("\n \n Choose a no. -> ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            bubble_sort(start);
            break;
        default:
            printf("CHOOSE THE OPTION MENTIONED IN THE MENU.....");
            break;
        }

    } while ((option >= 1) && (option < 4));

    return 0;
}

void create()
{
    int i, n, num;
    struct node *newnode, *ptr; // variables of struct node pointer types
    printf("Enter the no. of nodes : ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter a no. --> ");
        scanf("%d", &num);
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = num;
        if (start == NULL)
        {
            start = newnode;
            newnode->next = NULL;
        }
        else
        {
            ptr = start;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = newnode;
            newnode->next = NULL;
        }
    }
}

void display()
{
    printf("\n <------------- Display Successfully ------------->\n");
    struct node *ptr;
    ptr = start;
    while (ptr != NULL)
    {
        printf("%d \t", ptr->data);
        ptr = ptr->next;
    }
}

void bubble_sort(struct node *start)
{
    int swapped;
    struct node *ptr, *q = NULL;

    if (start == NULL)
        return;

    do
    {
        swapped = 0;
        ptr = start;
        while (ptr->next != q)
        {
            if (ptr->data > ptr->next->data)
            {
                swap(ptr, ptr->next);
                swapped = 1;
            }
            ptr = ptr->next;
        }
        q = ptr;

    } while (swapped);
    // return ;

    printf("-------- SUCCESSFULLY SORTED ------");
}

void swap(struct node *a, struct node *b)
{
    int temp;
    temp = a->data;
    a->data = b->data;
    b->data = temp;
}
