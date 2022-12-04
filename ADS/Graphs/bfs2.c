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

int dequeue(struct Queue *q){
    if(isEmpty(q)){
        printf("Cant dequeue. Queue is empty");
        return -1;
    }
    q->front++;
    return q->front-1;

}

void display(struct Queue * q){
    for(int i =q->front+1;i<q->rear+1;i++){
        printf("%d ",q->arr[i]);
    }
    printf("\n");
}

int main(void){
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    q->size = 100;
    q->front =q->rear = 0;
    q->arr = (int *)malloc(q->size*sizeof(int));

    int node;
    int i = 1;
    int visited[7] = {0,0,0,0,0,0,0};
    int a [7][7];


    for(int s = 0;s<7;s++){
        for(int t = 0;t<7;t++){
            a[s][t] = 0;
        }
    }

    for(int k = 0;k<21;k++){
        printf("Enter start and end points:\n");
        int x,y;
        scanf("%d %d",&x,&y);
        if(x==-1 && y==-1){
            break;
        }
        a[x][y] = 1;
        a[y][x] = 1;
    }

//    for(int i = 0;i<7;i++){
//        for(int j = 0;j<7;j++){
//            printf("%d ",a[i][j]);
//        }
//        printf("\n");
//    }

    printf("%d", i);
    visited[i] = 0;
    enqueue(q, i);
    while (!isEmpty(q))
    {
        node = dequeue(q);
        for (int j = 0; j < 7; j++)
        {
            if(a[node][j] ==1 && visited[j] == 0){
                printf("%d ", j);
                visited[j] = 1;
                enqueue(q, j);
            }
        }
    }


}