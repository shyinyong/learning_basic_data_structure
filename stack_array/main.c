#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 10

int list[MAX_SIZE];
int top = -1;

void push(int data) {
    if (top == MAX_SIZE - 1 ) {
        printf("堆栈已满");
        return;
    }
    
    list[++top] = data;
}

void pop() {
    if (top == -1) {
        printf("堆栈为空");
        return;
    }
    
    --top;
}

bool isEmpty() {
    if (top == -1) {
        return true;
    } else  {
        return  false;
    }
}

int main() {
    push(1);
    push(2);
    push(3);
    pop();
    pop();
    
    
    printf("%d", isEmpty());

    return 0;
}
