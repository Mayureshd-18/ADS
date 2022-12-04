#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct stack
{
    int size;
    int top;
    int *arr;
};



char stackTop(struct stack* sp){
    return sp->arr[sp->top];
}

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack* ptr, int val){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
int isOperator(char a){
    if(a=='*' || a=='-' || a=='/' || a=='+'){
        return 1;
    }
    return 0;
}

int pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int eval_postfix(char * postfix){
    struct stack * sp = (struct stack *) malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (char *) malloc(sp->size * sizeof(char));

    for(int i = 0;postfix[i];++i){
        if(isdigit(postfix[i])){
            push(sp,postfix[i]-'0');
        }
        else if(isOperator(postfix[i])){
            int val1 = pop(sp);
            int val2 = pop(sp);

            switch(postfix[i]){
                case '+':push(sp,val1 + val2);break;
            }
        }

    }
    return pop(sp);
}



int precedence(char a){
    if(a=='*' || a=='/')
        return 3;
    else if(a=='-' || a=='+')
        return 2;
    else
        return 0;
}

char * infixtopostfix(char * infix){
    struct stack * sp = (struct stack *) malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (char *) malloc(sp->size * sizeof(char));

    char * postfix = (char *)malloc(strlen(infix)+1* sizeof(char));
    int i = 0;
    int j = 0;

    while(infix[i]!='\0'){
        if(!isOperator(infix[i])){
            postfix[j] = infix[i];
            i++;j++;
        }
        else{
            if(precedence(infix[i])> precedence(stackTop(sp))){
                push(sp,infix[i]);
                i++;
            }
            else{
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while(!isEmpty(sp)){
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';

    return postfix;



}

int main(void){
    char * exp = "4+5";
    printf("%d",eval_postfix(infixtopostfix(exp)));
}