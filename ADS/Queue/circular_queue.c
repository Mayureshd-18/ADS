#include <stdio.h>
#define SIZE 50

int items[SIZE];
int front = -1, rear = -1;

int isFull() {
    if ((front == rear + 1) || (front == 0 && rear == SIZE - 1)) return 1;
    return 0;
}

int isEmpty() {
    if (front == -1) return 1;
    return 0;
}

void enQueue(int element) {
    if (isFull())
        printf("\n Queue is full!! \n");
    else {
        if (front == -1) front = 0;
        rear = (rear + 1) % SIZE;
        items[rear] = element;
        printf("\nInserted -> %d\n", element);
    }
}

int deQueue() {
    int element;
    if (isEmpty()) {
        printf("\nQueue is empty !! \n");
        return (-1);
    } else {
        element = items[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else {
            front = (front + 1) % SIZE;
        }
        printf("\nDeleted element -> %d \n", element);
        return (element);
    }
}

void display() {
    int i;
    if (isEmpty())
        printf(" \nEmpty Queue\n");
    else {
        printf("\nFront -> %d ", front);
        printf("\nQueue -> ");
        for (i = front; i != rear; i = (i + 1) % SIZE) {
            printf("%d ", items[i]);
        }
        printf("%d ", items[i]);
        printf("\nRear -> %d \n", rear);
    }
}

int main() {
    int opt,val;
    start:
    printf("\n*MENU*\n\n");
    printf("Press1 for Insertion \nPress2 for Deletion \nPress3 to Display Queue \nPress4 to exit \n");
    scanf("%d", &opt);
    getchar();

    while (1)
    {

        switch (opt)
        {
            case 1:
                printf("Enter value for insertion in queue : \n");
                scanf("%d", &val);
                enQueue(val);
                goto start;
                break;

            case 2:
                deQueue();
                goto start;
                break;

            case 3:
                display();
                goto start;
                break;

            case 4:
                goto end;
        }
    }
    end:
    printf("Program Ended\n");
    return 0;
}