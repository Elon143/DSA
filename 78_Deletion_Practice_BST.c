#include<stdio.h>
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


int main(){
    // Construction the root node - Using Function (Recommended)
    struct node *p = createNode(11);
    struct node *p1 = createNode(8);
    struct node *p2 = createNode(13);
    struct node *p3 = createNode(6);
    struct node *p4 = createNode(9);
    // Finally The tree looks like this:
    //      11
    //     / \
    //    8   13
    //   / \
    //  6   9

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    inOrder(p);
    deleteNode(p,13);
    // deleteNode(p,11);
    printf("\n");
    printf("|Data is %d |\n",p->data); // This will print main root of the tree
    inOrder(p);
    
    return 0;
}