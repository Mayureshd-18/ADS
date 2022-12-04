#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};



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

int pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int main(void) {
    struct stack *s = (struct stack *) malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int *) malloc(s->size * sizeof(int));

    int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    int a[7][7];

    for(int s = 0;s<7;s++){
        for(int t = 0;t<7;t++){
            a[s][t] = 0;
        }
    }

    for (int k = 0; k < 21; k++) {
        printf("Enter start and end points:\n");
        int x, y;
        scanf("%d %d", &x, &y);
        if (x == -1 && y == -1) {
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
    printf("%d ", i);
    visited[i] = 1;
    push(s, i);
    while (!isEmpty(s)) {
        node = pop(s);
        for (int j = 0; j < 7; j++) {
            if (a[node][j] == 1 && visited[j] == 0) {
                printf("%d ", j);
                visited[j] = 1;
                push(s, j);
            }
        }
    }
}