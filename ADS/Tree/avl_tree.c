#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * left;
    struct Node * right;
    int height;
};

int getHeight(struct Node * n){
    if(n==NULL){
        return 0;
    }
    return n->height;
}

struct Node * createNode(int key){
    struct Node * node = (struct Node *)malloc(sizeof(struct Node));
    node->data = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
};


int getBalanceFactor(struct Node * n){
    if(n==NULL){
        return 0;
    }
    return getHeight(n->left) - getHeight(n->right-);
}


struct Node * rightRotate(struct Node * y){
    struct Node * x = y->left;
    struct Node * T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right))+1;
//    x->height = max(x->left->height,x->right->height)+1;
    x->height = max(getHeight(x->left), getHeight(x->right))+1;
    //x is the new root
    return x;
}

struct Node * leftRotate(struct Node * x){
    struct Node * y = x->right;
    struct Node * T2 = y->left;

    y->left = x;
    x->right = T2;

    y->height = max(getHeight(y->left), getHeight(y->right))+1;
//    x->height = max(x->left->height,x->right->height)+1;
    x->height = max(getHeight(x->left), getHeight(x->right))+1;
    //x is the new root
    return y;
}

