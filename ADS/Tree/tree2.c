#include<stdio.h>
#include<stdlib.h>

struct node
{
    int key;
    struct node *left;
    struct node *right;
};

struct node *getNode(int val)
{
    struct node *newNode;

    newNode = malloc(sizeof(struct node));

    newNode->key   = val;
    newNode->left  = NULL;
    newNode->right = NULL;

    return newNode;
}

struct node *insertNode(struct node *root, int val)
{
    if(root == NULL)
        return getNode(val);

    if(root->key < val)
        root->right = insertNode(root->right,val);

    if(root->key > val)
        root->left = insertNode(root->left,val);

    return root;
}

void inorder(struct node *root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    printf("%d ",root->key);
    inorder(root->right);
}

void preorder(struct node *root)
{
    if(root == NULL)
        return;

    printf("%d ",root->key);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node *root)
{
    if(root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->key);
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
                printf("%d ",temp->key);
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
    struct node *root = NULL;


    int data;
    char ch;
    do
    {
        printf("\nSelect one of the operations::");
        printf("\n1. To insert a new node in the Binary Tree");
        printf("\n2. To display the tree using  Inorder Traversal");
        printf("\n3. To display the tree using Preorder traversal");
        printf("\n4. To display the tree using postorder traversal");
        printf("\n5. To display the tree using without recursion\n");

        int choice;
        scanf("%d",&choice);
        switch (choice)
        {
            case 1 :
                printf("\nEnter the value to be inserted\n");
                scanf("%d",&data);
                root = insertNode(root,data);
                break;
            case 2 :
                printf("\nInorder Traversal of the Binary Tree:\n");
                inorder(root);
                break;
            case 3:
                printf("\nPreorder Traversal of the Binary tree:\n");
                preorder(root);
                break;
            case 4:
                printf("\nPostorder Traversal of the Binary tree\n");
                postorder(root);
                break;
            case 5:
                printf("\nWithout recursion traversal of Binary tree:\n");
                tree_traversal(root);
                break;

            default :
                printf("Wrong Entry\n");
                break;
        }

        printf("\nDo you want to continue (Type y or n)\n");
        scanf(" %c",&ch);
    } while (ch == 'Y'|| ch == 'y');

    return 0;
}