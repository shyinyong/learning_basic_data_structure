#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node LINKITEM;

LINKITEM *front, *rear = NULL;

void enQueue(int data) {
    LINKITEM *temp = malloc(sizeof(LINKITEM));
    
    temp->data = data;
    temp->next = NULL;
    
    if (front == NULL && rear == NULL) {
        front = rear = temp;
        
        return;
    }
    
    rear->next = temp;
    rear = temp;
}

void deQueue() {
    if (front == NULL) {
        printf("队列为空 \n");
        
        return ;
    }
    
    if (front == rear) {
        front = rear = NULL;
    } else {
        LINKITEM *temp =  front;
        front = front->next;
        free(temp);
    }
    
}

void display() {
    LINKITEM *temp = front;
    
    while(temp != NULL) {
        printf("%d \n", temp->data);
        temp = temp->next;
    }
}

int main() {
    enQueue(1);
    enQueue(2);
    enQueue(3);
    enQueue(4);
    enQueue(5);
    
    deQueue();
    deQueue();
    deQueue();
    deQueue();
    
    display();
    
    return 0;
}
