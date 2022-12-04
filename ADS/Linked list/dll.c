#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    int data;
    struct Node * next;
    struct Node * prev;
};

void dlltraversals(struct Node * ptr){
    while (ptr != NULL){
        int a = ptr->data;
        printf("%d\n",a);
        ptr = ptr->next;
    }
}

void dlltraversalsbackward(struct Node * ptr){
    while (ptr != NULL){
        int a = ptr->data;
        printf("%d\n",a);
        ptr = ptr->prev;
    }
}

int reader(){
    int a = 0;
    printf("Enter the element: ");
    scanf("%d",&a);
    return a;
};

int indexreader(){
    int ind = 0;
    printf("Enter the index: ");
    scanf("%d",&ind);
    return ind;
}

struct Node* nodereader(struct Node * head, int status){
    char node[7];
    int a = 1;
    if (status ==0){
         a = 1;
    }

    printf("Enter the node: ");
    scanf("%s",node);
    printf("%s",node);

    if (strcmp(node,"second") == 0){
        a += 0;
    }
    else if (strcmp(node,"third") == 0){
        a += 1;
    }
    else if (strcmp(node,"fourth") == 0){
        a += 2;
    }
    else if (node == "fifth"){
        a += 3;
    }
    printf("\n%d",a);

    struct Node * ptr = head;
    for(int i =0;i<a;i++){
        ptr = ptr->next;

    }
    return  ptr;

}


struct Node * insertionatbeginning(struct Node * head, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof (struct Node));
    ptr->data = data;

    ptr->next = head;
    head->prev = ptr;
    ptr->prev = NULL;
    return ptr;
}

struct Node * insertionatend(struct Node * foot, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof (struct Node));
    ptr->data = data;

    ptr->next = NULL;
    ptr->prev = foot;
    foot->next = ptr;

    return ptr;
}

struct Node * insertionafternode(struct Node * head,struct Node * prevnode, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof (struct Node));
    ptr->data = data;

    ptr->next = prevnode->next;
    ptr->prev = prevnode;
    prevnode->next = ptr;
    ptr->next->prev = ptr;


    return head;
}

struct Node * insertionbeforenode(struct Node * head,struct Node * nextnode, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof (struct Node));
    ptr->data = data;


    ptr->next = nextnode;
    ptr->prev = nextnode->prev;
    nextnode->prev = ptr;
    ptr->prev->next = ptr;

    return head;
}

struct Node * deletionfrombeginning(struct Node * head){
    struct Node * ptr = head;
    head = head->next;
    head->next->prev = NULL;
    free(ptr);

    return head;
}

struct Node * deletionfromend(struct Node * foot){
    struct Node * ptr = foot;
    foot->prev->next = NULL;
    foot = foot->prev;
    free(ptr);

    return foot;
}

struct Node * deletionofnode(struct Node * head,int value ){
    struct Node * p = head;
    struct Node * q = head;
    while(p->next->data!=value){
        p = p->next;
    }

    while(q->data!=value){
        q = q->next;
    }

    p->next = q->next;
    q->next->prev = p;
    q->prev->next = p->next;
    free(q);
    return head;
}

int main(void){

    struct Node * head = (struct Node *)malloc(sizeof (struct Node));
    struct Node * second = (struct Node *)malloc(sizeof (struct Node));
    struct Node * third = (struct Node *)malloc(sizeof (struct Node));
    struct Node * fourth = (struct Node *)malloc(sizeof (struct Node));
    struct Node * foot ;


    head->data = 7;
    head->next = second;
    head->prev = NULL;

    second->data = 11;
    second->next = third;
    second->prev = head;

    third->data = 22;
    third->next = fourth;
    third->prev = second;

    fourth->data = 66;
    fourth->next = NULL;
    fourth->prev = third;

    struct Node * p = head;
    while(p->next!=NULL){
        p = p->next;
    }
    foot = p;

//    printf("While travelling forward:\n");
//    dlltraversals(head);

//    printf("While travelling backwards:\n");
//    dlltraversalsbackward(foot);

//    printf("After adding a element at the beginning:\n");
//    head = insertionatbeginning(head,12);
//    dlltraversals(head);

//    printf("After adding a element at the end:\n");
//    foot = insertionatend(foot,14);
//    dlltraversals(head);

//    printf("After adding a element after a node:\n");
//    head = insertionafternode(head,second,16);
//    dlltraversals(head);

//    printf("After adding a element before a node:\n");
//    head = insertionbeforenode(head,second,18);
//    dlltraversals(head);

//    printf("After deleting a element from beginning:\n");
//    head = deletionfrombeginning(head);
//    dlltraversals(head);

//    printf("After deleting a element from end:\n");
//    foot = deletionfromend(foot);
//    dlltraversals(head);

//    printf("After deleting a element of node:\n");
//    head = deletionofnode(head,11);
//    dlltraversals(head);

    int menu = 1;
    while(menu!=0){
        printf("Enter the operation you want:\n1. Insertion at beginning\n2.Insertion at end\n3.Insertion after node\n4.Insertion before node\n5.deletion from beginning\n6.deletion from end\n7.deletion at node\n");
        scanf("%d", &menu);

        if (menu == 1) {
            printf("Before any insertion\n");
            dlltraversals(head);
            head = insertionatbeginning(head, reader());
            printf("After insertion at the beginning\n");
            dlltraversals(head);


        } else if (menu == 2) {
            printf("Before any insertion\n");
            dlltraversals(head);
            head = insertionatend(foot, reader());
            printf("After insertion at end:\n");
            dlltraversals(head);

        } else if (menu == 3) {
            printf("Before any insertion\n");
            dlltraversals(head);
            head = insertionafternode(head, nodereader(head,0), reader());
            printf("After insertion after a given node:\n");
            dlltraversals(head);


        } else if (menu == 4) {
            printf("Before any insertion\n");
            dlltraversals(head);
            head = insertionbeforenode(head, nodereader(head,1), reader());
            printf("After insertion before a given node:\n");
            dlltraversals(head);
        }


        else if (menu == 5){
            printf("Before any deletion\n");
            dlltraversals(head);
            printf("After deletion from beginning:\n");
            head = deletionfrombeginning(head);
            dlltraversals(head);
        }


        else if (menu == 6){
            printf("Before any deletion\n");
            dlltraversals(head);
            printf("After deletion from end:\n");
            head = deletionfromend(foot);
            dlltraversals(head);
        }


        else if (menu == 7){
            printf("Before any deletion\n");
            dlltraversals(head);
            head = deletionofnode(head, reader());
            printf("After deletion a node with given value:\n");
            dlltraversals(head);
        }
    }

}