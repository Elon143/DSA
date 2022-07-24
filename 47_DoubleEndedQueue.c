#include <stdio.h>
#include<stdlib.h>

// **** I have doubt to write its isEmpty condition and isFull, I have to ask it with someone i dont know this , this time this is wrong

struct queue{
    int size;  // size of queue
    int f;  // front
    int r;  // rare
    int *arr;  // array
};



int isEmpty(struct queue *q){
    if(q->f==q->r){
        return 1;
    }
    return 0;
}

int isFull(struct queue *q){
    if(q->f == -1 && q->r==q->size-1){
        return 1;
    }
    return 0;
}


// Enqueue from Rear
void enqueueRear(struct queue *q, int val){
    if(isFull(q)){
        printf("queue Overflow!(This queue is Full)\n");
    }
    else{
        q->r++;
        q->arr[q->r] = val;
        printf("Enqueued value: %d\n", val);
    }
}

// //  dequing from rear, r ***********

int dequeueRear(struct queue *q){
    int a = 1;
    if(isEmpty(q)){
        printf("queue Underflow!(This queue is Empty)\n");
    }
    else{
        a = q->arr[q->r];
        q->r--;
    }
    return a;
}

// deletion from front f
int dequeueFront(struct queue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("queue Underflow!(This queue is Empty)\n");
    }
    else{
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}


void enqueueFront(struct queue *q, int val){
    if(isFull(q)){
        printf("You can not enter element\n");
    }
    else{
        q->arr[q->f] = val;
        q->f--;
        printf("Enqueued value: %d\n", val);
    }
}


int main(){
    struct queue q;
    q.size = 5;
    q.f = q.r = -1;
    q.arr = (int *) malloc(q.size * sizeof(int));
    // int i=0;
  
    // Enqueue few elements 
    enqueueRear(&q, 0);
    enqueueRear(&q, 88);
    enqueueRear(&q, 76);
    enqueueRear(&q, 76);
    enqueueRear(&q, 69);
    // enqueueRear(&q, 98);
    // enqueueFront(&q, 12);
    // enqueueFront(&q, 92);
    // enqueueFront(&q, 8);
    // enqueueFront(&q, 48);
    for (int i = 0; i < q.size; i++)
    {
        printf("%d ", q.arr[i]);
    }
    printf("%d\n");
   
    
    printf("Dequeuing element %d\n", dequeueFront(&q));
    printf("Dequeuing element %d\n", dequeueFront(&q));
    // enqueueFront(&q, 92);
    // enqueueFront(&q, 92);
    // printf("Dequeuing element %d\n", dequeueFront(&q));
 
    // printf("Dequeuing element %d\n", dequeueRear(&q));
    // printf("Dequeuing element %d\n", dequeueRear(&q));
    // printf("Dequeuing element %d\n", dequeueRear(&q));
    // enqueueRear(&q, 66);
    // enqueueRear(&q, 65);
    // enqueueRear(&q, 69);

    for (int i = 0; i < q.size; i++)
    {
        printf("%d ", q.arr[i]);
    }
    printf("%d\n");
    
    

    if(isEmpty(&q)){
        printf("queue is Empty\n");
    } 
    if(isFull(&q)){
        printf("queue is Full\n");
    } 
    return 0;
};  
