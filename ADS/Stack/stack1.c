#include <stdio.h>
#include <stdlib.h>

struct stack{
    int size;
    int top;
    int * arr;
};

int isEmpty(struct stack *s){
    if(s->top==-1){
        return 1;
    }
    return 0;
}

int display(struct stack *s,int val) {
    if (s->top + 1 - val < 0) {
        return -1;
    }
    return s->arr[val];

}
int isFull(struct stack *ptr){
    if(ptr->top==ptr->size-1){
        return 1;
    }
    return 0;
}

int push(struct stack *s,int val){
    if(isFull(s)){
        printf("Stack overflow");
        return -1;

    }
    s->top++;
    s->arr[s->top]=val;
}

int pop(struct stack *s){

    if(isEmpty(s)){
        printf("Cant pop, stack is empty");
        return -1;
    }
    printf("%d\n",s->arr[s->top]);
    s->top--;
}








int main(void){
    struct stack *s = (struct stack*)malloc(sizeof(struct stack));
    s->size = 5;
    s->top = -1;
    s->arr = (int*)malloc(s->size * sizeof(int));

//    s.arr[0]=4;
//    s.top++;

    if(isEmpty(s)){
        printf("It is empty\n");
    }
    else{
        printf("It is not empty");
    }

    push(s,16);
    push(s,32);
    push(s,64);
    push(s,78);
    push(s,56);
    push(s,76);

    if(isEmpty(s)){
        printf("\nIt is empty\n");
    }
    else{
        printf("It is not empty\n");
    }

    for(int j=0;j<s->top+1;j++){
        printf("%d\n",display(s,j));
    }
    printf("\n");
    pop(s);
    pop(s);
    pop(s);
    pop(s);
    pop(s);
    pop(s);
}

