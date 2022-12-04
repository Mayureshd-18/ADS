#include <stdio.h>
#include <stdlib.h>



/* in after node
 * in before node
 * in after node
 * in at begin
 * in at end
 *
 * del at begin
 * del at end
 * del at val
 * */

struct Node{
    int data;
    struct Node * next;
};

struct Node * createNode(int val){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = val;
    ptr->next = NULL;
    return ptr;

}

void linkedlisttraversals(struct Node * ptr){
    printf("\n");
    while (ptr != NULL){
        int a = ptr->data;
        printf("%d ",a);
        ptr = ptr->next;
    }
}

void insertafternodeplace(struct Node * ptr,int node,int val){

    struct Node *ptr2 = createNode(val);
    for(int ctr = 1;ctr<node;ctr++){
        ptr = ptr->next;
    }
    ptr2->next = ptr->next;
    ptr->next = ptr2;


}

void insertionbeforenode(struct Node * ptr,int node,int val){
    node--;
    insertafternodeplace(ptr,node,val);
}

void insertatend(struct Node * ptr,int val){
    struct Node *ptr2 = createNode(val);
    while(ptr->next!=NULL){
        ptr = ptr->next;
    }
    ptr->next = ptr2;
}

struct Node * deletionfrombeginning(struct Node * ptr){
    ptr = ptr->next;
    return ptr;
}



void deletionatend(struct Node * ptr){
    while(ptr->next->next!=NULL){
        ptr = ptr->next;
    }
    ptr->next = NULL;
    free(ptr->next);
}


void deletenode(struct Node * ptr,int val){
    if(ptr->data==val){
        deletionfrombeginning(ptr);
        return;
    }
    struct Node *ptr2 = ptr;
    while(ptr->next->data!=val){
        ptr = ptr->next;
    }
    while(ptr2->data!=val){
        ptr2 = ptr2->next;
    }
    ptr->next = ptr2->next;
    ptr2->next = NULL;
    free(ptr2);

}


void insertafterNodeval(struct Node * ptr, int val,int valins){
    struct Node *ptr2 = createNode(valins);
    while(ptr->data!=val){
        ptr = ptr->next;
    }

    ptr2->next = ptr->next;
    ptr->next = ptr2;
}

struct Node * insertatbeginning(struct Node * ptr, int val){
    struct Node * ptr3 = createNode(val);
    ptr3->next = ptr;

    return ptr3;
}

int main(void){
    struct Node *head = createNode(10);

//    linkedlisttraversals(head);

    insertatend(head,20);
//    linkedlisttraversals(head);

    head = insertatbeginning(head,30);
    linkedlisttraversals(head);

//    deletionatend(head);
//    linkedlisttraversals(head);


//    head = deletionfrombeginning(head);
//    linkedlisttraversals(head);

    insertafterNodeval(head,10,40);
    linkedlisttraversals(head);

//    deletenode(head,30);
//    linkedlisttraversals(head);
//    deletionatend(head);
//    linkedlisttraversals(head);

    insertafternodeplace(head,2,50);
    linkedlisttraversals(head);

    insertionbeforenode(head,3,60);
    linkedlisttraversals(head);



}