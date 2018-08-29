#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int linearSearch(int list[], int data) {
    int list_count = sizeof(list) / sizeof(list[0]));
    index = 0;
    while(index < list_count and list[index] < data) {
        index++;
    }
    if (index >= list_count || list[index] != data) {
        return -1;
    }
    
    return index;
}

int main() {
    
    return 0;
}
