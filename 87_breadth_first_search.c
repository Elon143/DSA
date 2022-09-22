#include <stdio.h>
#include<stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int* arr;
};

int isEmpty(struct queue *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}

int isFull(struct queue *q)
{
    if (q->r==q->size-1)
    {
        return 1;
    }
    return 0; 
};

void enqueue(struct queue *q, int val){
    if (isFull(q))
    {
        printf("This Queue is full\n");
    }
    else{
        q->r++;
        q->arr[q->r] = val;
        // printf("ENqued element is: %d\n, val");
    }
    
}

int dequeue(struct queue *q){
    int a = -1;
    if (isEmpty(q))
    {
        printf("This Queue is Empty\n");
    }
    else{
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

int main(){
    // Initiating Queue (Array Implementation)
    struct queue q;
    q.size = 400;
    q.f = q.r = 0;
    q.arr = (int *) malloc(q.size*sizeof(int));

    // BFS -> Breadth First Search, Implementation
    int node;
    int i = 0;
    int visited[7] = {0,0,0,0,0,0,0};
    // Graph [7][7]
    //   0--1
    //   |\ |
    //   2--3
    //   \  /
    //    4
    //   / \
    //  5   6
    

    int a [7][7] = {
        // This is from code with harry 
        {0,1,1,1,0,0,0}, // 0
        {1,0,1,0,0,0,0}, // 1
        {1,1,0,1,1,0,0}, // 2
        {1,0,1,0,1,0,0}, // 3
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0},

// This is by me
 /*   //   0 1 2 3 4 5 6
        {0,1,1,1,0,0,0}, // 0
        {1,0,0,1,0,0,0}, // 1
        {1,0,0,1,1,0,0}, // 2
        {1,1,1,0,1,0,0}, // 3
        {0,0,1,1,0,1,1}, // 4
        {0,0,0,0,1,0,0}, // 5
        {0,0,0,0,1,0,0}, // 6
 */       
    };
    printf("%d", i);
    visited[i] = 1;
    enqueue(&q, i); // Enqueue i for exploration
    while (!isEmpty(&q))
    {
        int node = dequeue(&q);
        for (int j = 0; j < 7; j++)
        {
            if (a[node][j] ==1 && visited[j] == 0)
            {
                printf("%d", j);
                visited[j] = 1;
                enqueue(&q, j);
            }
            
        }
        
    }
    

    return 0;
}