#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 6

int queue_list[MAX_SIZE];
int front = 0;
int rear = 0;

bool isEmpty(){
    if (front == rear) {
        return  true;
    } else {
        return false;
    }
}

bool isFull(){
    if ((rear + 1) % MAX_SIZE == front) {
         return  true;
    } else {
        return false;
    }
}

void enQueue(int data) {
    if (isFull()) {
        printf("队列已满！ \n");
        return ;
    }
    
    rear = (rear + 1) % MAX_SIZE;
    queue_list[rear] = data;
}

void deQueue() {
    if (isEmpty()) {
        printf("队列为空！ \n");
        return ;
    }
    
    front = (front + 1) % MAX_SIZE;
}

void display() {
    printf("当前列队 front: %d \n", front);
    printf("当前列队 rear: %d \n", rear);
}

int main() {
    enQueue(20);
    enQueue(30);
    enQueue(40);
    enQueue(50);

    deQueue();
    deQueue();
    deQueue();
    deQueue();
    
    enQueue(60);
    enQueue(70);
    
    display();
    
//    for (int i = 0; i< MAX_SIZE; i++) {
//        printf("%d \n", queue_list[i]);
//    }
    
    
    return 0;
}
