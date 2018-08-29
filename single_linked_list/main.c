#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node LINKITEM;
LINKITEM *head = NULL;

void create(int data) {
    LINKITEM *temp;
    temp = malloc(sizeof(LINKITEM));
    if (head == NULL) {
        temp->data = data;
        temp->next = NULL;
        head = temp;
    }
}

void print(){
    LINKITEM *temp = head;
    while(temp != NULL){
        temp = temp->next;
    }
    
    return;
}

// 显示链表
void display() {
    if (head == NULL) {
        return;
    }
    
    LINKITEM *ptr = head;
    while(ptr != NULL) {
        printf("%p,\t%d \n",  ptr, (*ptr));
        
        ptr = ptr->next;
    }
    
    printf("\n");
}

// 在链表头处插入
void insertAtFirst(int data){
    LINKITEM *newNode = malloc(sizeof(LINKITEM));
    if (!newNode) {
        return ;
    }
    
//    printf("newNode: %p \n", &newNode);
//    printf("newNode value: %p \n", newNode);
    
    newNode->data = data;
    newNode->next = head;
    
//    printf("head: %p \n", &head);
//    printf("head value: %p \n", head);
    
    head = newNode;
    
    //printf("head value: %p \n", head);
}

// 在链表尾处插入
void insertAtEnd(int data){
    LINKITEM *newNode = malloc(sizeof(LINKITEM));
    if (!newNode) {
        return ;
    }
    
    newNode->data = data;
    newNode->next = NULL;
    
    if (head == NULL) {
        head = newNode;
    } else {
        LINKITEM *temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        
        temp->next = newNode;
    }
    
    return ;
}

void insert_end(int data){
    if (head == NULL) {
        return;
    }
    
    LINKITEM *ptr, *temp;
    
    ptr = head;
    while(1) {
        if (ptr->next != NULL) {
            ptr = ptr->next;
        } else {
            break;
        }
    }
    
    temp = malloc(sizeof(LINKITEM));
    temp->data = data;
    temp->next = NULL;
    ptr->next = temp;
}

void insert_beg(int data) {
    LINKITEM *temp;
    // temp 自身的内存地址是 0xfffffff
    // temp 值等于 0x0
//    printf("%p \n", &temp);
//    printf("%p \n \n", temp);
    
    temp = malloc(sizeof(LINKITEM));
    if (!temp) {
        return ;
    }
    
    temp->data = data;
    temp->next = head;
    
    head = temp;
    
    return ;
}

void insert_pos(int data, int pos){
    int i;
    LINKITEM *temp, *ptr;
    ptr = head;
    for (i = 0; i < pos; i++) {
        if (ptr == NULL) {
            return;
        }
        ptr = ptr->next;
    }
    
    if(ptr->next == NULL) {
        insert_end(data);
    } else {
        temp = malloc(sizeof(LINKITEM));
        temp->data = data;
        temp->next = ptr;
        
        ptr->next = temp;
    }
}

// 移除第一个结点
void delete_beg(){
    if (head == NULL) {
        printf("List is Empty! \n");
        return ;
    }
    
    LINKITEM *temp = head;
    head = temp->next;
    
    free(temp);
}

void delete_end(){
    if (head == NULL) {
        return;
    }
    
    LINKITEM *ptr, *preptr;
    ptr = head->next;
    preptr = head;
    while(ptr ->next != NULL ) {
        ptr = ptr->next;
        preptr = preptr->next;
    }
    
    preptr->next = NULL;
    free(ptr);
    
    return;
}

int getLength(){
    int length = 0;
    LINKITEM *temp = head;
    while(temp  != NULL) {
        ++length;
        
        temp = temp->next;
    }
    
    return length;
}

// 链表反转
void reverse() {
    LINKITEM *pre = NULL;
    LINKITEM *current = head;
    LINKITEM *next = current->next;
    
    while(next != NULL) {
        current->next = pre;  // 把 current->next 转向
        pre = current;   // 把 pre 往后挪
        current = next; // 把 current 往后挪
        next = next->next; // 把 next 往后挪
    }
    
    current->next = pre; // 此时 current 位于最后一个node, 把current->next 转向
    head = current; // 是新 head
    
//    head
//    1 -> 2 -> 3 -> 4 -> NULL
    
//                           head
//    NULL <- 1 <- 2 <- 3 <- 4

}

void reverse2() {
    LINKITEM *prev, *current, *next;
    current = head;
    prev = NULL;
    
    while(current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    head = prev;
}

int main() {
    insertAtEnd(1);
    insertAtEnd(2);
    insertAtEnd(3);
    insertAtEnd(4);
    
    
///    insert_beg(1);
//    insertAtFirst(3);
//    insertAtFirst(4);
//    insertAtFirst(5);
  
    display();
//
//    reverse();
//
//    printf("反转后 \n");
//
//    display();
    
    reverse2();
    
    display();

    return EXIT_SUCCESS;
}
