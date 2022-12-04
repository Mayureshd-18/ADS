#include <stdio.h>
// #include <conio.h>
#include <malloc.h>
struct node
{
    struct node *left;
    int data;
    struct node *right;
};


struct Node
{
    int data;
    struct Node *left, *right;
};



struct Stack
{
    int size;
    int top;
    struct Node* *array;
};

struct Node* newNode(int data)
{
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Stack* createStack(int size)
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->size = size;
    stack->top = -1;
    stack->array = (struct Node**) malloc(stack->size * sizeof(struct Node*));
    return stack;
}

int isFull(struct Stack* stack)
{ return stack->top - 1 == stack->size; }

int isEmpty2(struct Stack* stack)
{ return stack->top == -1; }

void push2(struct Stack* stack, struct Node* node)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = node;
}

struct Node* pop2(struct Stack* stack)
{
    if (isEmpty2(stack))
        return NULL;
    return stack->array[stack->top--];
}

struct Node* peek(struct Stack* stack)
{
    if (isEmpty2(stack))
        return NULL;
    return stack->array[stack->top];
}

void postOrderIterative(struct Node* root)
{
    if (root == NULL)
        return;

    struct Stack* stack = createStack(10);
    do
    {
        while (root)
        {
            if (root->right)
                push2(stack, root->right);
            push2(stack, root);

            root = root->left;
        }

        root = pop2(stack);

        if (root->right && peek(stack) == root->right)
        {
            pop2(stack);
            push2(stack, root);
            root = root->right;

        }
        else
        {
            printf("%d ", root->data);
            root = NULL;
        }
    } while (!isEmpty2(stack));
}

void main()
{
    void insert(struct node **,int);
    void inorder(struct node *);
    void postorder(struct node *);
    void preorder(struct node *);
    int tree_traversal(struct node *);




    struct node *ptr = NULL;
    int no,i,num;

    // ptr = NULL;
    // ptr->data=0;

    int data;
    char ch;
    /*  Do while loop to display various options to select from to decide the input  */
    do
    {
        printf("\nSelect one of the operations::");
        printf("\n1. To insert a new node in the Binary Tree");
        printf("\n2. To display the nodes of the Binary Tree(via Preorder Traversal).");
        printf("\n3. To display the nodes of the Binary Tree(via Inorder Traversal).");
        printf("\n4. To display the nodes of the Binary Tree(via Postorder Traversal).");
        printf("\n5. To display the nodes of binary tree without recursion.\n");

        int choice;
        scanf("%d",&choice);
        switch (choice)
        {
            case 1 :
                printf("\nEnter the value to be inserted\n");
                scanf("%d",&data);
                insert(&ptr,data);
                break;
            case 2 :
                printf("\nPreorder Traversal of the Binary Tree::\n");
                preorder(ptr);
                break;
            case 3 :
                printf("\nInorder Traversal of the Binary Tree::\n");
                inorder(ptr);
                break;
            case 4 :
                printf("\nPostorder Traversal of the Binary Tree::\n");
                postorder(ptr);
                break;
            case 5 :
                printf("binary tree without recursion.\n");
                tree_traversal(ptr);
                break;
            case 6:
                postOrderIterative(ptr);
                break;
            default :
                printf("Wrong Entry\n");
                break;
        }

        printf("\nDo you want to continue (Type y or n)\n");
        scanf(" %c",&ch);
    } while (ch == 'Y'|| ch == 'y');



}

void insert(struct node **p,int num)
{
    if((*p)==NULL)
    {
        printf("Leaf node created.");
        (*p)=malloc(sizeof(struct node));
        (*p)->left = NULL;
        (*p)->right = NULL;
        (*p)->data = num;
        return;
    }
    else
    {
        if(num==(*p)->data)
        {
            printf("\nREPEATED ENTRY ERROR VALUE REJECTED\n");
            return;
        }
        if(num<(*p)->data)
        {
            printf("\nDirected to left link.\n");
            insert(&((*p)->left),num);
        }
        else
        {
            printf("Directed to right link.\n");
            insert(&((*p)->right),num);
        }
    }
    return;
}

void inorder(struct node *p)
{
    if(p!=NULL)
    {
        inorder(p->left);
        printf("%d ",p->data);
        inorder(p->right);
    }
    else
        return;
}

void preorder(struct node *p)
{
    if(p!=NULL)
    {
        printf("%d ",p->data);
        preorder(p->left);
        preorder(p->right);
    }
    else
        return;
}

void postorder(struct node *p)
{
    if(p!=NULL)
    {
        postorder(p->left);
        postorder(p->right);
        printf("%d ",p->data);
    }
    else
        return;
}

struct stack
{
    struct node* data;
    struct stack* next;
};

void push(struct stack** top,struct node* n);
struct node* pop(struct stack** top);
int isEmpty(struct stack* top);

int tree_traversal(struct node* root)
{
    struct node* temp = root;
    struct stack* s_temp = NULL;
    int flag = 1;
    while(flag)
    {
        if(temp){
            push(&s_temp,temp);
            temp = temp->left;
        }
        else{
            if(!isEmpty(s_temp)){
                temp = pop(&s_temp);
                temp = temp->right;
                printf("%d ",temp->data);
            }
            else
                flag = 0;
        }
    }
}



void push(struct stack** top,struct node* n)
{
    struct stack* new_n = (struct stack*)malloc(sizeof(struct stack));
    new_n->data = n;
    new_n->next = (*top);
    (*top) = new_n;
}
int isEmpty(struct stack* top)
{
    if(top==NULL)
        return 1;
    else
        return 0;
}
struct node* pop(struct stack** top_n)
{
    struct node* item;
    struct stack* top;
    top = *top_n;
    item = top->data;
    *top_n = top->next;
    free(top);
    return item;
}
