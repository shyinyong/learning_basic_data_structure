#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct binary_tree {
    int data;
    struct binary_tree *left;
    struct binary_tree *right;
};
typedef struct binary_tree BT;

BT *rootPtr = NULL;

struct queue {
    struct binary_tree *rootPtr;
    struct queue *next;
};
typedef struct queue QUEUE;

QUEUE *front, *rear = NULL;

void enQueue(BT *rootPtr) {
    QUEUE *newNote = malloc(sizeof(QUEUE));
    newNote->rootPtr = rootPtr;
    newNote->next = NULL;
    
    if (front == NULL && rear == NULL) {
        front = rear = newNote;
        return ;
    }
    
    rear->next = newNote;
    rear = newNote;
}

BT* deQueue() {
    QUEUE *newNote = front;
    BT *newNoteBt = newNote->rootPtr;
    
    if (front == NULL) {
        return NULL;
    }
    
    front = front->next ;
    
    free(newNote);
    
    return newNoteBt;
}

bool queueIsEmpty() {
    bool isEmpty = false;
    
    if(front == rear) {
        isEmpty = true;
    }
    
    return isEmpty;
}

int getLeafCount(BT *rootPtr) {
    if (rootPtr == NULL) {
        return 0;
    } else if (rootPtr->left == NULL && rootPtr->right == NULL) {
        return 1;
    } else {
        return getLeafCount(rootPtr->left) + getLeafCount(rootPtr->right);
    }
}

void preOrder(BT *rootPtr) {
    if (rootPtr  == NULL) {
        return ;
    }
    
    printf("%d \n ", rootPtr->data);
    preOrder(rootPtr->left);
    preOrder(rootPtr->right);
}

void inOrder(BT *rootPtr) {
    if (rootPtr == NULL) {
        return;
    }
    
    inOrder(rootPtr->left);
    printf("%d \n ", rootPtr->data);
    preOrder(rootPtr->right);
}

void postOrder(BT *rootPtr) {
    if (rootPtr == NULL) {
        return ;
    }
    
    postOrder(rootPtr->left);
    postOrder(rootPtr->right);
    printf("%d \n", rootPtr->data);
}

void levelOrder(BT *rootPtr){
    if (rootPtr == NULL) {
        return ;
    }
   
    enQueue(rootPtr);
    BT* temp = deQueue();
    printf("%d \n", temp->data);
    
    return;

//    while(front != NULL) {
//        if (rootPtr->left != NULL) {
//            enQueue(rootPtr->left);
//        }
//        if (rootPtr->right != NULL) {
//            enQueue(rootPtr->right);
//        }
//
//        temp = deQueue();
//        printf("%d \n", temp->data);
//    }
}

BT* newTree(int data){
    BT *newTree = malloc(sizeof(BT));
    newTree->data = data;
    newTree->left = newTree->right = NULL;
    
    return newTree;
}

int main() {
    printf("aa \a \n");
    return 0;
    rootPtr = newTree(1);
//    rootPtr->left = newTree(2);
//    rootPtr->right = newTree(3);
//    rootPtr->left->left = newTree(4);
//    rootPtr->left->right = newTree(5);
//    rootPtr->right->left = newTree(6);
//    rootPtr->right->right = newTree(7);
    
    levelOrder(rootPtr);
   
    printf("结束 \n");
    
    return 0;
}
