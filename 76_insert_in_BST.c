#include <stdio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *n;                                 // creating a node pointer
    n = (struct node *)malloc(sizeof(struct node)); // Allocating the memOry in the heap
    n->data = data;                                 // setting the data
    n->left = NULL;                                 // setting the left and right children to NULL
    n->right = NULL;                                // setting the left and right children to NULL
    return n;                                       // Finally returning the created node
};

// preOrder traversal is:( root => root->left => root-right)
void preOrder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// postOrder traversal is:(root->left => root-right => root)
void postOrder(struct node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

// inOrder traversal is:(root->left => root => root-right )
void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// checking prev value
int isBST(struct node *root)
{
    static struct node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}

// Function to search value in BST Iteratively (Itrative Strategy)
struct node *searchIter(struct node *root, int key)
{
    while (root != NULL)
    {
        if (key == root->data)
        {
            return root;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return NULL;
}

// inserting a value in BinarySearchTree
void insert(struct node *root, int key){
    struct node *prev = NULL;
    while (root!=NULL)
    {
        prev = root;
        if (key==root->data)
        {
            printf("Cannot insert %d, already in BST\n",key);
            return;
        }
        else if (key<root->data)
        {
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    struct node* newNode = createNode(key);
    if (key<prev->data)
    {
        prev->left = newNode;
    }
    else{
        prev->right = newNode;
    }
    
}

int main()
{
    // Construction the root node - Using Function (Recommended)
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);
    // Finally The tree looks like this:
    //      5
    //     / \
    //    3   6
    //   / \
    //  1   4

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    insert(p,7);
    printf("Inserted Element is: %d\n",p->right->right->data);
    // printf("Inserted Element is: %d\n",p2->right->data); // work of both are same 

    insert(p,2);
    printf("Inserted Element is: %d\n",p3->right->data); 
    
    insert(p,4); // cannot insert because 4 already exist in BST
    printf("Inserted Element is: %d\n",p4->right->data); 

    return 0;
}
