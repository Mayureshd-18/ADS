#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    int data;
    struct Node * next;
};

void linkedlisttraversals(struct Node * ptr){
    while (ptr != NULL){
        int a = ptr->data;
        printf("%d\n",a);
        ptr = ptr->next;
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

 struct Node* nodereader(struct Node * head){
    char node[7];
    int a = 0;
    printf("Enter the node: ");
    scanf("%s",node);
    printf("%s",node);
    if (strcmp(node,"head")==0){
        a = 1;
    }
    else if (strcmp(node,"second") == 0){
        a = 2;
    }
    else if (strcmp(node,"third") == 0){
        a = 3;
    }
    else if (strcmp(node,"fourth") == 0){
        a = 4;
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
    return ptr;
}

struct Node * insertionatindex(struct Node * head, int data, int index){
    struct Node * ptr = (struct Node *)malloc(sizeof (struct Node));
    int i = 0;
    struct Node * p = head;

    while(i!=index-1){
        p = p->next;
        i++;
    }

    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

struct Node * insertionatend(struct Node * head, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof (struct Node));
    struct Node * p = head;

    while(p->next!=NULL){
        p = p->next;
    }

    ptr->data = data;
    ptr->next = NULL;
    p->next = ptr;
    return head;
}

struct Node * insertionafternode(struct Node * head,struct Node * prevnode, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof (struct Node));

    ptr->data = data;
    ptr->next = prevnode->next;
    prevnode->next = ptr;

    return head;
}

struct Node * deletionfrombeginning(struct Node * head){
    struct Node * ptr = head;
    head = head->next;
    free(ptr);

    return head;
}

struct Node * deletionfromend(struct Node * head){
    struct Node * p = head;
    struct Node * q = head;
    while(p->next->next!=NULL){
        p = p->next;
    }

    while(q->next!=NULL){
        q = q->next;
    }

    p->next = NULL;
    free(q);

    return head;
}

struct Node * deletionofnode(struct Node * head,int value){
    struct Node * p = head;
    struct Node * q = head;
    while(p->next->data!=value){
        p = p->next;
    }

    while(q->data!=value){
        q = q->next;
    }

    p->next = q->next;
    free(q);
    return head;
}




int main(void) {

    struct Node *head = (struct Node *) malloc(sizeof(struct Node));
    struct Node *second = (struct Node *) malloc(sizeof(struct Node));
    struct Node *third = (struct Node *) malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *) malloc(sizeof(struct Node));


    head->data = 7;
    head->next = second;

    second->data = 11;
    second->next = third;

    third->data = 22;
    third->next = fourth;

    fourth->data = 66;
    fourth->next = NULL;



//    printf("After insertion at the beginning\n");
//    head = insertionatbeginning(head,12);
//    linkedlisttraversals(head);


//    printf("After insertion at a given index:\n");
//    head = insertionatindex(head,69,2);
//    linkedlisttraversals(head);

//    printf("After insertion at end:\n");
//    head = insertionatend(head,69);
//    linkedlisttraversals(head);


//    printf("After insertion after a given node:\n");
//    head = insertionafternode(head,second,420);
//    linkedlisttraversals(head);

//    printf("After deletion from beginning:\n");
//    head = deletionfrombeginning(head);
//    linkedlisttraversals(head);

//    printf("After deletion from end:\n");
//    head = deletionfromend(head);
//    linkedlisttraversals(head);

//    printf("After deletion a node with given value:\n");
//    head = deletionofnode(head, 11);
//    linkedlisttraversals(head);


    int menu = 1;
    while(menu!=0){
        printf("Enter the operation you want:\n1. Insertion at beginning\n2.Insertion at end\n3.Insertion at index\n4.Insertion at node\n5.deletion from beginning\n6.deletion from end\n7.deletion at node\n");
        scanf("%d", &menu);

        if (menu == 1) {
            printf("Before any insertion\n");
            linkedlisttraversals(head);
            head = insertionatbeginning(head, reader());
            printf("After insertion at the beginning\n");
            linkedlisttraversals(head);


        } else if (menu == 2) {
            printf("Before any insertion\n");
            linkedlisttraversals(head);
            head = insertionatend(head, reader());
            printf("After insertion at end:\n");
            linkedlisttraversals(head);

        } else if (menu == 3) {
            printf("Before any insertion\n");
            linkedlisttraversals(head);
            head = insertionatindex(head, reader(), indexreader());
            printf("After insertion at a given index:\n");
            linkedlisttraversals(head);


        } else if (menu == 4) {
            printf("Before any insertion\n");
            linkedlisttraversals(head);
            head = insertionafternode(head,  nodereader(head), reader());
            printf("After insertion after a given node:\n");
            linkedlisttraversals(head);
        }


        else if (menu == 5){
            printf("After deletion from beginning:\n");
            head = deletionfrombeginning(head);
            linkedlisttraversals(head);
        }


        else if (menu == 6){
            printf("After deletion from end:\n");
            head = deletionfromend(head);
            linkedlisttraversals(head);
        }


        else if (menu == 7){
            printf("After deletion a node with given value:\n");
            head = deletionofnode(head, reader());
            linkedlisttraversals(head);
        }
    }


    return 0;
}