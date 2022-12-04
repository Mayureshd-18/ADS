#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct stack{
    int top;
    int size;
    int * arr;
};

void display(struct stack *s){
    for(int i=0;i<s->top+1;i++){
        printf("%c ",s->arr[i]);
    }
}

struct stack* create(int max)

{
    struct stack* stack = (struct stack*)malloc(sizeof(struct stack));
    stack->size = max;
    stack->top = -1;
    stack->arr = (int*)malloc(stack->size * sizeof(int));
    return stack;

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

void push(struct stack* ptr, char val){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
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

//int eval_post(struct stack * s,char * postfix){
//
//    for(int i = 0;i<3;i++){
//        if(postfix[i]!="+"){
//            push(s,postfix[i]);
//        }
//
//        else if(postfix[i]=="+"){
//            int a = pop(s);
//            int b = pop(s);
//            printf("a and b is %d %d",a,b);
//            int res = a+b;
//            push(s,res);
//        }
//        display(s);
//    }
//}

int evaluatePostfix(struct stack *s,char* exp)
{
    int i;
    for (i = 0; exp[i]; ++i)
    {
        if (isdigit(exp[i]))
            push(s, exp[i] - '0');

        else{
            int val1 = pop(s);
            int val2 = pop(s);
            switch (exp[i])
            {
                case '+': push(s, val2 + val1); break;
                case '-': push(s, val2 - val1); break;
                case '*': push(s, val2 * val1); break;
                case '/': push(s, val2/val1); break;
            }
        }
    }
    return pop(s);
}

int main(void){

    struct stack * s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (char*)malloc(sizeof(char)*s->size);

    char * postfix = "45+";
//    evaluatePostfix(postfix);
    printf("%d", evaluatePostfix(s,postfix));
}
