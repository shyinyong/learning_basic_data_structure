#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int binarySearch() {
    int list[20] = {1,4};
    int size = 2;
    int first = 0;
    int last = size - 1;
    int middle = (first + last) / 2;
    
    int value = 5;
    while(first <= last) {
        if (list[middle] < value) {
            first = middle + 1;
        } else if(list[middle] == value) {
            printf("找到！ index %d \n", middle);
            break;
        } else {
            last = middle - 1;
        }
        
        middle = (first + last) / 2;
    }
    
    if (first > last) {
        printf("Not found \n");
    }
    
    return 0;
}

int binarySearch2() {
    int list[5] = {1,4,6,10, 62};
    int list_count = sizeof(list)/sizeof(list[0]);//Method
    
    int low, high, mid;
    int key = 62;
    
    low = 0;
    high = list_count - 1;
    while (low <= high) {
        mid =(low + high) / 2; // 折半
        if (key < list[mid]) {
            high = mid - 1; // 最高下标调整到中位下标前一位
        } else if (key > list[mid]) {
            low = mid + 1; // 最低下标调整到中位下标后一位
        } else {
            return  list[mid]; // 否则就是相等， 说明mid即为查找的位置
        }
    }
    
    return 0;
}

bool binarySearch3() {
    int list[] = {1,4,6,10, 62};
    int key = 623;

    int left = 0;
    int right = sizeof(list)/sizeof(list[0]);
    while(left <= right) {
        if (left > right) {
            return  false;
        }

        int mid = (left + right) / 2;
        if (list[mid] == key) {
            return true;
        } else if ( key < list[mid]){
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return false;
}

int main() {
    bool result =  binarySearch3();
    printf("%d \n", result);
    
    return 0;
}
