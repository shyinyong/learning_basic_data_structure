//
//  main.c
//  insertionSort
//
//  Created by Apple on 2018/8/8.
//  Copyright © 2018年 Apple. All rights reserved.
//

// 插入排序

#include <stdio.h>

void insertSort(int list[], int list_count) {
    int i, j, temp;

    for (i = 1; i< list_count; i++) {
        temp = list[i];
        j = i - 1;

        //  i = 1, temp = 20, j = 0, list[j] = 15
        //  i = 2, temp = 10, j = 1, list[j] = 20
        while((temp < list[j] && (j >= 0))) {
            list[j+1] = list[j];
            j = j-1;
        }

        list[j+1] = temp;

        // list[1] = 20
    }
}

void insertSort2(int list[], int list_count) {
    for(int i = 1; i<list_count; i++) {
        int value = list[i];
        int hole = i ;
        while(hole > 0 && list[hole - 1] > value) {
            list[hole] = list[hole-1];
            hole = hole - 1;
        }
        list[hole] = value;
    }
}

void insertSort3(int list[], int list_count) {
    /*
     初始化V
     ------------------------------------
     15 | 9 | 10 | 30 | 50 | 18 | 5 | 45
     ------------------------------------
     0   1    2    3    4    5    6   7
     第一步
     ------------------------------------
     9 | 15 | 10 | 30 | 50 | 18 | 5 | 45
     ------------------------------------
     0   1    2    3    4    5    6   7
     preI  i
     第二步
     ------------------------------------
     9 | 10 | 15 | 30 | 50 | 18 | 5 | 45
     ------------------------------------
     0   1    2    3    4    5    6   7
        preI  i
     第三步
     ------------------------------------
     9 | 10 | 15 | 30 | 50 | 18 | 5 | 45
     ------------------------------------
     0   1    2    3    4    5    6   7
             preI  i
     第四步
     ------------------------------------
     9 | 10 | 15 | 30 | 50 | 18 | 5 | 45
     ------------------------------------
     0   1    2    3    4    5    6   7
                  preI  i
     第五步
     ------------------------------------
     9 | 10 | 15 | 18 | 30 | 50 | 5 | 45
     ------------------------------------
     0   1    2    3    4    5    6   7
     preI                    i
     第六步
     ------------------------------------
     5 | 9 | 10 | 15 | 18 | 30 | 50 | 45
     ------------------------------------
     0   1    2    3    4    5    6   7
     preI                         i
     第七步
     ------------------------------------
     5 | 9 | 10 | 15 | 18 | 30 | 45 | 50
     ------------------------------------
     0   1    2    3    4    5    6   7
                            preI      i
     
     */
    for (int i = 1; i < list_count; i++) {
        int currentValue = list[i]; // 45
        int preIndex = i - 1; // 6
        while((currentValue < list[preIndex] && (preIndex >= 0))) {
            list[preIndex+1] = list[preIndex];
            preIndex = preIndex - 1;

            /*
             list[1] = 15; preIndex = -1
             */
        }
        list[preIndex+1] = currentValue;
    }
}

void insertionSort4 (int list[], int list_count) {
    for(int i = 1; i < list_count; i++) {
        int currentValue = list[i];
        int preIndex = i - 1;
        while(currentValue < list[preIndex] && preIndex >=0) {
            list[preIndex+1] = list[preIndex];
            --preIndex;
        }
        list[preIndex+1] = currentValue;
    }
}

int main() {
    int list[] = {15,9,10,30,50,18,5,45};
    int list_count;
    list_count = sizeof(list) / sizeof(list[0]);
    
    insertionSort4(list, list_count);
    
    for(int i = 0; i<list_count; i++){
        printf("%d ", list[i]);
    }
    
    printf("\n 执行结束 \n");
    
    return 0;
}


