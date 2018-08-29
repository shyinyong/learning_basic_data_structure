#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node LINKITEM;
LINKITEM *head = NULL;

LINKITEM* getNewNode(int data) {
    LINKITEM *newNode = malloc(sizeof(LINKITEM));
    if (newNode == NULL) {
        return NULL;
    }
    
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    
    return newNode;
}

// 在头部插入结点
void insert_head(int data) {
    LINKITEM *newNode = getNewNode(data);
    if (head == NULL) {
        head = newNode;
        
        return ;
    }
    head->prev = newNode;
    newNode->next = head;
    
    head = newNode;
}

// 在尾部插入结点
void insert_end(int data) {
    LINKITEM *newNode = getNewNode(data);
    if (head == NULL) {
        head = newNode;
        
        return;
    }
    
    LINKITEM *temp;
    
    temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = newNode;
    newNode->next = NULL;
    newNode->prev = temp;
    
    return ;
}

void print() {
    LINKITEM *temp = head;
    if (temp == NULL) {
        return;
    }
    
    while(temp != NULL) {
        printf("%d \n", temp->data);
        temp = temp->next;
    }
    
    printf("\n");
    
    return ;
}

void reversePrint() {
    LINKITEM *temp = head;
    if (temp == NULL) {
        return;
    }
    
    while(temp->next != NULL) {
        temp = temp->next;
    }
    
    while(temp != NULL) {
        printf("%d \n", temp->data);
        temp = temp->prev;
    }
    
    printf("\n");
    
    return ;
}

int main() {
    //insert_head(1);
    insert_end(1);
    insert_end(2);
    insert_end(3);
    insert_end(4);
    insert_end(5);

    print();
    
    reversePrint();
    
    printf("\n");
    return 0;
}
