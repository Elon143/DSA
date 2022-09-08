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
// in Order Predecessor
struct node* inOrderPredecessor(struct node * root){
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
    
}

// Function to deleteNode
struct node *deleteNode(struct node *root, int value){
    struct node* iPre;
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }
    
    
    // search for the node to be deleted
    if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }
    // Deletion strategy // Now we reached the node and we need to delete let se
    else{
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = deleteNode(root->left, iPre->data);
    }
    return root; 
}


// This is main function Starts from here
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

    inOrder(p);
    // deleteNode(p,4);
    deleteNode(p,5);
    printf("\n");
    printf("|Data is %d |\n",p->data); // This will print main root of the tree
    inOrder(p);

    return 0;
}
