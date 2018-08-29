#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b ;
    *b = temp;
}

void bubble_sort2(int list[], int list_count) {
    int i,j;
    bool flag;
    for(i = 0; i < list_count - 1; i++) {
        flag = false;
        for (j = 0; j < list_count - i - 1; j++) {
            if (list[j] > list[j+1]) {
                swap(&list[j], &list[j+1]);
                flag = true;
            }
        }
        
        if (flag == false) {
            break;
        }
    }
}

void bubble_sort(int list[], int list_count)
{
    int last_unsorted = list_count - 1;
    bool is_sorted = false;
    while (!is_sorted)
    {
        is_sorted = true;
        for (int i = 0; i < last_unsorted; i++)
        {
            if (list[i] > list[i + 1])
            {
                swap(&list[i], &list[i + 1]);
                is_sorted = false;
            }
        }
        last_unsorted--;
    }
}

int main() {
    int list[] = {15,9,10,30,50,18,5,45};
    int list_count = sizeof(list) / sizeof(list[0]);
    
    bubble_sort(list, list_count);
    
    for(int i = 0; i<list_count; i++){
        printf("%d ", list[i]);
    }
    
    printf("\n 执行结束 \n");
    
    return 0;
}
