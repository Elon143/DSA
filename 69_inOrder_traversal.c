#include<stdio.h>
#include<malloc.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data)
{
    struct node *n; // creating a node pointer
    n = (struct node *) malloc(sizeof(struct node)); // Allocating the memOry in the heap
    n->data = data; // setting the data
    n->left = NULL; // setting the left and right children to NULL
    n->right = NULL; // setting the left and right children to NULL
    return n; // Finally returning the created node
};

// preOrder traversal is:( root => root->left => root-right)
void preOrder(struct node * root){
    if (root!=NULL)
    {
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
    
}

// postOrder traversal is:(root->left => root-right => root)
void postOrder(struct node * root){
    if (root!=NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->data);
    }
    
}

// inOrder traversal is:(root->left => root => root-right )
void inOrder(struct node * root){
    if (root!=NULL)
    {
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
    
}

int main(){
   // Construction the root node - Using Function (Recommended)
    struct node *p = createNode(4);
    struct node *p1 = createNode(1);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(5);
    struct node *p4 = createNode(2);
    // Finally The tree looks like this:
    //      4
    //     / \
    //    1   6
    //   / \
    //  5   2

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    // preOrder(p); // Function preOrder traversal
    // printf("\n");
    // postOrder(p); // calling functon postOrder traversal
    // printf("\n");
    inOrder(p); // calling inOrder traversal

    return 0;
}
