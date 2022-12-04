#include <stdio.h>
#include <stdlib.h>

struct Stack{
    int sizes;
    int *arrs;
    int top;
};

struct Queue{
    int sizeq;
    int f;
    int r;
    int *arrq;
};





int isEmptyStack(struct Stack * s){
    if(s->top==-1){
        return 1;
    }
    return 0;
}

int isFullStack(struct Stack *s){
    if(s->top==s->sizes-1){
        return 1;
    }
    return 0;
}

void pushStack(struct Stack *s,int val){
    if(isFullStack(s)){
        printf("Cant push");
        return;
    }
    s->top++;
    s->arrs[s->top] = val;
}

int popStack(struct Stack * s){
    if(isEmptyStack(s)){
        printf("cant pop");
        return -1;
    }
    int temp = s->arrs[s->top];
    s->top--;
    return temp;
}

int isEmptyQueue(struct Queue *q){
    if(q->f==q->r){
        return 1;
    }
    return 0;
}

int isFullQueue(struct Queue * q){
    if(q->r==q->sizeq-1){
        return 1;
    }
    return 0;
}



void enQueue(struct Queue * q,int val){
    if(isFullQueue(q)){
        printf("Cant enqueue");
        return;
    }
    q->r++;
    q->arrq[q->r] = val;
}

int deQueue(struct Queue* q){
    if(isEmptyQueue(q)){
        printf("Cant dequeue");
        return -1;
    }
    q->f++;
    return q->arrq[q->f];
}

void displayStack(struct Stack * s){
    for(int i = 0;i<s->top+1;i++){
        printf("%d ",s->arrs[i]);
    }
}

void displayQueue(struct Queue * q){
    if(isEmptyQueue(q)){
        printf("Queue is empty cant display");
    }
    for(int i = q->f+1;i<q->r+1;i++){
        printf("%d ",q->arrq[i]);
    }
}

void reverseStack(struct Stack *s,struct Queue *q){
    while(!isEmptyStack(s)){
        int b = popStack(s);
        printf("\n%d",b);
        enQueue(q,b);
    }
    for(int i = q->f+1;i<q->r+1;i++){
        int a = deQueue(q);
        pushStack(s,a);

    }
}



int main(void){
    struct Stack *s = (struct Stack*)malloc(sizeof(struct Stack));
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));

    s->sizes = 10;
    s->top = -1;
    s->arrs = (int *)malloc(s->sizes * sizeof(int) );

    q->sizeq = 10;
    q->f =q->r =-1;
    q->arrq = (int*)malloc(q->sizeq * sizeof(int) );


    pushStack(s,10);
    pushStack(s,20);
    pushStack(s,30);
    pushStack(s,40);
    pushStack(s,50);

    displayStack(s);
    printf("top is at %d",s->top);
    reverseStack(s,q);
    printf("\n");
    displayStack(s);

//    popStack(s);
//    printf("top is at %d",s->top);


}