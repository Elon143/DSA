#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isFull(struct stack* ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(struct stack* ptr){
    if(ptr->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}
void push(struct stack* ptr, int val){
    if(isFull(ptr)){
        printf("Stack overflow! = means cannot push element(%d) to the stack \n", val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}


int main(){
    struct stack *sp = (struct stack *) malloc(sizeof(struct stack));
    sp->size = 8;
    sp->top = -1;
    sp->arr=(int *) malloc(sp->size  * sizeof(int));
    printf("Stack has been created successfully\n");

    printf("Before pushing, Full: %d\n", isFull(sp));
    printf("Before pushing, Empty: %d\n", isEmpty(sp));
    // element pushing now
    push(sp, 44);
    push(sp, 44);
    push(sp, 44);
    push(sp, 44);
    push(sp, 84);
    push(sp, 84);
    push(sp, 34);
    push(sp, 44);
    // push(sp, 445);  // --> Pushed 10 values
    // push(sp, 45);  // Stack Overflow since the size of the stack is 10
    
    

    printf("After pushing, Full: %d\n", isFull(sp));
    printf("After pushing, Empty: %d\n", isEmpty(sp));
// Last in first out (LIFO)
    printf("Popped %d from the stack\n", pop(sp));
    printf("Popped %d from the stack\n", pop(sp));  // Last in first out (LIFO)
    printf("Popped %d from the stack\n", pop(sp));  // Last in first out (LIFO)

    return 0;
}