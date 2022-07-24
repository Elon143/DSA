#include <stdio.h>
#include<stdlib.h>

// Global variable declaration f, r
struct Node *f = NULL;
struct Node *r = NULL;

//// queue = [8][-]->[7][-]->[6][NULL]

struct Node
{
    int data;
    struct Node * next;
};

void linkedListTraversal(struct Node *ptr){
    printf("Printing the elements of this linked list\n");
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
    
}

void enqueue(int val){
    struct Node *n = (struct Node *) malloc(sizeof(struct Node));
    if(n==NULL){
        printf("Queue is Full");
    }
    else{
        n->data = val;
        n->next = NULL;
        if (f==NULL)
        {
            f = r = n;
        }
        else{
            r->next = n;
            r = n;
        }
        
    }

}

int dequeue(){
    int val = -1;
    struct Node *ptr = f;
    if(f==NULL){
        printf("Queue is Empty\n");
    }
    else{
        f = f->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}



int main(){
   
    printf("Dequeued element is: %d\n", dequeue());
    enqueue(45);
    enqueue(56);
    enqueue(98);
    linkedListTraversal(f);
    printf("Dequeued element is: %d\n", dequeue());
    linkedListTraversal(f);
    


    return 0;
}