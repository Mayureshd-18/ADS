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

};


void inorder(struct Node *p){
    if(p!=NULL){
        inorder(p->left);
        printf("%d ",p->data);
        inorder(p->right);

    }
}
int main(void){
    struct Node *n = createNode(10);
    struct Node *n2 = createNode(20);
    struct Node *n3 = createNode(5);

    n->right = n2;
    n->left = n3;


    inorder(n);

}