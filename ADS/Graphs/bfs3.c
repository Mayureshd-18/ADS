#include<stdio.h>
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

int isFull(struct queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q, int val){
    if(isFull(q)){
        printf("This Queue is full\n");
    }
    else{
        q->r++;
        q->arr[q->r] = val;
        // printf("Enqued element: %d\n", val);
    }
}

int dequeue(struct queue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("This Queue is empty\n");
    }
    else{
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

int main(){
    // Initializing Queue (Array Implementation)
    struct queue q;
    q.size = 400;
    q.f = q.r = 0;
    q.arr = (int*) malloc(q.size*sizeof(int));

    int noofvert;
    scanf("%d",&noofvert);
    int visited[noofvert] ;
    for(int i =0;i<noofvert;i++){
       visited[i] = 0;
    }


    int a [noofvert][noofvert];


    for(int s = 0;s<noofvert;s++){
        for(int t = 0;t<noofvert;t++){
            a[s][t] = 0;
        }
    }
    for(int i = 0;i<7;i++){
        for(int j = 0;j<7;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
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

    for(int i = 0;i<7;i++){
        for(int j = 0;j<7;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    int node;
    int i = 0;
    printf("%d", i);
    visited[i] = 1;
    enqueue(&q, i); // Enqueue i for exploration
    while (!isEmpty(&q))
    {
        int node = dequeue(&q);
        for (int j = 0; j < noofvert; j++)
        {
            if(a[node][j] ==1 && visited[j] == 0){
                printf("%d", j);
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
    }
    return 0;
}
