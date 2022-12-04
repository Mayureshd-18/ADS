#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *  prev;
    struct Node * next;
};

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

struct Node * createNode(int val){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = val;
    ptr->prev = NULL;
    ptr->next = NULL;

    return ptr;
}


struct Node * insertatbeginning(struct Node * head, int data){
    struct Node * ptr2 = createNode(data);
    ptr2->next = head;
    head->prev = ptr2;

    return ptr2;
}
int main(void){
    struct Node * head = createNode(10);

    head = insertatbeginning(head, 5);

    dlltraversal(head);
    dlltraversalrev(head);



}