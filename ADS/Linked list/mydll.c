#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * prev;
    struct Node * next;
};

struct Node * createNode(int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->prev = NULL;
    ptr->next = NULL;
    return ptr;
}

struct Node * insertatbeginning(struct Node * ptr, int data){
    struct Node * ptr2 = createNode(data);
    ptr->prev = ptr2;
    ptr2->next = ptr;

    return ptr2;
}

void insertatend(struct Node * ptr, int data){
    struct Node * ptr2 = createNode(data);
    while(ptr->next!=NULL){
        ptr = ptr->next;
    }
    ptr->next = ptr2;
    ptr2->prev = ptr;

}

void insertafterval(struct Node * ptr,int val, int data){
    struct Node * ptr2 = createNode(data);
    while(ptr->data!=val){
        ptr = ptr->next;
    }
    ptr2->next = ptr->next;
    ptr->next->prev = ptr2;
    ptr2->prev = ptr;
    ptr->next = ptr2;

}


void dlltraversal(struct Node * ptr){
    printf("\n");
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
}

void dlltraversalrev(struct Node * ptr){
    printf("\n");
    while(ptr->next!=NULL){
        ptr = ptr->next;
    }
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr = ptr->prev;
    }
}
int main(void){
    struct Node * head = createNode(10);
//    dlltraversal(head);

    head = insertatbeginning(head,5);
//    dlltraversal(head);

    insertatend(head,20);
//    dlltraversal(head);
//    dlltraversalrev(head);

    insertafterval(head,10,15);
    dlltraversal(head);
    dlltraversalrev(head);

}