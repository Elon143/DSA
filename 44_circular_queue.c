#include <stdio.h>
#include<stdlib.h>

struct circularQueue{
    int size;  // size of queue
    int f;  // front
    int r;  // rare
    int *arr;  // array
};

int isEmpty(struct circularQueue *cq){
    if(cq->r==cq->f){
        return 1;
    }
    return 0;
}

int isFull(struct circularQueue *cq){
    if((cq->r+1)%cq->size == cq->f){
        return 1;
    }
    return 0;
}

void enqueue(struct circularQueue *cq, int val){
    if(isFull(cq)){
        printf("Queue Overflow!(This Queue is Full)\n");
    }
    else{
        cq->r = (cq->r +1)%cq->size;
        cq->arr[cq->r] = val;
        printf("Enqued element: %d\n", val);
    }
}

int dequeue(struct circularQueue *cq){
    int a = -1;
    if(isEmpty(cq)){
        printf("Queue Underflow!(This Queue is Empty)\n");
    }
    else{
        cq->f = (cq->f+1)%cq->size;
        a = cq->arr[cq->f];
    }
    return a;
}

// CircularQueue
int main(){
    struct circularQueue cq;
    cq.size = 6;
    cq.f = cq.r = 0;
    cq.arr = (int *) malloc(cq.size * sizeof(int));
  
    // Enqueue few elements 
    enqueue(&cq, 12);
    enqueue(&cq, 0);
    // enqueue(&cq, 32);
    // enqueue(&cq, 1);

    // // i can  enque element = cq.size-1 // means size = 6 // i can enqueue element 5
    // enqueue(&cq, 9);  
     
    printf("Dequeuing element %d\n", dequeue(&cq));
    printf("Dequeuing element %d\n", dequeue(&cq));
    // printf("Dequeuing element %d\n", dequeue(&cq));
    // // printf("Dequeuing element %d\n", dequeue(&cq));

    // enqueue elemetn again
    enqueue(&cq, 38);
    enqueue(&cq, 19);
  
    
    

    if(isEmpty(&cq)){
        printf("Queue is Empty\n");
    } 
    if(isFull(&cq)){
        printf("Queue is Full\n");
    } 
    return 0;
}