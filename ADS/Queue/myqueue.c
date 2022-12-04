#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int front;
    int rear;
    int * arr;
    int size;
};

int isEmpty(struct Queue *q){
    if(q->rear==q->front){
        return 1;
    }
    return 0;
}

int isFull(struct Queue *q){
    if(q->rear==q->size-1){
        return 1;
    }
    return 0;
}

void enqueue(struct Queue *q,int data){
    if(isFull(q)){
        printf("Cant enqueue. Queue is full");
        return;
    }
    else{
        q->rear++;
        q->arr[q->rear] = data;
    }
}

void dequeue(struct Queue *q){
    if(isEmpty(q)){
        printf("Cant dequeue. Queue is empty");
        return;
    }
    q->front++;

}

void display(struct Queue * q){
    for(int i =q->front+1;i<q->rear+1;i++){
        printf("%d ",q->arr[i]);
    }
    printf("\n");
}

int main(void){
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    q->size = 5;
    q->front =q->rear = -1;
    q->arr = (int *)malloc(q->size*sizeof(int));

    enqueue(q,5);
    dequeue(q);
    dequeue(q);

    display(q);
}