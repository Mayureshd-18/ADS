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

int node_count(struct Node * root){
    if(root==NULL)
        return 0;
    return (1+ node_count(root->left)+ node_count(root->right));
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
    struct Node * new = createNode(val);
    struct Node * prev = NULL;

    while(root!=NULL){
        prev = root;
        if(root->data == val){
            printf("Node already exits. Unable to insert.");
            return;
        }
        else if(root->data>val)
            root = root->left;
        else if(root->data<val)
            root = root->right;
    }
    if(prev->data>val)
        prev->left = new;
    else
        prev->right = new;
}



void inorderTraversal(struct Node * root){
    if(root!=NULL){
        inorderTraversal(root->left);
        printf("%d ",root->data);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(struct Node * root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(struct Node * root){
    if(root!=NULL){
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ",root->data);
    }
}

int main(void){
        struct Node * root = createNode(10);
        insert(root,7);
        insert(root,6);
        insert(root,8);
        insert(root,12);
        insert(root,11);
//        insert(root,13);

    inorderTraversal(root);
    printf("\n");
    preorderTraversal(root);
    printf("\n");
    postorderTraversal(root);
    printf("\n");


//    printf("%d",max_height(root));
//    printf("%d", node_count(root));


    mirror(root);

    inorderTraversal(root);
    printf("\n");
    preorderTraversal(root);
    printf("\n");
    postorderTraversal(root);
    printf("\n");
}