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

//Case 1: Deleting the first element from the linked list
struct Node * deleteFirst(struct Node *head)
{
   
    struct Node * ptr = head;
    head = head->next;
    free(ptr);
     
    return head;
    
};

//Case 2: Deleting the element at a given index from the linked list
struct Node * deleteAtIndex(struct Node *head, int index){
    struct Node *p = head;
    struct Node *q = head->next;
    for (int i = 0; i < index-1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    
    free(q);

    return head;
}

//Case 3: Deleting the last element 
struct Node * deleteAtLast(struct Node *head)
{
   
    struct Node *p = head;
    struct Node *q = head->next;
    while(q->next!=NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;         
    free(q);
    
    

    return head;
       
};

//Case 4: Deleting the element with a given value from the linked list
struct Node * deleteGivenValue(struct Node *head, int value){
    struct Node *p = head;
    struct Node *q = head->next;

    while(q->data!=value && q->next!= NULL)
    {
        p = p->next;
        q = q->next;
    }

    if(q->data == value){
        p->next = q->next;
        free(q);
    }

    return head;
}






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
    fourth->data = 224;
    fourth->next = NULL;
    
    printf("Linked list before Deletion\n");
    linkedListTraversal(head);
    // For deleting first element of the linked list
    // head = deleteFirst(head); 

    // For deleting At Index element of the linked list
    // head = deleteAtIndex(head, 2);

    // For deleting End(last) element of the linked list
    // head = deleteAtLast(head);

    // For deleting Given value of the linked list
    head = deleteGivenValue(head, 224);
    printf("Linked list After Deletion\n");
    linkedListTraversal(head);
   

    return 0;
}