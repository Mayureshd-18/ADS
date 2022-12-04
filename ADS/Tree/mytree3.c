#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * left;
    struct Node * right;

};

struct Node * createNode(int val){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = val;
    ptr->left = NULL;
    ptr->right = NULL;

    return ptr;
}

int max_height(struct Node * root){
    if(root==NULL){
       return 0;
    }
   int l_depth = max_height(root->left);
   int r_depth = max_height(root->right);

   if(l_depth>r_depth)
       return l_depth+1;
   return r_depth+1;
}

int count_nodes(struct Node * root){
    if(root==NULL)
        return 0;
    return (1+ count_nodes(root->left)+ count_nodes(root->right));
}

void Inorder(struct Node * root){
    if(root!=NULL){
        Inorder(root->left);
        printf("%d ",root->data);
        Inorder(root->right);
    }
}

void mirror(struct Node * root){
    if(root==NULL){
        return;
    }

    mirror(root->left);
    mirror(root->right);

    struct Node * temp;
    temp = root->left;
    root->left = root->right;
    root->right = temp;

}

void insert(struct Node * root, int val){
    struct Node * prev = NULL;
    struct Node * new = createNode(val);
    while(root!=NULL){
        prev = root;

        if(root->data==val){
            printf("Already exits cant insert");
            return;
        }
        else if(val>root->data){
            root = root->right;
        }
        else{
            root = root->left;
        }
    }
    if(prev->data>val)
        prev->left = new;
    else
        prev->right = new;
}

int main(void){
    struct Node * root = createNode(10);
    insert(root,5);
    insert(root,15);
    insert(root,6);
    insert(root,4);

    Inorder(root);

    mirror(root);
    printf("\n");
    Inorder(root);
}