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
    n = (struct node *) malloc(sizeof(struct node)); // Allocating the memory in the heap
    n->data = data; // setting the data
    n->left = NULL; // setting the left and right children to NULL
    n->right = NULL; // setting the left and right children to NULL
    return n; // Finally returning the created node
};

// inOrder traversal is:(root->left => root => root-right )
// Note: InOrder traversal of a (BST) binary search tree gives an ascending sorted array
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
    struct node *p = createNode(9);
    struct node *p1 = createNode(4);
    struct node *p2 = createNode(11);
    struct node *p3 = createNode(2);
    struct node *p4 = createNode(7);
    struct node *p5 = createNode(5);
    struct node *p6 = createNode(8);
    struct node *p7 = createNode(15);
    struct node *p8 = createNode(14);
    // Finally The Binary_Search tree looks like this:
    //      9
    //     / \
    //    4   11
    //   / \   \
    //  2   7   15
    //     / \   /
    //    5  8  14

    // Linking the root node with left and right children
    // No need to declare Null 
    p->left = p1;
    p->right = p2;

    p1->left = p3;
    p1->right = p4;

    p2->left = NULL; // NO need to declare NULL p2->left = NULL;
    p2->right = p7;

    p3->right = NULL;
    p3->left = NULL;

    p4->right = p6;
    p4->left = p5;

    p5->left = NULL;
    p5->right = NULL;

    p6->left = NULL;
    p6->right = NULL;

    p7->right = NULL;
    p7->left = p8;

    p8->left = NULL;
    p8->right = NULL;

    inOrder(p); // calling inOrder_traversal func
    return 0;
}
