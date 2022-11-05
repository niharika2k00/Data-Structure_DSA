
// *********************** LINKED-LIST IMPLEMENTATION  **********************
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
struct node *start = NULL, *q = NULL, *p = NULL; // start - global variable

// prototypes......
void create();
void display(struct node *start);
void addbeginning();
void addend();
void addbefr_givennode();
void addaftr_givennode();
void delbeginning();
void delend();
void delany_givennode();
void delentire_linkedlist();
void maxNode();
// void Reverse();
void Reverse(struct node *start);
void search(struct node *start);
void delodd_ele();
void findsum();
void insertele_position();
void delele_position();
void reversePrint(struct node *start);

int main(void)
{
    int option;

    do
    {
        printf("\n \n **************** CHOOSE AN OPTION **********************");
        printf("\n \n 1. Create a linked-list.");
        printf("\n 2. Display a linked-list.");
        printf("\n 3. Add a node from the beginning.");
        printf("\n 4. Add a node from the END.");
        printf("\n 5. Add a node BEFORE a given node.");
        printf("\n 6. Add a node AFTER a given node.");
        printf("\n 7. Delete a node from the beginning.");
        printf("\n 8. Delete a node from the END.");
        printf("\n 9. Delete any given NODE.");
        printf("\n 10. Delete the entire linked-list.");
        printf("\n 11. MAXIMUM node value in the whole linked-list.  ");
        printf("\n 12. REVERSE the linked-list. ");
        printf("\n 13. Search an element in the linked-list.");
        printf("\n 14. Delete ALL ODD elements.");
        printf("\n 15. Sum of all elements.");
        printf("\n 16. Insert element at a given POSITION. ");
        printf("\n 17. Delete element at a given POSITION. ");
        printf("\n 18. Print the REVERSE list. \n");
        printf("\n ********************** EXIT *****************************");
        printf("\n \n Choose a no. -> ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            create();
            break;
        case 2:
            display(start);
            // display();
            break;
        case 3:
            addbeginning();
            break;
        case 4:
            addend();
            break;
        case 5:
            addbefr_givennode();
            break;
        case 6:
            addaftr_givennode();
            break;
        case 7:
            delbeginning();
            break;
        case 8:
            delend();
            break;
        case 9:
            delany_givennode();
            break;
        case 10:
            delentire_linkedlist();
            break;
        case 11:
            maxNode();
            break;
        case 12:
            // Reverse();
            Reverse(start);
            break;
        case 13:
            search(start);
            break;
        case 14:
            delodd_ele();
            break;
        case 15:
            findsum();
            break;
        case 16:
            insertele_position();
            break;
        case 17:
            delele_position();
            break;

        case 18:
            reversePrint(start);
            break;
        default:
            printf("CHOOSE THE OPTION MENTIONED IN THE MENU.....");
            break;
        }

    } while ((option >= 1) && (option <= 20));
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
            start = newnode; // head / start pointing to the Linked List.
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

void display(struct node *start) // display using recursion
{
    struct node *ptr = start;
    if (ptr == NULL)
        return;
    printf("%d \t", ptr->data);
    display(ptr->next);
}

/* void display()               // Iterative Method
{
    printf("\n <------------- Display Successfully ------------->\n");
    struct node *ptr;
    ptr = start;
    while (ptr != NULL)
    {
        printf("%d \t", ptr->data);
        ptr = ptr->next;
    }
} */

void addbeginning()
{
    struct node *newnode;
    int num;
    printf("####### _______ ADD NODE BEGINNING  ________########  \n\n");
    printf("Enter a value of the node that must be entered at the beginning --> ");
    scanf("%d", &num);
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->next = start;
    start = newnode;
    printf("\nNODE SUCCESSFULLY ADDED AT THE BEGINNING\n");
}

void addend()
{
    struct node *ptr, *newnode;
    int num;
    printf("####### _______ ADD NODE END  ________######## \n\n ");
    printf("Enter a value of the node that must be added at the end --> ");
    scanf("%d", &num);
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->next = NULL;
    ptr = start;
    if (start == NULL)
        return;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = newnode;
    printf("\nNODE SUCCESSFULLY ADDED AT THE END\n");
}

void addbefr_givennode()
{
    struct node *ptr, *newnode, *preptr;
    int num, value;
    printf("\nEnter the value of the node before which you want to add new no. : ");
    scanf("%d", &value);
    printf("Enter a value of the node that must be added --> ");
    scanf("%d", &num);
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;
    ptr = start;
    while (ptr->data != value)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    newnode->next = ptr;
    preptr->next = newnode;
    printf("\nSUCCESSFULLY INSERTED A  NODE\n \n");
}

void addaftr_givennode()
{
    struct node *ptr, *newnode;
    int num, value;
    printf("\nEnter the value of the node after which you want to add new no. : ");
    scanf("%d", &value);
    printf("Enter a value of the node that must be added --> ");
    scanf("%d", &num);
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;
    ptr = start;
    while (ptr->data != value)
    {
        ptr = ptr->next;
    }
    newnode->next = ptr->next;
    ptr->next = newnode;
    printf("\nSUCCESSFULLY INSERTED A NODE AFTER A GIVEN NODE. \n \n");
}

void delbeginning()
{
    struct node *ptr;
    ptr = start;
    start = ptr->next;
    printf("\nSUCCESSFULLY DELETED THE 1ST NODE\n \n");
}

void delend()
{
    struct node *ptr, *preptr;
    ptr = start;
    while (ptr->next != NULL)
    {
        preptr = ptr;
        ptr = ptr->next;
    }

    preptr->next = NULL;
    printf("\nSUCCESSFULLY DELETED THE LAST NODE\n \n");
}

void delany_givennode()
{
    struct node *ptr, *preptr;
    int value;
    printf("\nEnter the value of the node u want to delete : ");
    scanf("%d", &value);
    ptr = start;
    while (ptr->data != value)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next;
    printf("\nSUCESSFULLY DELETED THE NODE U WANTED......\n");
}

void delentire_linkedlist()
{
    struct node *temp;
    struct node *ptr = start;
    while (ptr != NULL)
    {
        temp = ptr;
        ptr = ptr->next;
        free(temp);
    }
    printf("YAAAH !!....  LINKED-LIST DELETED");
    start = ptr;
}

void maxNode()
{
    struct node *current = start;
    int max;

    if (start == NULL)
        printf("List is empty \n");

    else
    {
        max = start->data;
        while (current->next != NULL)
        {
            if (max < current->data) //  CPP : max = max(current->data, max);
                max = current->data;
            current = current->next;
        }
        printf("\n Maximum value node in the list: %d\n", max);
    }
}

/* void Reverse()                  // Reversing using an ARRAY.
{
    struct node *ptr = start;
    int a[20], i;
    for (i = 0; ptr->next != NULL; i++)
    {
        a[i] = ptr->data;
        ptr = ptr->next;
    }

    ptr = start;
    i = i - 1;
    while (ptr->next != NULL)
    {
        ptr->data = a[i--];
        ptr = ptr->next;
    }
    printf("REVERSED SUCCESSFULLY --------> \n");
    // printing the reversed ll.
    ptr = start;
    while (ptr->next != NULL)
    {
        printf("%d \t", ptr->data);
        ptr = ptr->next;
    }
}*/

/* void Reverse()                  //  Reversing using sliding pointer/ changing the arrow direction
{
    struct node *ptr = start;
    struct node *q = NULL;
    struct node *r = NULL;
    while (ptr != NULL)
    {
        r = q;
        q = ptr;
        ptr = ptr->next;
        q->next = r;
    }
    start = q;

    // printing the reversed ll.
    printf("REVERSED SUCCESSFULLY --------> \n");
    ptr = start;
    while (ptr != NULL)
    {
        printf("%d \t", ptr->data);
        ptr = ptr->next;
    }
}
 */

void Reverse(struct node *p) // Time Complexity: O(n), Recursive method (BEST)
{
    if (p->next == NULL)
    {
        start = p;
        printf("REVERSED SUCCESSFULLY --------> \n");
        return;
    }
    Reverse(p->next);
    struct node *rev;
    rev = p->next;
    rev->next = p;
    p->next = NULL;
}

void search(struct node *start)
{
    int val;
    struct node *p = start;
    printf("Enter the value that u want to find ? ");
    scanf("%d", &val);
    while (p != NULL)
    {
        if (p->data == val)
        {
            printf("%d is found in the linked list\n", val);
            // break;
            return;
        }
        p = p->next;
    }
    printf("%d is NOT found in the linked list\n", val);
}

void delodd_ele()
{
    struct node *p = start;
    if ((p->data) % 2 != 0) // checking whether the data of first node is ODD
    {
        struct node *t = p->next;
        free(p);
        p = t;
    }
    struct node *temp = p;
    while (temp != NULL)
    {
        if (temp->next != NULL && temp->next->data % 2 != 0)
        {
            struct node *t = temp->next->next;
            free(temp->next);
            temp->next = t;
        }
        else
            temp = temp->next;
    }
    printf("DELETED ALL ODD NODES SUCCESSFULLY --------> \n");
}

void findsum()
{
    int sum = 0;
    struct node *ptr;
    ptr = start;
    while (ptr != NULL)
    {
        sum = sum + ptr->data;
        ptr = ptr->next;
    }
    printf("\n Sum of all the NODES OF THE Linked-List is :: %d  ---------->\n", sum);
}

void insertele_position()
{
    struct node *newnode, *ptr = start, *temp;
    int pos = 0, val, position;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the POSITION of the node u want to insert : ");
    scanf("%d", &position);
    printf("Enter the VALUE to insert : ");
    scanf("%d", &val);
    newnode->data = val;

    if (!start)
        printf("List is empty \n");

    while (ptr != NULL)
    {
        if (pos == position)
            break;
        temp = ptr;
        ptr = ptr->next;
        pos++;
    }
    temp->next = newnode;
    newnode->next = ptr;
    printf("***** Sucessfully Inserted *****");
}

void delele_position()
{
    struct node *ptr = start, *temp;
    int pos = 0, val, position;
    printf("\nEnter the POSITION of the node u want to insert : ");
    scanf("%d", &position);

    if (position == 0) // If first element of linked list is deleted
    {
        start = ptr->next;
        free(ptr);
    }

    while (ptr != NULL)
    {
        if (pos == position)
            break;
        temp = ptr;
        ptr = ptr->next;
        pos++;
    }
    temp->next = ptr->next;
    free(ptr);
    printf("***** Sucessfully Deleted *****");
}

void reversePrint(struct node *start)
{
    if (start == NULL)
    {
        printf("***** Printing Reverse linked - list :: *****\n");
        return;
    }
    reversePrint(start->next); //  Backtracking
    printf("%d\t", start->data);
}

/*Reverse
    SinglyLinkedListNode *prev = head,
                         *current = head->next, *aftr;

if (head == NULL)
    return head;
head->next = NULL;
while (current)
{
    aftr = current->next;
    current->next = prev;
    prev = current;
    current = aftr;
}

return prev;

void remove_duplicate()
{
    SinglyLinkedListNode *current = head->next, *prev = head, *temp;
    if (!head)
        return head;
    while (current != NULL)
    {
        if (prev->data == current->data)
        {
            temp = current;
            current = current->next;
            prev->next = current;
        }
        else
        {
            prev = current;
            current = current->next;
        }
    }

    return head;
} */