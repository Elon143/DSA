#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isStackEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
};

int isStackFull(struct stack *ptr)
{
    if (ptr->top == ptr->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    // struct stack s;
    // s.size = 80;
    // s.top = -1;
    // s.arr=(int *)malloc(s.size * sizeof(int) );

    struct stack *s = (struct stack *) malloc(sizeof(struct stack));
    s->size = 80;
    s->top = -1;
    s->arr = (int *) malloc(s->size * sizeof(int));
///////
    printf("Stack is created successfuly\n\n");
/////////
    // Pushing an element manually
    s->arr[0] = 7;
    s->top++;

    // // check if stack is empty
    if (isStackEmpty(s))
    {
            printf("The Stack is empty.");  
    }
    else
    {
        printf("The Stack is Not empty.");
    }

    return 0;
}