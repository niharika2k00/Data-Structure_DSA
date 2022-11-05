
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
int tree_height(struct BST_Node *root);
void ancestors(struct BST_Node *root, int val);
BST_Node *commonAncestors(struct BST_Node *root, int a, int b);
BST_Node *deleteNode(struct BST_Node *root, int key);
void isHeap(struct BST_Node *root);

int main(void)
{
    BST_Node *nodeVal;
    int option, key, height, ans, a, b;
    bool res;

    do
    {
        printf("\n \n **************** CHOOSE AN OPTION **********************");
        printf("\n \n 1. Create a Binary_Search_Tree.");
        printf("\n 2. Display the PRE-ORDER TRAVERSAL of the Binary_Search_Tree.");
        printf("\n 3. Display the IN-ORDER TRAVERSAL of the Binary_Search_Tree.");
        printf("\n 4. Display the POST-ORDER TRAVERSAL of the Binary_Search_Tree.");
        printf("\n 5. Display the LEVEL-ORDER TRAVERSAL using Queue of the Binary_Search_Tree.");
        printf("\n 6. Search if a node exsist or not.");
        printf("\n 7. Height of the Tree.");
        printf("\n 8. Ancestors of a Node in BST .");
        printf("\n 9. Common Ancestors of 2 Nodes in BST.");
        printf("\n 10. Delete a NODE in BST.");
        printf("\n 11. Check whether this BST is a Heap or Not .\n");
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
            ans = checkNodeExsist(root, key);
            if (ans)
                cout << "YES " << key << " ALREADY EXSIST IN THE TREE \n";
            else
                cout << "NO " << key << " NOT PRESENT IN THE TREE \n";
            break;
        case 7:
            height = tree_height(root);
            cout << "Height of the Binary Tree ---->  " << height << endl;
            break;
        case 8:
            cout << "______ Ancestors of a NODE in a Binary Search Tree ______\n";
            cout << "Enter a no. for whose ancestor you want to find: ";
            cin >> key;
            ancestors(root, key);
            break;
        case 9:
            cout << "______ Common Ancestors of 2 NODE in a Binary Search Tree ______\n";
            cout << "Enter 2 values  for whose Common Ancestors you want to find: ";
            cin >> a >> b;
            nodeVal = commonAncestors(root, a, b);
            cout << nodeVal->data << "\t";
            break;
        case 10:
            cout << "______ Delete a NODE in BST ______\n";
            cout << "Node You Want to Delete : ";
            cin >> key;
            deleteNode(root, key);
            break;
        case 11:
            isHeap(root);
            break;
        default:
            printf("CHOOSE THE OPTION MENTIONED IN THE MENU.....");
            break;
        }

    } while ((option >= 1) && (option <= 20));
    return 0;
}

// __________________   CREATION OF  Binary_Search_Tree.    _________________
void create()
{
    int value;
    cout << "Enter the DATA  of the node to be inserted : ";
    cin >> value;
    newnode = (struct BST_Node *)malloc(sizeof(struct BST_Node));
    newnode->data = value;
    newnode->left = newnode->right = NULL;
}

void insertNode()
{
    create();
    if (root == NULL)
        root = newnode;
    else
        binarySearch(root);
    cout << "***** Successfully inserted a node in the Binary_Search_Tree  *******";
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
// __________________________________________________________________________

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

// LEVEL ORDER TRAVERSAL   OR    BREADTH FIRST SEARCH (BFS)   using Queue      Iterative BFS
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
                     check its left child     ? Q.push()
                     check its right child   ? Q.push()
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

    if (root->data == key)
        return true;

    if (root->left) //  If Exsist
    {
        responseL = checkNodeExsist(root->left, key);
        if (responseL)
            return true;
    }
    if (root->right)
    {
        responseR = checkNodeExsist(root->right, key);
        if (responseR)
            return true;
    }
}

// Find HEIGHT / DEPTH  of a tree, defined by the root node
int tree_height(struct BST_Node *root) // Depth of the tree
{
    int leftHt, rightHt;
    if (!root)
        return 0;
    else
    {
        // Find the height of left, right subtrees
        leftHt = tree_height(root->left);
        rightHt = tree_height(root->right);

        // Find max(subtree_height) + 1 to get the height of the tree
        return max(leftHt, rightHt) + 1;
    }
}

// Find all the ANCESTORS (Parent)  of a node
void ancestors(struct BST_Node *root, int val)
{
    if (root == NULL)
        return;
    if (root->data == val) // void return --> jumps out of the function
        return;
    if (val > root->data)
    {
        cout << root->data << "\t";
        ancestors(root->right, val);
    }
    if (val < root->data)
    {
        cout << root->data << "\t";
        ancestors(root->left, val);
    }
}

BST_Node *commonAncestors(struct BST_Node *root, int a, int b)
{
    if (a > root->data && b > root->data)
        return commonAncestors(root->right, a, b);

    if (a < root->data && b < root->data)
        return commonAncestors(root->left, a, b);

    // cout << root->data << "\t";
    return root;
}

//  ------------------------------------------------------
// DELETE A NODE OF A BINARY TREE
// -------------------------------------------------------

BST_Node *LastRightChild_Finder(BST_Node *root)
{
    if (root->right == NULL) // means Last Child
        return root;

    LastRightChild_Finder(root->right);
}

BST_Node *Helper(BST_Node *root)
{
    if (root->right == NULL)
        return root->left;

    if (root->left == NULL)
        return root->right;

    BST_Node *RightChild = root->right;
    BST_Node *LastChild = LastRightChild_Finder(root->left); //  Root->Left Max Node(at the right) will get connected with the Right SubTree.
    LastChild->right = RightChild;

    return root->left;
}

BST_Node *deleteNode(struct BST_Node *root, int key)
{
    if (!root)
        return NULL;

    if (root->data == key)
        Helper(root);

    BST_Node *storeRoot = root; // storing the root as later it may change

    while (root != NULL)
    {
        if (key > root->data) //  Right Subtree
        {
            if (root->right && root->right->data == key)
            {
                root->right = Helper(root->right);
                break;
            }
            else
                root = root->right;
        }

        else if (key < root->data) // Left Subtree
        {
            if (root->left && root->left->data == key)
            {
                root->left = Helper(root->left);
                break;
            }
            else
                root = root->left;
        }
    }

    return storeRoot;
}

// _______________________   COUNT NUMBER OF NODES   _________________________
int countNodes(struct BST_Node *root)
{
    if (root == NULL)
        return 0;
    else
        return (countNodes(root->left) + countNodes(root->right) + 1); // left subtree + right subtree + 1
}

// checking Complete Binary_Search_Tree or Not
// ITERATIVE METHOD  -----
bool checkCompleteBT_iterative(struct BST_Node *root) // Iterative Method for checking Complete Binary_Search_Tree or Not
{
    bool flag = true;
    queue<BST_Node *> Q;
    Q.push(root);

    while (!Q.empty())
    {
        BST_Node *temp = Q.front();
        Q.pop();

        if (temp->left) // exsist ?
        {
            if (flag == false)
                return false;

            Q.push(temp->left);
        }
        else
            flag = false; // Not Binary Tree
        // ------------------------
        if (temp->right)
        {
            if (flag == false)
                return false;

            Q.push(temp->right);
        }
        else
            flag = false;
    }
    return true;
}

// RECURSIVE METHOD -----
bool checkCompleteBT_recursive(struct BST_Node *root, int index, int totalNodes)
{
    if (root == NULL)
        return true;

    if (index >= totalNodes)
        return false;

    return (checkCompleteBT_recursive(root->left, 2 * index + 1, totalNodes) && checkCompleteBT_recursive(root->right, 2 * index + 1, totalNodes));
}

bool heapCheck(struct BST_Node *root)
{

    if (root->left == NULL && root->right == NULL)
        return true;

    // only Check Right Subtree as ----------->  for Complete BT Right subtree doesnt exsist without Left
    if (root->right == NULL)
        return (root->data >= root->left->data); // as MaxHeap

    else
    {
        if (root->data >= root->left->data && root->data >= root->right->data)
            return ((heapCheck(root->left)) && (heapCheck(root->right)));
        else
            return (false);
    }
}

void isHeap(struct BST_Node *root)
{
    int totalNodes = countNodes(root), index = 0;
    // bool checkComplete = checkCompleteBT_iterative(root);
    bool checkComplete = checkCompleteBT_recursive(root, index, totalNodes);
    bool checkHeap = heapCheck(root);

    if (checkComplete && checkHeap)
        cout << "It is a Complete Binary Tree as well as follows HEAP" << endl;
    else
        cout << "OOpssss this tree is not a Heap  !! " << endl;
}