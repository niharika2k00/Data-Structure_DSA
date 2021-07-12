
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct BST_Node
{
    int data;
    struct BST_Node *right; // right child
    struct BST_Node *left;  // left child
};
struct BST_Node *root = NULL, *newnode = NULL; // Global variables are declared here...

// prototypes of the declared functions
void insertNode();
void create();
void binarySearch(struct BST_Node *root);
void preOrder(struct BST_Node *tree);
void inOrder(struct BST_Node *tree);
void postOrder(struct BST_Node *tree);
void levelOrderTraversal(struct BST_Node *root);
bool checkNodeExsist(struct BST_Node *root, int key);

int main(void)
{
    int option, key;

    do
    {
        printf("\n \n **************** CHOOSE AN OPTION **********************");
        printf("\n \n 1. Create a Binary_Search_Tree.");
        printf("\n 2. Display the PRE-ORDER TRAVERSAL of the Binary_Search_Tree.");
        printf("\n 3. Display the IN-ORDER TRAVERSAL of the Binary_Search_Tree.");
        printf("\n 4. Display the POST-ORDER TRAVERSAL of the Binary_Search_Tree.");
        printf("\n 5. Display the LEVEL-ORDER TRAVERSAL using Queue of the Binary_Search_Tree.");
        printf("\n 6. Search if a node exsist or not.");
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
        case 2:
            cout << "______ Post-Order traversal of a Binary Search Tree ______\n";
            preOrder(root);
            break;
        case 3:
            cout << "______ Post-Order traversal of a Binary Search Tree ______\n";
            inOrder(root);
            break;
        case 4:
            cout << "______ Post-Order traversal of a Binary Search Tree ______\n";
            postOrder(root);
            break;
        case 5:
            cout << "______ Level-Order traversal of a Binary Search Tree ______\n";
            levelOrderTraversal(root);
            break;
        case 6:
            cout << "______ Node Exsist Checker of a Binary Search Tree ______\n";
            cout << "Enter a no. for searching : ";
            cin >> key;
            bool ans = checkNodeExsist(root, key);
            if (ans)
                cout << "YES " << key << " ALREADY EXSIST IN THE TREE \n";
            cout << "NO " << key << " NOT PRESENT IN THE TREE \n";
            break;
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
            //     Reverse(root);
            //     break;
            // case 13:
            //     search(root);
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
            //     reversePrint(root);
            //     break;
            // default:
            // printf("CHOOSE THE OPTION MENTIONED IN THE MENU.....");
            // break;
        }

    } while ((option >= 1) && (option <= 20));
    return 0;
}

// CREATION OF  Binary_Search_Tree.
void insertNode()
{
    create();
    if (root == NULL)
        root = newnode;
    else
        binarySearch(root);
    cout << "***** Successfully inserted a node in the Binary_Search_Tree  *******";
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
void binarySearch(struct BST_Node *tree)
{
    if ((newnode->data > tree->data) && (tree->right != NULL))
        binarySearch(tree->right);
    else if ((newnode->data > tree->data) && (tree->right == NULL))
        tree->right = newnode;
    else if ((newnode->data < tree->data) && (tree->left != NULL))
        binarySearch(tree->left);
    else if ((newnode->data < tree->data) && (tree->left == NULL))
        tree->left = newnode;
}

// PREORDER TRAVERSAL ---------  RECURSIVE METHOD
void preOrder(struct BST_Node *tree)
{
    if (tree == NULL)
    {
        printf("No elements in a tree to display ");
        return;
    }
    cout << tree->data << '\t';
    if (tree->left != NULL)
        preOrder(tree->left);
    if (tree->right != NULL)
        preOrder(tree->right);
}

// INORDER TRAVERSAL ---------  RECURSIVE METHOD
void inOrder(struct BST_Node *tree)
{
    if (tree == NULL)
    {
        printf("No elements in a tree to display ");
        return;
    }
    if (tree->left != NULL)
        preOrder(tree->left);
    cout << tree->data;
    if (tree->right != NULL)
        preOrder(tree->right);
}

// POST TRAVERSAL ---------  RECURSIVE METHOD
void postOrder(struct BST_Node *tree)
{
    if (tree == NULL)
    {
        printf("No elements in a tree to display ");
        return;
    }
    if (tree->left != NULL)
        preOrder(tree->left);
    if (tree->right != NULL)
        preOrder(tree->right);
    cout << tree->data;
}

// LEVEL ORDER TRAVERSAL using Queue
void levelOrderTraversal(struct BST_Node *root) //  Time Complexity : O(n)
{
    /* 
       =====  ALGORITHM ====== 
       if(root == NULL) return
       else
       {
          *  create a QUEUE data structure
          *  enqueue the root
          *  Loop unless Q not Empty 
                     --- print ---
                     Dequeue(remove) the front node
                     check its left child
                     check its right child
       }
    */

    if (root == NULL)
        return;

    queue<BST_Node *> Q;
    Q.push(root); // Enqueue

    while (!Q.empty())
    {
        BST_Node *FrontNode = Q.front();
        cout << FrontNode->data << "\t";
        Q.pop();

        // Enqueue left child
        if (FrontNode->left != NULL)
            Q.push(FrontNode->left);

        // Enqueue right child
        if (FrontNode->right != NULL)
            Q.push(FrontNode->right);
    }
}

bool checkNodeExsist(struct BST_Node *root, int key)
{
    bool responseL, responseR;
    if (root == NULL)
        return false;

    else if (root->data == key)
        return true;

    else if (root->left != NULL)
    {
        responseL = checkNodeExsist(root->left, key);
        if (responseL)
            return true;
    }

    else if (root->right != NULL)
    {
        responseR = checkNodeExsist(root->right, key);
        if (responseR)
            return true;
    }
    else
        return false;
}

// DELETING A SINGLE NODE
/* void delete ()
{
} */