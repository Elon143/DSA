#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr!=NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
    
};

//Case 1: Insert At the beginning (func)
struct Node * insertAtFirst(struct Node *head, int data)
{
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = head;
    return ptr;
   
    
};

//Case 2: Insert At between (Index)

struct Node * insertAtIndex(struct Node *head, int data, int index){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    struct Node * p = head;
    int i = 0;

    while (i!=index-1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
    
    
}

//Case 3: Insert At End (last me insert)
struct Node * insertAtEnd(struct Node *head, int data)
{
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node * p = head;

    while (p->next!=NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
     
       
};

//Case 4: Insert After Node (Given Node) // we can say given address where we have to insert
struct Node * insertAfterNode(struct Node *head, struct Node  *prevNode,  int data)
{
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
       
};



int main(){
    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * fourth;
    
    // Allocate memory for nodes in  the linked list in Heap
    head = (struct Node *) malloc(sizeof(struct Node));
    second = (struct Node *) malloc(sizeof(struct Node));
    third = (struct Node *) malloc(sizeof(struct Node));
    fourth = (struct Node *) malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data = 7;
    head->next = second;

    // Link second and third nodes
    second->data = 45;
    second->next = third;

    // Link third and fourth nodes
    third->data = 31;
    third->next = fourth;

    // Terminate the list at the fourth node
    fourth->data = 2024;
    fourth->next = NULL;
    
    printf("Linked list before Insertion\n");
    linkedListTraversal(head);
    // head = insertAtFirst(head, 90);
    // head = insertAtIndex(head, 300, 2);
    // head = insertAtEnd(head, 30);
    head = insertAfterNode(head, third, 99);
    printf("Linked list After Insertion\n");
    linkedListTraversal(head);
   

    return 0;
}