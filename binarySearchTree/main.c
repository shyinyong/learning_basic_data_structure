#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct binarySearchTree {
    int data;
    struct binarySearchTree *left;
    struct binarySearchTree *right;
};


typedef struct binarySearchTree BST;

BST* newNode(int data) {
    BST *newNode = malloc(sizeof(BST));
    
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    
    return newNode;
}

void preOrder(BST *rootPtr){
    if (rootPtr != NULL) {
        preOrder(rootPtr->right);
        preOrder(rootPtr->left);
        printf("%d \n", rootPtr->data);
    }
}

void inOrder(BST *rootPtr){
    if (rootPtr != NULL) {
        inOrder(rootPtr->left);
        printf("%d \n", rootPtr->data);
        inOrder(rootPtr->right);
    }
}

void PostOrder(BST *rootPtr){
    if (rootPtr != NULL) {
        PostOrder(rootPtr->left);
        PostOrder(rootPtr->right);
        printf("%d \n", rootPtr->data);
    }
}

void levelOrder(BST *rootPtr) {
    if (rootPtr == NULL) {
        return ;
    }
    //
    /*
        A 100
   B 200        C 300
D 400    E 500    F 600     G 700
     
     出队             入队
     <=               <=
     ----------------
   <-  A (100),     B(200), C(300),     D(400), E(500)   F（600，G（700 ...
   |  ----------------
   V
     A 出队, 将B和C入队,
     B 出队， 将D和E入队，
     C 出队， 将F和G入队
     E 出队， E出队， F出队， G出队
     只要队列不为空， 我们就先取出一个结点， 然后访问它， 然后让孩子入队
     levelOrder(*root) {
         if (root == NULL) {
            return ;
         }
         queue Q;
         Q.push(root);
        while(!Q.empty()) {
            *current = Q.front();
            printf(current.data);
             if(current->left != NULL) {
                Q.push(current->left);
             }
     
            if(current->right != NULL) {
                Q.push(current->right);
            }
     
            // removing the element at front
            Q.pop();
        }
     }
     */

    
}

BST* insert(BST *rootPtr, int data) {
    if (rootPtr == NULL) {
        return newNode(data);
    }
    
    if (data < rootPtr->data) {
        rootPtr->left = insert(rootPtr->left, data);
    } else if (data > rootPtr->data) {
        rootPtr->right = insert(rootPtr->right, data);
    }
    
    return rootPtr;
}

int findMin(BST *rootPtr){
    if (rootPtr == NULL) {
        printf("空树");
        
        return 0;
    }
    
    BST *current = rootPtr;
    while(current->left != NULL) {
        current = current->left;
    }
    
    return current->data;
}

int findMax(BST *rootPtr){
    if (rootPtr == NULL) {
        printf("空树");
        
        return 0;
    }
    // 以递归的方式
//    else if (rootPtr->left == NULL) {
//        return rootPtr->data;
//    }
//    return findMin(rootPtr->left);
    
    BST *current = rootPtr;
    while(current->right != NULL) {
        current = current->right;
    }
    
    return current->data;
}

int main() {
    BST *rootPtr = NULL;
    
    rootPtr = insert(rootPtr, 50);
    insert(rootPtr, 30);
    insert(rootPtr, 20);
    insert(rootPtr, 40);
    insert(rootPtr, 70);
    insert(rootPtr, 60);
    insert(rootPtr, 80);
    
//    /inOrder(rootPtr);
    
    
    printf("%d \n", findMin(rootPtr));
    printf("%d \n", findMax(rootPtr));
    
    return 0;
}
