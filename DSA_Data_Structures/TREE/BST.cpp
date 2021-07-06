
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct BST_Node
{
    int data;
    struct BST_Node *right;
    struct BST_Node *left;
};
struct BST_Node *start = NULL, *newnode = NULL; // Global variables are declared here...

void insertNode();
void create();
void binarySearch(struct BST_Node *root);

int main(void)
{
    int option;
    do
    {
        printf("\n \n **************** CHOOSE AN OPTION **********************");
        printf("\n \n 1. Create a Binary_Search_Tree.");
        printf("\n 2. Display a Binary_Search_Tree.");
        printf("\n 3. Display the PRE-ORDER TRAVERSAL of the Binary_Search_Tree.");
        printf("\n 4. Display the IN-ORDER TRAVERSAL of the Binary_Search_Tree.");
        printf("\n 5. Display the POST-ORDER TRAVERSAL of the Binary_Search_Tree.");
        printf("\n 6. Delete a node from BST.");
        printf("\n 7. Delete a node from the beginning.");
        printf("\n 8. Delete a node from the END.");
        printf("\n 9. Delete any given NODE.");
        printf("\n 10. Delete the entire Binary_Search_Tree.");
        printf("\n 11. MAXIMUM node value in the whole Binary_Search_Tree.  ");
        printf("\n 12. REVERSE the Binary_Search_Tree. ");
        printf("\n 13. Search an element in the Binary_Search_Tree.");
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
            insertNode();
            break;
        // case 2:
        //     display(start);
        //     // display();
        //     break;
        // case 3:
        //     addbeginning();
        //     break;
        // case 4:
        //     addend();
        //     break;
        // case 5:
        //     addbefr_givennode();
        //     break;
        // case 6:
        //     addaftr_givennode();
        //     break;
        // case 7:
        //     delbeginning();
        //     break;
        // case 8:
        //     delend();
        //     break;
        // case 9:
        //     delany_givennode();
        //     break;
        // case 10:
        //     delentire_linkedlist();
        //     break;
        // case 11:
        //     maxNode();
        //     break;
        // case 12:
        //     // Reverse();
        //     Reverse(start);
        //     break;
        // case 13:
        //     search(start);
        //     break;
        // case 14:
        //     delodd_ele();
        //     break;
        // case 15:
        //     findsum();
        //     break;
        // case 16:
        //     insertele_position();
        //     break;
        // case 17:
        //     delele_position();
        //     break;

        // case 18:
        //     reversePrint(start);
        //     break;
        default:
            printf("CHOOSE THE OPTION MENTIONED IN THE MENU.....");
            break;
        }

    } while ((option >= 1) && (option <= 20));
    return 0;
}

// CREATION OF  Binary_Search_Tree.
void insertNode()
{
    create();
    if (start == NULL)
        start = newnode;
    else
        binarySearch(start);
    cout << "***** Successfully created a node in the Binary_Search_Tree  *******";
}

void create()
{
    int value;
    cout << "Enter the DATA  of the node to be inserted : ";
    cin >> value;
    newnode = (struct BST_Node *)malloc(sizeof(struct BST_Node));
    newnode->data = value;
    newnode->left = newnode->right = NULL;
}

// finding the position of the NEWNODE
void binarySearch(struct BST_Node *root)
{
    if ((newnode->data > root->data) && (root->right != NULL))
        binarySearch(root->right);
    else if ((newnode->data > root->data) && (root->right == NULL))
        root->right = newnode;
    else if ((newnode->data < root->data) && (root->left != NULL))
        binarySearch(root->left);
    else if ((newnode->data < root->data) && (root->left == NULL))
        root->left = newnode;
}

// PREORDER TRAVERSAL ---------  RECURSIVE METHOD
void preOrder()
{
}
// INORDER TRAVERSAL ---------  RECURSIVE METHOD
void inOrder()
{
}
// POST TRAVERSAL ---------  RECURSIVE METHOD
void post()
{
}

// DELETING A SINGLE NODE
void dekete()
{
}