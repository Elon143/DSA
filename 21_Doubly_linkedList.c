#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node * prev;
    struct Node * next;
};


// // Doubly linked list traversal
void linkedListTraversal(struct Node *N1)
{
    struct Node *ptr = N1;
    do
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
        
    }while (ptr!=N1);
    
};


// struct Node * prevListTraversal(struct Node * N1){
//      struct Node *ptr = N1;
//     //  do
//     // {
//     //     printf("Element: %d\n", ptr->data);
//     //     ptr = ptr->next;
        
//     // }while (ptr!=N1);
//     do
//     {
//         printf("Element: %d\n", ptr->data);
//         ptr = ptr->prev;
//     } while (N1!=NULL);
    
// }

int main(){
    // creating nodes // n1 = node1 
    struct Node * N1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node * N2 = (struct Node *)malloc(sizeof(struct Node));
    struct Node * N3 = (struct Node *)malloc(sizeof(struct Node));
    struct Node * N4 = (struct Node *)malloc(sizeof(struct Node));
    struct Node * N5 = (struct Node *)malloc(sizeof(struct Node));

    // link nodes
    N1->data = 34;
    N1->next = N2;
    N1->prev = NULL;

    // link N2 to N1 and N3
    N2->data = 21;
    N2->next = N3;
    N2->prev = N1;

    // N3 ko N4 aur N2 se link kiya gaya
    N3->data = 4;
    N3->next = N4;
    N3->prev = N2;

    // N4
    N4->data = 6;
    N4->next = N5;
    N4->prev = N3;

    // N5
    N5->data = 7;
    N5->next = NULL;
    N5->prev = N4;

    printf("Doubly Linked list Traversal\n");
    linkedListTraversal(N1);
    // prevListTraversal(N1);

    return 0;
}