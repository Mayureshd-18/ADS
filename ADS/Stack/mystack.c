#include <stdio.h>
#include <stdlib.h>

struct Stack{
    int size;
    int top;
    char *arr;
};


int isEmpty(struct Stack *s){
    if(s->top==-1){
        return 1;
    }
    return 0;
}

int isFull(struct Stack *s){
    if(s->top==s->size-1){
        return 1;
    }
    return 0;
}

void display(struct Stack *s){
    for(int i=0;i<s->top+1;i++){
        printf("%c ",s->arr[i]);
    }
}

void push(struct Stack *s, int data){
    if(isFull(s)){
        printf("Stack is full cant push");
        return;
    }

    s->top++;
    s->arr[s->top] = data;
}

void pop(struct  Stack *s){
    if(isEmpty(s)) {
        printf("Stack is full");
        return;
    }

        s->top--;

}

int peek(struct Stack *s, int i){
    int arrayInd = s->top -i + 1;
    if(arrayInd < 0){
        printf("Not a valid position for the stack\n");
        return -1;
    }
    else{
        return s->arr[arrayInd];
    }
}

int balanceparenthesis(struct Stack *sp,char * exp){

    for (int i = 0; exp[i]!='\0'; i++)
    {
        if(exp[i]=='('){
            push(sp, '(');
        }
        else if(exp[i]==')'){
            if(isEmpty(sp)){
                return 0;
            }
            pop(sp);
        }
    }

    if(isEmpty(sp)){
        return 1;
    }
    else{
        return 0;
    }

}


int main(void){
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    s->size = 10;
    s->top = -1;
    s->arr = (char*) malloc(s->size*sizeof(char));


//    push(s,5);
//    push(s,10);
//    pop(s);
//    pop(s);
//    display(s);
//    printf("\n%d",s->top);

//    peek(s,i);
    char sent[10];
    scanf("%s",sent);
//    printf("%s",sent);

    if(balanceparenthesis(s,sent)){
        printf("The parenthesis is matching");
    }
    else{
        printf("The parenthesis is not matching");
    }
    display(s);

}