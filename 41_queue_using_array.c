#include <stdio.h>
#include<stdlib.h>

struct queue{
    int size;  // size of queue
    int f;  // front
    int r;  // rare
    int *arr;  // array
};

int isEmpty(struct queue *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}

int isFull(struct queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q, int val){
    if(isFull(q)){
        printf("Queue Overflow!(This Queue is Full)\n");
    }
    else{
        q->r++;
        q->arr[q->r] = val;
        printf("Enqueued value: %d\n", val);
    }
}

int dequeue(struct queue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("Queue Underflow!(This Queue is Empty)\n");
    }
    else{
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

/* int main(){
    struct queue q;
    q.size = 4;
    q.f = q.r = -1;
    q.arr = (int *) malloc(q.size * sizeof(int));
  
    // Enqueue few elements 
    enqueue(&q, 12);
    enqueue(&q, 0);
    enqueue(&q, 32);
    enqueue(&q, 1);
    
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q));

    if(isEmpty(&q)){
        printf("Queue is Empty\n");
    } 
    if(isFull(&q)){
        printf("Queue is Full\n");
    } 
    return 0;
}  */


// This main is  copy from 44_circular Queue
int main(){
    struct queue q;
    q.size = 6;
    q.f = q.r = 0;
    q.arr = (int *) malloc(q.size * sizeof(int));
  
    // Enqueue few elements 
    enqueue(&q, 12);
    enqueue(&q, 0);
    enqueue(&q, 32);
    enqueue(&q, 45);
    enqueue(&q, 1);

    // // i can  enque element = q.size-1 // means size = 6 // i can enqueue element 5
    // enqueue(&q, 9);  
     
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q));
    // printf("Dequeuing element %d\n", dequeue(&q));
    // // printf("Dequeuing element %d\n", dequeue(&q));

    // enqueue elemetn again
    enqueue(&q, 38);
    enqueue(&q, 19);
  
    
    

    if(isEmpty(&q)){
        printf("Queue is Empty\n");
    } 
    if(isFull(&q)){
        printf("Queue is Full\n");
    } 
    return 0;
}