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

void preorder(struct node * root){
    if (root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
    
}

void postorder(struct node * root){
    if (root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
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

    preorder(p); // Function preorder
    printf("\n");
    postorder(p); // calling functon postorder

    return 0;
}
