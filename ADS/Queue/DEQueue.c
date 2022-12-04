#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int f;
    int r;
    int *arr;
    int size;
};

int isFull(struct Queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    return 0;
}

int isEmpty(struct Queue *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}
void display(struct Queue * q){
    for(int i =q->f+1;i<q->size;i++){
        printf("%d ",q->arr[i]);
    }
    printf("\n");
}

void deQueueR(struct Queue *q){
    if(isEmpty(q)){
        printf("Cant dequeue. Queue is empty");
        return;
    }
    q->r = q->r-1;

}
void deQueueF(struct Queue *q){
    if(isEmpty(q)){
        printf("Cant dequeue. Queue is empty");
        return;
    }
    q->f = q->f+1;

}



void enqueueR(struct Queue *q,int val){
    if(isFull(q)){
        printf("Queue overflow\n");
        return;
    }
    q->r =  q->r+1;
    q->arr[q->r] = val;
}

void enqueueF(struct Queue *q,int val){
    if(isFull(q)){
        printf("Queue overflow\n");
        return;
    }
    q->f =  q->f-1;
    q->arr[q->f] = val;
}

int main(void){
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    q->size = 5;
    q->f = q->r=-1;
    q->arr = (int *)malloc(q->size*sizeof(int));
    enqueueR(q,12);
    enqueueR(q,24);
    enqueueF(q,36);
//    enqueue(q,48);
//    enqueue(q,60);
    display(q);
//    deQueue(q);
//    display(q);
//    deQueue(q);
//    deQueue(q);
//    deQueue(q);
//    deQueue(q);
//    display(q);
//    enqueue(q,56);


}