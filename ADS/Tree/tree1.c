#include <stdio.h>
#include <stdlib.h>
struct node *root2;

void insert(int);
struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}


void RecursivePrintInorder(struct node* node)
{
    if (node == NULL)
        return;

    RecursivePrintInorder(node->left);
    printf("%d ", node->data);
    RecursivePrintInorder(node->right);
}


void RecursivePrintPostorder(struct node* node)
{
    if (node == NULL)
        return;


    RecursivePrintPostorder(node->left);
    RecursivePrintPostorder(node->right);
    printf("%d ", node->data);
}

void RecursivePrintPreorder(struct node* node)
{
    if (node == NULL)
        return;

    printf("%d ", node->data);
    RecursivePrintPreorder(node->left);
    RecursivePrintPreorder(node->right);
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
                printf("%d ",temp->data);
                temp = temp->right;
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







int main()
{
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);


    /*              1
     *             /\
     *            2  3
     *           /\
     *          4  5   */

    printf("\nInorder traversal of tree using recursion is \n");
    RecursivePrintInorder(root);

    printf("\nPostorder traversal of tree using recursion is \n");
    RecursivePrintPostorder(root);

    printf("\nPreorder traversal of tree using recursion is \n ");
    RecursivePrintPreorder(root);


    printf("\n");
    printf("Tree traversal of tree without using recursion is \n");
    tree_traversal(root);


    int choice,item;
    do
    {
        printf("\nEnter the item which you want to insert?\n");
        scanf("%d",&item);
        insert(item);
        printf("\nPress 0 to insert more ?\n");
        scanf("%d",&choice);
    }while(choice == 0);
    RecursivePrintInorder(root);


return 0;
}

void insert(int item)
{
    struct node *ptr, *parentptr , *nodeptr;
    ptr = (struct node *) malloc(sizeof (struct node));
    if(ptr == NULL)
    {
        printf("can't insert");
    }
    else
    {
        ptr -> data = item;
        ptr -> left = NULL;
        ptr -> right = NULL;
        if(root2 == NULL)
        {
            root2 = ptr;
            root2 -> left = NULL;
            root2 -> right = NULL;
        }
        else
        {
            parentptr = NULL;
            nodeptr = root2;
            while(nodeptr != NULL)
            {
                parentptr = nodeptr;
                if(item < nodeptr->data)
                {
                    nodeptr = nodeptr -> left;
                }
                else
                {
                    nodeptr = nodeptr -> right;
                }
            }
            if(item < parentptr -> data)
            {
                parentptr -> left = ptr;
            }
            else
            {
                parentptr -> right = ptr;
            }
        }
        printf("Node Inserted");
    }
}