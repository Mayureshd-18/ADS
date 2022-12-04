#include <stdio.h>
#include <stdlib.h>

struct Stack{
    int sizes;
    int top;
    int * arrs;
};

struct Queue{
    int f;
    int r;
    int sizeq;
    int * arrq;
};

int isEmptys(struct Stack *s){
    if(s->top==-1){
        return 1;
    }
    return 0;
}

int displays(struct Stack *s) {
    for(int i=0;i<s->sizes;i++){
        printf("%d ",s->arrs[i]);

    }


}
int isFulls(struct Stack *ptr){
    if(ptr->top==ptr->sizes-1){
        return 1;
    }
    return 0;
}

int push(struct Stack *s,int val){
    if(isFulls(s)){
        printf("Stack overflow");
        return -1;

    }
    s->top++;
    s->arrs[s->top]=val;
}

int pop(struct Stack *s){

    if(isEmptys(s)){
        printf("Cant pop, stack is empty");
        return -1;
    }
    int temp =  s->arrs[s->top];
    s->top--;
    return temp;
}





int isEmptyq(struct Queue *q){
    if(q->r==q->f){
        printf("\nQueue is empty");
        return 1;
    }
    return 0;
}

int deQueue(struct Queue *q){
    if(isEmptyq(q)){
        printf("Cant dequeue. Queue is empty");
        return -1;
    }
    q->f++;
    return q->arrq[q->f-1];

}
int isFullq(struct Queue *q){
    if(q->r==q->sizeq-1){
        return 1;
    }
    return 0;
}
void displayq(struct Queue * q){
    for(int i =q->f+1;i<q->sizeq;i++){
        printf("%d ",q->arrq[i]);
    }
    printf("\n");
}

void enqueue(struct Queue *q,int val){
    if(isFullq(q)){
        printf("Queue overflow\n");
        return;
    }
    q->r =  q->r+1;
    q->arrq[q->r] = val;
}


void reverse_stack(struct Stack *s,struct Queue *q){
    for(int k =0;k<s->sizes;k++){
        enqueue(q,pop(s));
    }
    printf("%d", isEmptys(s));
    printf("%d", isFullq(q));
    for(int k =0;k<q->sizeq;k++){
        push(s, deQueue(q));
    }

}

int main(void) {


    struct Stack *s = (struct Stack *) malloc(sizeof(struct Stack));
    s->sizes = 5;
    s->top = -1;
    s->arrs = (int *) malloc(s->sizes * sizeof(int));

    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->sizeq = 5;
    q->r=q->f = -1;
    q->arrq = (int *)malloc(q->sizeq * sizeof(int));


    push(s,10);
    push(s,20);
    push(s,30);
    push(s,40);
    push(s,50);
    displays(s);

    printf("\n");
    reverse_stack(s,q);
    displayq(q);
    printf("%d",s->top);
    displays(s);

}