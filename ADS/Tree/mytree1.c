#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node * left;
    struct node * right;
};


struct node * createNode(int val){
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = val;
    p->left = NULL;
    p->right = NULL;
}

void preorder(struct node *p){
    if(p!=NULL){
        printf("%d ",p->data);
        preorder(p->left);
        preorder(p->right);
    }
}

void inorder(struct node *p){
    if(p!=NULL){
        inorder(p->left);
        printf("%d ",p->data);
        inorder(p->right);

    }
}
void postorder(struct node *p){
    if(p!=NULL){
        postorder(p->left);
        postorder(p->right);
        printf("%d ",p->data);
    }
    else{
        return;
    }
}

struct node * Search(struct node * root,int val){
    if(root==NULL){
        return NULL;
    }
    if(root->data==val){
//        printf("Found the value");
        return root;
    }
    else if(root->data>val){
        Search(root->left,val);
    }
    else if(root->data<val){
        Search(root->right,val);
    }
}

struct node * Itersearch(struct node * root,int val){
    while(root!=NULL){
        if(root->data==val){
            return root;
        }
        else if(root->data>val){
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    return NULL;
}


void insert(struct node * root,int val){
    struct node * prev = NULL;
    while(root!=NULL){
        prev = root;
        if(root->data==val){
            printf("Value already exists in the tree,");
            return;
        }
        else if(root->data>val){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    struct node * new = createNode(val);
    if(val>prev->data){
        prev->right = new;
    }
    else{
        prev->left = new;
    }
}

struct node * InorderPredecessor(struct node * root){
    root = root->left;
    while(root->right!=NULL){
        root = root->right;
    }
    return root;
}

struct node * DeleteNode(struct node * root, int val){
    struct node * Ipre;
    if(root==NULL){
        return NULL;
    }
    //It is a leaf node
    else if(root->left==NULL && root->right==NULL){
        free(root);
        return NULL;
    }
    //Search the node
    if(val>root->data){
        root->right = DeleteNode(root->right,val);
    }
    else if(val<root->data){
        root->left = DeleteNode(root->left,val);
    }
    //After the node is found copy the  inorder predecessor in the root and delete the predecessor.
    else{
        Ipre = InorderPredecessor(root);
        root->data = Ipre->data;
        root->left = DeleteNode(root->left,Ipre->data);
    }
    return root;
}


int main(void){
    struct node *n = createNode(5);
    struct node *n1 = createNode(3);
    struct node *n2 = createNode(7);
    struct node *n3 = createNode(2);
//    struct node *n4 = createNode(4);
    struct node *n5 = createNode(6);
    struct node *n6 = createNode(8);


    /*
          5
        /  \
       3    7
      / \  / \
     2  4  6  8

     */
    n->left = n1;
    n->right = n2;
    n1->left = n3;
//    n1->right = n4;
    n2->left = n5;
    n2->right = n6;

//    preorder(n);
//    printf("\n");
//    postorder(n);
//    printf("\n");
//    inorder(n);

//    struct node *a = Search(n,6);
//    printf("Found %d",a->data);

//struct node *a = Itersearch(n,6);
//printf("Found %d",a->data);
    inorder(n);
    printf("\n");
    insert(n,4);
    inorder(n);
//    inorder(n);
//    DeleteNode(n,5);
//    printf("\n");
//    printf("%d\n",n->data);
//    inorder(n);
}