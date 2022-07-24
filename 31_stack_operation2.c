#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void linkedListTraversal(struct Node *ptr){
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
    
}

int isEmpty(struct Node* top){
    if(top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct Node* top){
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    if(p==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

struct Node* push(struct Node *top, int x){
    if(isFull(top)){
        printf("Stack Overflow!\n");
    }
    else{
        struct Node* n= (struct Node*)malloc(sizeof(struct Node));
        n->data = x;
        n->next = top;
        top =n;
        return top;
    }
};

int pop(struct Node* tp){
    if(isEmpty(tp)){
        printf("Stack Underflow!\n");
    }
    else{
        struct Node* n= tp;
        top = (tp)->next;
        int x = n->data;
        free(n);
        return x;
    }
};

// peek operation // pos= position
int peek(int pos){
    struct Node* ptr = top;
    for (int i = 0; (i < pos-1 && ptr!=NULL); i++)
    {
        ptr = ptr->next;
    }
    if(ptr != NULL)
    {
        return ptr->data;
    }
    else{
        return -1;
    }

}

int Stacktop(){
    return top->data;
}

// int StackBottom(){   // I have to write this function it is not complete

//     return StackBottom->data;
    

    
// }


int main(){
    // struct Node* top = NULL;
    top = push(top, 98);
    top = push(top, 8);
    top = push(top, 43);
    top = push(top, 9);

    linkedListTraversal(top);
    for (int i = 1; i <= 4; i++)
    {
        printf("Value at position %d is : %d\n", i, peek(i));
    }
    
    printf("Top value is: %d\n",Stacktop());
    // printf("Bottom value is: %d\n",StackBottom());  // This function is not complete
   
    


    return 0;
}