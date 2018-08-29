#include <stdio.h>
#include <stdlib.h>

//void selectionSort(int list[], int n) {
//    for (int i = 0; i < n-1; i++) {
//        int iMin = i;
//        for (int j = i+1; j<n; j++) {
//            if(list[j] < list[iMin]) {
//                iMin = j;
//            }
//        }
//
//        int temp = list[i];
//        list[i] = list[iMin];
//        list[iMin] = temp;
//    }
//}

void selectionSort(int list[], int list_count) {
    for (int i = 0; i < list_count - 2; i++) {
        int iMin = i;
        for(int j = i+1; j < list_count - 1; j++) {
            if (list[j] < list[iMin]) {
                iMin = j;
            }
        }
        int temp = list[i];
        list[i] = list[iMin];
        list[iMin] = temp;
    }
}

int main() {
    int list[] = {15,9,10,30,50,18,5,45};
    int list_count = sizeof(list) / sizeof(list[0]);
    
    selectionSort(list, list_count);
    
    for(int i = 0; i<list_count; i++) {
        printf("%d ", list[i]);
    }
    
    printf("\n 执行结束 \n");
    
    return 0;
}
