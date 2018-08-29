#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    int data;
    struct node *link;
};

typedef struct node LINKITEM;
LINKITEM *top = NULL;

void push(int data) {
    LINKITEM *temp = malloc(sizeof(LINKITEM));
    temp->data =  data;
    temp->link = top;
    top = temp;
}

void pop() {
    if (top == NULL) {
        printf("堆栈为空");
        
        return ;
    }
    
    LINKITEM *temp;
    temp = top;
    top = top->link;
    
    free(temp);
}

bool isEmpty() {
    return top == NULL ? true : false;
}

int main() {
    push(1);
    push(2);
    pop();
    
    
    return 0;
}
