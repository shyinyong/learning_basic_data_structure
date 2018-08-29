//
//  main.c
//  circular_linked_list
//
//  Created by Apple on 2018/8/14.
//  Copyright © 2018年 Apple. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

typedef struct Node LINKITEM;

LINKITEM *head = NULL;

void insert_beg(int data) {
    LINKITEM *newNode = malloc(sizeof(LINKITEM));
    
    newNode->data = data;
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        LINKITEM *temp = head;
        while(temp->next != head) {
            temp = temp->next;
        }
        
        newNode->next = head;
        head = newNode;
        temp->next = head;
        
        head = newNode;
    }
}

void insert_end(int data) {
    LINKITEM *newNode = malloc(sizeof(LINKITEM));
    newNode->data = data;
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        
    }
    
    
}

int main() {
    
    
    return 0;
}
